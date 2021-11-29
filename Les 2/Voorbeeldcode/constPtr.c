/* Demonstrates constant pointer errors */

#include <stdio.h>

/* Declare and initialize an int variable */
int a = 2;
int b = 4;
int y = 0;



int main (void )
{
	/* Declare a const pointer to int */
	int *const ptr = &a;
	a = 22;
	y = *ptr;
	printf("y: %d (should be 22)\n", y);
 
	*ptr = 40;

//	ptr=&b;  // error - can't change address of ptr
	
	/* declare a pointer to a const object: object is read only */
	const int *ptr2 = &a;
//	*ptr2 =3;  // error - can't change value of *ptr2

	y = *ptr2;
	printf("y: %d (should be 40)\n", y); 
	ptr2 = &b;
	y = *ptr2;
	printf("y: %d (should be 4)\n", y); 

	return 0;



}


