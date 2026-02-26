#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int find_min(int tableau[], int size) {  // Fonction pour trouver le minimum dans un tableau
    int min = tableau[0];  // Initialisation du minimum avec le premier élément du tableau
    for (int i = 0; i < size; i++) {  // Parcours du tableau
        if (tableau[i] < min) {
            min = tableau[i];  // Mise à jour du minimum si un élément plus petit est trouvé
        }
    }
    return min;
}

int find_max(int tableau[], int size) {  // Fonction pour trouver le maximum dans un tableau
    int max = tableau[0];  // Initialisation du maximum avec le premier élément du tableau
    for (int i = 0; i < size; i++) {  // Parcours du tableau
        if (tableau[i] > max) {
            max = tableau[i];  // Mise à jour du maximum si un élément plus grand est trouvé
        }
    }
    return max;
}


int main() {
    int size = 100;
    int tableau[size];  // Déclaration d'un tableau de 100 entiers

    srand(time(NULL));  // Initialisation de la graine pour la génération de nombres aléatoires


    for (int i = 0; i < size; i++) {
        tableau[i] = (rand() % 1000) + 1;  // Remplissage du tableau avec des valeurs aléatoires entre 1 et 1000
    }

    int min = find_min(tableau, size);  // Appel de la fonction pour trouver le minimum
    int max = find_max(tableau, size);  // Appel de la fonction pour trouver le maximum

    printf("Le numéro le plus petit est : %d\n", min);
    printf("Le numéro le plus grand est : %d\n", max);

    return 0;
}