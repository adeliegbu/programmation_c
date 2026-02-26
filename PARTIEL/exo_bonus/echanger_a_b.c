#include <stdio.h>


void echanger(float *a, float *b) {
    float c = *a;
    *a = *b;
    *b = c;
}

int main() {
    float a = 1.25;
    float b = 5.21;
    printf("a = %f, b = %f \n", a, b);
    echanger(&a,&b);
    printf("a = %f, b = %f \n", a, b);
    return 0;
}