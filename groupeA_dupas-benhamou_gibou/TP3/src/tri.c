#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void tri(int tableau[], int size)  {  // Fonction de tri à bulle
    int stocke = tableau[0];  // Variable temporaire pour l'échange des valeurs
    for (int i = 0; i < size - 1; i++) {  // Tri à bulle
        for (int j = 0; j < size - 1 - i; j++)
            if (tableau[j] > tableau[j+1]) {  // Si l'élément courant est plus grand que le suivant, on les échange
                stocke = tableau[j];
                tableau[j] = tableau[j+1];
                tableau[j+1] = stocke; 
            }
    }
}

int main() {
    int size = 100;
    int tableau[size];  // Déclaration d'un tableau de 100 entiers

    srand(time(NULL));  // Initialisation de la graine pour la génération de nombres aléatoires

    printf("Tableau non trié : \n");
    for (int i = 0; i < size; i++) {
        tableau[i] = (rand() % 1000) + 1;  // Remplissage du tableau avec des valeurs aléatoires entre 1 et 1000
        printf("%d ", tableau[i]);
    }
    printf("\n");


    printf("Tableau trié : \n");
    tri(tableau, size);  // Appel de la fonction de tri
    for (int i = 0; i < size; i++) {
        printf("%d ", tableau[i]);  // Affichage du tableau trié
    }
    printf("\n");

    return 0;
}