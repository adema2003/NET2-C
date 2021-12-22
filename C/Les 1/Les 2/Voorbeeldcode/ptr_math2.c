/* Demonstrates using pointer arithmetic to access */
/* array elements with pointer notation. */

#include <stdio.h>
#define MAX 5

/* Declare and initialize an integer array. */
int i_array[MAX] = {0,1,2,3,4};

/* Declare a pointer to int and an int variable. */
int *i_ptr1, *i_ptr2, count;

int main (void )
{
	/* Initialize the pointers, */
	i_ptr1 = i_array;
	i_ptr2 = &(i_array[0]);

	/* Print how far elements in the array are apart from the first element. */
	for (count = 0; count < MAX; count++) {
		printf("Element %d:\tDistance from 1st element:\t%d\n", count, i_ptr2 - i_ptr1);
		i_ptr2++;
	}	

	return 0;
}


