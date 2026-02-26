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

    for (int i = 0; i < size; i++) {
        tableau[i] = (rand() % 1000) + 1;  // Remplissage du tableau avec des valeurs aléatoires entre 1 et 1000
    }

    printf("Tableau trié : \n");
    tri(tableau, size);
    for (int i = 0; i < size; i++) {
        printf("%d ", tableau[i]);  // Affichage du tableau trié
    }
    printf("\n");


    int chercher;
    printf("Entrez l'entier que vous souhaitez chercher : ");
    scanf("%d", &chercher);  // On demande à l'utilisateur un entier à chercher dans le tableau

    int trouve = 0;  // Variable pour indiquer si l'entier a été trouvé
    int indice_min = 0;  // Indice min pour la recherche dichotomique
    int indice_max = size - 1;  // Indice max pour la recherche dichotomique
    while (indice_min <= indice_max) {  // Tant que l'indice min est inférieur ou égal à l'indice max
        int indice = (indice_max+indice_min)/2;  // Calcul de l'indice médian

        if (tableau[indice] < chercher) {
            indice_min = indice + 1;  // Si l'élément médian est inférieur à l'élément cherché, on cherche dans la moitié supérieure
        }
        else if (tableau[indice] > chercher) {
            indice_max = indice - 1;  // Si l'élément médian est supérieur à l'élément cherché, on cherche dans la moitié inférieure
        }
        else if (tableau[indice] == chercher) {
            trouve = 1;  // Si l'élément médian est égal à l'élément cherché, on a trouvé l'élément
            printf("Entier présent.\n");  // On affiche le message
            return 0;  // On termine le programme
        }
    }

    if (!trouve) {  // Si l'élément n'a pas été trouvé, on affiche le message
        printf("Entier absent.\n");
        return 0;  // On termine le programme
    }
}