#include <stdio.h>

// Définition de la fonction factorielle
int factorielle(int num) {
  if (num == 0) {
    printf("fact(0): 1\n");
    return 1;
  }
  else {
    int valeur = num * factorielle(num - 1);
    printf("fact(%d): %d\n", num, valeur);
    return (valeur);
  }
}

int main() {
    int n;
    printf("Entrez un entier non négatif: ");  // Demande à l'utilisateur de saisir un entier
    scanf("%d", &n);  // Lecture de l'entier saisi par l'utilisateur
    if (n < 0) {  // Si l'entier est négatif, afficher un message d'erreur
        printf("Erreur: Entier négatif.\n");
    } else {  // Sinon, calculer et afficher la factorielle de l'entier
        int resultat = factorielle(n);
        printf("La factorielle de %d est %d\n", n, resultat);
    }
    return 0;
}