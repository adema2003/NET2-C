/* Demonstrates using pointer arithmetic to access */
/* array elements with pointer notation. */

#include <stdio.h>
#define MAX 5

/* Declare and initialize an integer array. */
int i_array[MAX] = {0,1,2,3,4};

/* Declare a pointer to int and an int variable. */
int *i_ptr, count;

/* Declare and initialize a float array. */
float f_array[MAX] = {.0, .1, .2, .3, .4};

/* Declare a pointer to float. */
float *f_ptr;

int main (void )
{
	/* Initilaize the pointers, */
	i_ptr = i_array;
	f_ptr = f_array;

	/* Print the array elements using array indices. */
	printf("Print the array elements using array indices.\n"); 
	for (count = 0; count < MAX; count++) {
		printf("Element %d:\t%d\t%f\n", count, 
					i_array[count],  f_array[count]);
	}

	/* Print the array elements using pointer arithmatic. */
	printf("\nPrint the array elements using pointer arithmetic.\n"); 
	for (count = 0; count < MAX; count++) {
		printf("Element %d:\t%d\t%f\n", count, *i_ptr++, *f_ptr++);
	}	

	return 0;
}


