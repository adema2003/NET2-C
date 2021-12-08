#include <stdio.h>

typedef struct opleiding {
    char naam[20];
    int instroomjaar;
} opleiding;
typedef struct gegevens {
    char naam[20];
    int leeftijd;
    opleiding opl;
} gegevens;

int main() {
    gegevens g1;
    printf("Vul je naam in: ");
    scanf("%s", &g1.naam);
    printf("\n Vul je leeftijd in: ");
    scanf("%d", &g1.leeftijd);
    printf("Vul de naam van je opleiding in: ");
    scanf("%s", &g1.opl.naam);
    printf("\n Vul je instroomjaar in: ");
    scanf("%d", &g1.opl.instroomjaar);
    printf("\n Dit zijn je gegevens: \n");
    printf("Naam: %s\nLeeftijd: %d\nNaam van je opleiding: %s\nInstroomjaar: %d\n",g1.naam,g1.leeftijd,g1.opl.naam,g1.opl.instroomjaar);  
    return 0;
}