#include <stdio.h>
#include "opdracht1.h"

int main( void ) {
    int keuze;
    printf("Er zijn de volgende opties: \n");
    printf("1: Print een vrolijke smiley \n");
    printf("2: Voer de code van weekopdracht 1 uit\n");
    printf("3: Print eenn zielige smiley\n");
    printf("Voer je keuze in: ");
    scanf("%d", &keuze);  
    printf("Deze keuze heb je gemaakt, %d \n", keuze);

    if(keuze < 0) {
        return 0;
    } else {
        switch(keuze) {
            case 1:
                printf(":-)\n");
                break;
            case 2:
                function();
                break;
            case 3:
                printf(":-(\n");
                break;
            default:
                printf("Deze input is incorrect. Vul een getal in tussen 1 en 3");
        }
    }
    return 0;

}