#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int tableau_int[10];  // Déclaration des tableaux d'entiers et de floats
    float tableau_float[10];

    srand(time(NULL));  // Initialisation de la graine pour la génération de nombres aléatoires

    for (int i = 0; i < 10; i++) {  // Remplissage des tableaux avec des valeurs aléatoires
        tableau_int[i] = rand() % 100;
        tableau_float[i] = (float)(rand() % 100)/10;
    }

    printf("Tableau d'entiers (avant la multiplication par 3):\n");  // Affichage du tableau d'entiers avant modification
    for (int i = 0; i < 10; i++) {
        printf("%d ", *(tableau_int + i));
    }
    printf("\n");

    printf("Tableau de floats (avant la multiplication par 3):\n");  // Affichage du tableau de floats avant modification
    for (int i = 0; i < 10; i++) {
        printf("%.1f ", *(tableau_float + i));
    }
    printf("\n");


    for (int i = 0; i < 10; i += 2) {  // Multiplication par 3 des éléments d'indice pair
        *(tableau_int + i) *= 3;
        *(tableau_float + i) *= 3;
    }
    
    printf("Tableau d'entiers (après la multiplication par 3):\n");  // Affichage du tableau d'entiers après modification
    for (int i = 0; i < 10; i++) {
        printf("%d ", *(tableau_int + i));
    }
    printf("\n");

    printf("Tableau de floats (après la multiplication par 3):\n");  // Affichage du tableau de floats après modification
    for (int i = 0; i < 10; i++) {
        printf("%.1f ", *(tableau_float + i));
    }
    printf("\n");

    return 0;
}