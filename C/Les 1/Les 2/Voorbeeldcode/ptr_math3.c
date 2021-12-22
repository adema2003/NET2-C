/* Demonstrates pointer arithmetic */


#include <stdio.h>


int main (void )
{
        printf("Short stored in %d bytes!\n", sizeof(short));       
        short var_short = 2;
        short* ptr_to_short = &var_short;
        printf("pointer points to short at address: %d\n", ptr_to_short);        
        ptr_to_short++; 	// address increased by type 				// of short (usually 2 bytes)
        printf("Pointer value is increased with one.\n");
        printf("pointer points to short at address: %d\n", ptr_to_short);
      
        printf("\n\n");
        printf("Double stored in %d bytes!\n", sizeof(double));        
        double var_double = 2.0;
        double * ptr_to_double = &var_double;
        printf("pointer points to double at address: %d\n", ptr_to_double);        
        ptr_to_double++; 	// address increased by type 				// of double (usually 8 bytes)
        printf("Pointer value is increased with one.\n");
        printf("pointer points to double at address: %d\n", ptr_to_double);
        
        
        return 0;
}

