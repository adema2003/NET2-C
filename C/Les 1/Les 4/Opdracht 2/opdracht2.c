#include <stdio.h>
#include <stdlib.h>
int main( void )
{

    struct persoon
    {
        char naam[25];
        int leeftijd;
    };

    struct persoon *pointer = (struct persoon*)malloc(sizeof(struct persoon));
    int i = 1;
    int c = 1;
    struct persoon *npointer;

    while (1)
    {
        npointer = pointer;
        npointer += (c-1);

        printf("Vul uw naam in: ");
        scanf("%s", npointer->naam);

        
        printf("Vul uw leeftijd in: ");
        scanf("%d", &npointer->leeftijd);


        printf("Vul 1 in als u uw gegevens wilt veranderen:(1) \n");
        printf("Vul een willekeurig getal in als u het programma wilt stoppen: ");
        scanf("%d", &i);
        if (i != 1)
        {
            break;
        }
        printf("\n");

        struct persoon *np = pointer;
        for (int i = 0; i < c; i++)
        {
            printf("%s\n", np->naam);
            printf("%d\n", np->leeftijd);
            np++;
        }

        c++;

        pointer = (struct persoon*)realloc(pointer, c * sizeof(struct persoon));
        if (pointer == NULL)
        {
            perror("Er is iets fout gegaan, probeer het opnieuw");
            exit(-1);
        }
    }
    free(pointer);
    return 0;
}
