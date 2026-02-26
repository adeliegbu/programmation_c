#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int size = 100;
    int tableau[size];  // Déclaration d'un tableau de 100 entiers

    srand(time(NULL));  // Initialisation de la graine pour la génération de nombres aléatoires

    printf("Tableau : \n");
    for (int i = 0; i < size; i++) {
        tableau[i] = (rand() % 1000) + 1;  // Remplissage du tableau avec des valeurs aléatoires entre 1 et 1000
        printf("%d ", tableau[i]);
    }
    printf("\n");

    int chercher;
    printf("Entrez l'entier que vous souhaitez chercher : ");  
    scanf("%d", &chercher);  // On demande à l'utilisateur un entier à chercher dans le tableau

    for (int i = 0; i < size; i++) {  // Parcours du tableau pour chercher l'entier
        if (tableau[i] == chercher) { 
            printf("Entier présent.\n");  // Si l'entier est trouvé, on affiche le message
            return 0;  // On termine le programme
        }
    }
    printf("Entier absent.\n");  // Si l'entier n'est pas trouvé, on affiche le message
    return 0;
}