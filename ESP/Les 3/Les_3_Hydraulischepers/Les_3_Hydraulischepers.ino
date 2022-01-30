#include <WiFi.h>
#include "secret.h"
#include "time.h"
// add header file for SNTP client
#include "esp_sntp.h"

#define GPIO_LED 23
#define GPIO_BUTTONL 15
#define GPIO_BUTTONR 16

static QueueHandle_t xqueue;
static QueueHandle_t queue;
const int reset_press = -998;

//
// contants for SNTP client
const char* ntpServer = "nl.pool.ntp.org";
const long  gmtOffset_sec = 3600;
const int   daylightOffset_sec = 3600;
//

void WiFi_connect() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    printf(".");
  }
  printf(" CONNECTED\r\n");
}

char* printLocalTime()
{
//https://docs.espressif.com/projects/esp-idf/en/latest/esp32/apireference/system/system_time.html
time_t now;
char *time_buf = (char*)malloc(64 * sizeof(char));
struct tm timeinfo;
time(&now);
localtime_r(&now, &timeinfo);
strftime(time_buf, (64 * sizeof(char)), "%c", &timeinfo);
//ESP_LOGI(TAG, "\r\nThe current date/time is: %s\r\n", time_buf);
return time_buf;
}

static void time(void * para) {
  // init time protocol sync
  sntp_setoperatingmode(SNTP_OPMODE_POLL);
  sntp_setservername(0, "pool.ntp.org");
  sntp_init();
  setenv("TZ", "CET-1CEST-2,M3.5.0/02:00:00,M10.5.0/03:00:00", 1);
  tzset();
  vTaskDelete(NULL);
}

static void debounce_task(void *argp) {
unsigned button_gpio = *(unsigned*)argp;
uint32_t level, state = 0;
uint32_t mask = 0x7FFFFFFF;
int event, last = -999;

for (;;) {
level = !digitalRead(button_gpio);
state = (state << 1) | level;
if ( (state & mask) == mask )
event = button_gpio; 
else
event = -button_gpio; 

if ( event != last ) {
if ( xQueueSendToBack(queue,&event,0) == pdPASS ) {
last = event;
} else if ( event < 0 ) {
do {
xQueueReset(queue); 
} while ( xQueueSendToBack(queue,&reset_press,0) != pdPASS );
last = event;
}
}
taskYIELD();
}
}

static void press_task(void *argp) {
static const uint32_t enable = (1 << GPIO_BUTTONL)
| (1 << GPIO_BUTTONR);
BaseType_t s;
int event;
uint32_t state = 0;

// Make sure press is OFF
digitalWrite(GPIO_LED,LOW);

for (;;) {
s = xQueueReceive(
queue,
&event,
portMAX_DELAY
);
assert(s == pdPASS);



if ( event == reset_press ) {
digitalWrite(GPIO_LED,LOW);
state = 0; printf("RESET!!\n");
continue;
}

if ( event >= 0 ) {
state |= 1 << event;
} else {
state &= ~(1 << -event);
}

if ( state == enable ) {
digitalWrite(GPIO_LED,HIGH);

char trash[64];
printf("Button pressed\r\n");

if( xQueueSendToBack( xqueue, printLocalTime(), 0) != pdPASS)
{
  xQueueReceive(xqueue, &trash, 0);
  printf("Thrown out data: %s\r\n", trash);
  xQueueSendToBack( xqueue, printLocalTime(), 0);
}

} else {
digitalWrite(GPIO_LED,LOW);
}
}
}

void setup() {
int app_cpu = xPortGetCoreID();
static int left = GPIO_BUTTONL;
static int right = GPIO_BUTTONR;
TaskHandle_t h;
BaseType_t rc;
WiFi_connect();


xqueue = xQueueCreate( 5, 64 * sizeof( char ) );





delay(2000);
queue = xQueueCreate(2,sizeof(int));
assert(queue);

pinMode(GPIO_LED,OUTPUT);
pinMode(GPIO_BUTTONL,INPUT_PULLUP);
pinMode(GPIO_BUTTONR,INPUT_PULLUP);

time_set = xTaskCreatePinnedToCore(
  time,
  "Time set",
   2048,
   &t,
   3,
   &t,
   app_cpu);
  assert(time_set == pdPASS);
  assert(t);

rc = xTaskCreatePinnedToCore(
button_press,


"debounceL",
2048,
&left,
1,
&h,
app_cpu
);
assert(rc == pdPASS);
assert(h);

rc = xTaskCreatePinnedToCore(
button_press,
"debounceR",
2048,
&right, 
1,
&h,
app_cpu 
);
assert(rc == pdPASS);
assert(h);

rc = xTaskCreatePinnedToCore(
press_task,
"led",
2048,
nullptr,
1,
&h,
app_cpu
);
assert(rc == pdPASS);
assert(h);
}

// Not used:
void loop() {
  vTaskDelete(nullptr);
}