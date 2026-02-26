#include <stdio.h>

int main() {

    // On déclare et initialise une variable de chaque type de donnée
    char my_char = 'a';
    unsigned char my_uchar = 123;
    short my_short = -12;
    unsigned short my_ushort = 12345;
    int my_int = 12;
    unsigned int my_uint = 1234;
    long int my_long = -1234567L;
    unsigned long int my_ulong = 123456UL;
    long long int my_llong = 1234567LL;
    unsigned long long int my_ullong = 1234567ULL;
    float my_float = 1.23;
    double my_double = 1.23E-12;
    long double my_ldouble = 1.23E-12;


    // On affiche la valeur de chaque variable avec le format approprié
    printf("char = %c\n", my_char);
    printf("unsigned char = %hhu\n", my_uchar);
    printf("short = %hd\n", my_short);
    printf("unsigned short = %hu\n", my_ushort);
    printf("int = %d\n", my_int);
    printf("unsigned int = %u\n", my_uint);
    printf("long int = %ld\n", my_long);
    printf("unsigned long int = %lu\n", my_ulong);
    printf("long long int = %lld\n", my_llong);
    printf("unsigned long long int = %llu\n", my_ullong);
    printf("float = %f\n", my_float);
    printf("double = %g\n", my_double);
    printf("long double = %Lg\n", my_ldouble);

    return 0;
}