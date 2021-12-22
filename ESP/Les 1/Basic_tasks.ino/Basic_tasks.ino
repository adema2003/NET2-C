// MIT License (see file LICENSE)
// Change the following if you want to use
// different GPIO pins for the three LEDs
#define LED1 12 // GPIO 12
#define LED2 13 // etc.
#define LED3 15

int led = 12;
int led1 = 11;
int cnt = 1;
int del;

struct s_led {
byte gpio; // LED GPIO number
byte state; // LED state
unsigned napms; // Delay to use (ms)
TaskHandle_t taskh; // Task handle
};

static s_led leds[3] = {
{ LED1, 0, 500, 0 },
{ LED2, 0, 200, 0 },
{ LED3, 0, 750, 0 }
};
static void led_task_func(void *argp) {
s_led *ledp = (s_led*)argp;
unsigned stack_hwm = 0, temp;
delay(1000);
for (;;) {
digitalWrite(ledp->gpio,ledp->state ^= 1);
temp = uxTaskGetStackHighWaterMark(nullptr);
if ( !stack_hwm || temp < stack_hwm ) {
stack_hwm = temp;
printf("Task for gpio %d has stack hwm %u\n",
ledp->gpio,stack_hwm);
}
delay(ledp->napms);
}
}
void setup() {
Serial.begin (9600);
pinMode (led,OUTPUT);
pinMode (led1,OUTPUT);
int app_cpu = 0; // CPU number
delay(500); // Pause for serial setup
app_cpu = xPortGetCoreID();
printf("app_cpu is %d (%s core)\n",
app_cpu,
app_cpu > 0 ? "Dual" : "Single");
printf("LEDs on gpios: ");for ( auto& led : leds ) {
pinMode(led.gpio,OUTPUT);
digitalWrite(led.gpio,LOW);
xTaskCreatePinnedToCore(
led_task_func,
"led_task",
2048,
&led,
1,
&led.taskh,
app_cpu
);
printf("%d ",led.gpio);
}
//putchar(‘\n’);
}
void loop() {
delay(1000);
{ while (cnt <=11) cnt++;}{

if (cnt <= 3 and cnt > 0) {del = 1500;}

if (cnt > 3 and cnt <= 6) {del = 1000;}
if (cnt > 6 and cnt <= 9) { del = 500;}
if (cnt > 9 and cnt <= 12) {del = 250;}
if (cnt > 12 and cnt <= 15) { del = 125;}

if (cnt > 15 and cnt <= 18) {del = 1000;}
if (cnt > 18 and cnt <= 21) { del = 500;}
if (cnt > 21 and cnt <= 24) {del = 250;}
if (cnt > 24 and cnt <= 27) { del = 125;}
if (cnt == 27) {cnt = 1;}
}
}
