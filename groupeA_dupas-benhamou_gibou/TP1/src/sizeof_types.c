#include <stdio.h>

int main() {
    // On affiche la taille en octet de chaque type de donnée
    printf("Taille en octet de char: %lu\n", sizeof(char));
    printf("Taille en octet de unsigned char: %lu\n", sizeof(unsigned char));
    printf("Taille en octet de short: %lu\n", sizeof(short));
    printf("Taille en octet de unsigned short: %lu\n", sizeof(unsigned short));
    printf("Taille en octet de int: %lu\n", sizeof(int));
    printf("Taille en octet de unsigned int: %lu\n", sizeof(unsigned int));
    printf("Taille en octet de long int: %lu\n", sizeof(long int));
    printf("Taille en octet de unsigned long int: %lu\n", sizeof(unsigned long int));
    printf("Taille en octet de long long int: %lu\n", sizeof(long long int));
    printf("Taille en octet de unsigned long long int: %lu\n", sizeof(unsigned long long int));
    printf("Taille en octet de float: %lu\n", sizeof(float));
    printf("Taille en octet de double: %lu\n", sizeof(double));
    printf("Taille en octet de long double: %lu\n", sizeof(long double));
    return 0;
}