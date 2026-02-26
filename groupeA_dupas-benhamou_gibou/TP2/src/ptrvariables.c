#include <stdio.h>

int main() {
    // On déclare et initialise une variable de chaque type de donnée, ainsi qu'un pointeur vers chaque variable
    char my_char = 'a';
    char *my_char_addr = &my_char;

    short my_short = -12;
    short *my_short_addr = &my_short;

    int my_int = 12;
    int *my_int_addr = &my_int;

    long int my_long = -1234567L;
    long int *my_long_addr = &my_long;

    long long int my_llong = 1234567LL;
    long long int *my_llong_addr = &my_llong;

    float my_float = 1.23;
    float *my_float_addr = &my_float;

    double my_double = 1.23E-12;
    double *my_double_addr = &my_double;

    long double my_ldouble = 1.23E-12;
    long double *my_ldouble_addr = &my_ldouble;


    // On affiche la valeur et l'adresse de chaque variable avec le format approprié
    printf("Avant la manipulation :\n");
    printf("char: valeur = %c, adresse = %p\n", my_char, (void*)my_char_addr);
    printf("short: valeur = %hd, adresse = %p\n", my_short, (void*)my_short_addr);
    printf("int: valeur = %d, adresse = %p\n", my_int, (void*)my_int_addr);
    printf("long: valeur = %ld, adresse = %p\n", my_long, (void*)my_long_addr);
    printf("long long: valeur = %lld, adresse = %p\n", my_llong, (void*)my_llong_addr);
    printf("float: valeur = %f, adresse = %p\n", my_float, (void*)my_float_addr);
    printf("double: valeur = %f, adresse = %p\n", my_double, (void*)my_double_addr);
    printf("long double: valeur = %Lf, adresse = %p\n", my_ldouble, (void*)my_ldouble_addr);

    // On manipule les valeurs des variables via leurs pointeurs
    *my_char_addr += 1;
    *my_short_addr -= 1;
    *my_int_addr *= 2;
    *my_long_addr /= 3;
    *my_llong_addr += 1000;
    *my_float_addr *= 3.0;
    *my_double_addr /= 2.0;
    *my_ldouble_addr += 0.1;


    // On affiche à nouveau la valeur et l'adresse de chaque variable pour vérifier que les modifications ont été prises en compte
    printf("\nAprès la manipulation :\n");
    printf("char: valeur = %c, adresse = %p\n", my_char, (void*)my_char_addr);
    printf("short: valeur = %hd, adresse = %p\n", my_short, (void*)my_short_addr);
    printf("int: valeur = %d, adresse = %p\n", my_int, (void*)my_int_addr);
    printf("long: valeur = %ld, adresse = %p\n", my_long, (void*)my_long_addr);
    printf("long long: valeur = %lld, adresse = %p\n", my_llong, (void*)my_llong_addr);
    printf("float: valeur = %f, adresse = %p\n", my_float, (void*)my_float_addr);
    printf("double: valeur = %f, adresse = %p\n", my_double, (void*)my_double_addr);
    printf("long double: valeur = %Lf, adresse = %p\n", my_ldouble, (void*)my_ldouble_addr);

    return 0;    
}