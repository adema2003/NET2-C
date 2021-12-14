#include <stdio.h>
#include <string>

int main() {
    char tekst[100];
    char tekstnieuw;
    int length = 0;

    FILE *fptr1, *fptr2 ;
		fptr1 = fopen ( "test.txt", "r") ;
		if (fptr1 == NULL) 	{
			printf ("File 'mydata' did not open.\n") ;
		}
        fptr2 = fopen ( "test-nieuw.txt", "w") ;
		if (fptr2 == NULL) 	{
			printf ("File 'mydata' did not open.\n") ;
		}

    while (tekstnieuw != EOF)
    {
        length++;
        tekstnieuw = fgetc(fptr1);
        fputc(tekstnieuw+1, fptr2);
    }
    printf("Lengte is : %d\n", length);

    fclose(fptr1);
    fclose(fptr2);

    return 0;
}