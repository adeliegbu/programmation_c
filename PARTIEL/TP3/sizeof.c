#include <stdio.h>

int main() {
    int i = 1;  // Déclaration d'un entier
    int* pi = &i;  // Déclaration d'un pointeur vers un entier
    int** ppi = &pi;  // Déclaration d'un pointeur vers un pointeur vers un entier
    printf("La taille de int est : %lu\n", sizeof(i));
    printf("La taille de int* est : %lu\n", sizeof(pi));
    printf("La taille de int** est : %lu\n", sizeof(ppi));
    
    char c = 'a';  // Déclaration d'un caractère
    char* pc = &c;  // Déclaration d'un pointeur vers un caractère
    char** ppc = &pc;  // Déclaration d'un pointeur vers un pointeur vers un caractère
    char*** pppc = &ppc;  // Déclaration d'un pointeur vers un pointeur vers un pointeur vers un caractère
    printf("La taille de char est : %lu\n", sizeof(c));
    printf("La taille de char* est : %lu\n", sizeof(pc));
    printf("La taille de char** est : %lu\n", sizeof(ppc));
    printf("La taille de char*** est : %lu\n", sizeof(pppc));
    
    float f = 1.2;  // Déclaration d'un float
    float* pf = &f;  // Déclaration d'un pointeur vers un float
    float** ppf = &pf;  // Déclaration d'un pointeur vers un pointeur vers un float
    float*** pppf = &ppf;  // Déclaration d'un pointeur vers un pointeur vers un pointeur vers un float
    printf("La taille de float est : %lu\n", sizeof(f));
    printf("La taille de float* est : %lu\n", sizeof(pf));
    printf("La taille de float** est : %lu\n", sizeof(ppf));
    printf("La taille de float*** est : %lu\n", sizeof(pppf));

    return 0;
}