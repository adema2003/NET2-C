#include <stdio.h>
int main() {
    char string[100];
    int length = 0;

    printf("Vul een zin in: ");
    fgets(string, 100, stdin);
    printf("Je hebt deze zin ingevuld: %s", string);

    while (string[length] != '\0') {
        length++;
    }

    printf("Je zin is zolang: %d\n", length);

    return 0;
}