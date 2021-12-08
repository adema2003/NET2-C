#include <stdio.h>
int main( void ) {
    void maxArrays(float *ar1, float *ar2, float *array3);

    float array1[] = {0.7, 3.3, 0.5, 10.3};
    float array2[] = {4.1, 1.5, 0.3, 2.3};
    float array3[1];

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

    maxArrays(array1, array2, array3);
    printf("Dit is array 3: %.1f \n", array3);
    return 0;
}


void maxArrays(float *ar1, float *ar2, float *array3) {
     int n;
  for (int i = 1; i < n; ++i) {
    if (ar1[0] < ar1[i]) {
      ar1[0] = ar1[i];
    }
  }
    *array3 = ar1[0];
}