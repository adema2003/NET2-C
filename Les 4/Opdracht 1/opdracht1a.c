#include <stdio.h>
int main() {
    char tekst, tekstnieuw;
    int length = 0;
    int i;
    char *ascii;
    int tekstascii[5];

    FILE *fptr1, *fptr2 ;
		fptr1 = fopen ( "test.txt", "r") ;
		if (fptr1 == NULL) 	{
			printf ("File 'mydata' did not open.\n") ;
		}
        fptr2 = fopen ( "test-nieuw.txt", "w") ;
		if (fptr2 == NULL) 	{
			printf ("File 'mydata' did not open.\n") ;
		}

   tekstnieuw = fgetc(fptr1);
    while (tekstnieuw != EOF)
    {
        length++;
        fputc(tekstnieuw, fptr2);
        tekstnieuw = fgetc(fptr1);
    }
    *ascii = tekstnieuw;
    for (char *i = ascii; *i; ++i) {
        tekstascii[0] = tekstascii[0] + *i;
    }
    printf("%d", tekstacii[0])
    printf("\nDe tekst bestaat uit %d", length);
    printf(" karakters\n");
    fclose(fptr1);

    return 0;
}