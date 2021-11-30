#include <stdio.h>

void berekenOmtrek(int diameter, float *omtrek);

int main( void ) {
    float omtrek; 
    int diameter;
    printf("Wat is de diameter van de cirkel? ");
    scanf("%d", &diameter);  
    printf("Dit is de diameter, %d \n", diameter);

    berekenOmtrek(diameter, &omtrek);

    printf("Dit is de omtrek, %f \n", omtrek);

    return 0;
}

void berekenOmtrek(int diameter, float *omtrek)
{
    *omtrek = diameter * 3.14;
}