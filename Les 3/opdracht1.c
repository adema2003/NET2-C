#include <stdio.h>
int main( void ) {
    void maxArrays(float *array1, float *array2);

    float array1[] = {0.7, 3.3, 0.5, 10.3};
    float array2[] = {4.1, 1.5, 0.3, 2.3};
    float array3[] = {};

    printf("Array 1 bevat:\n");
    for(int i=0; i<5; i++) {
        printf("%.1f", array1[i]);
        printf("\n");
    }
    printf("Array 2 bevat:\n");
    for(int i=0; i<5; i++) {
        printf("%.1f", array2[i]);
        printf("\n");
    }
    
    // ptra1 = &array1;
    // ptra2 = &array2;

    maxArrays(&array1, &array2);
    return 0;
}


void maxArrays(float *array1, float *array2) {
   
   printf("test");
}