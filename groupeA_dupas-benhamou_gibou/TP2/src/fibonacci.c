#include <stdio.h>

int main() {
    int n;
    printf("Combien de termes voulez-vous générer ? ");
    scanf("%d", &n);  // On demande à l'utilisateur de saisir le nombre de termes à générer
    printf("Voici la suite de Fibonacci :\n");
    int U0 = 0;  // Premier terme de la suite
    int U1 = 1;  // Deuxième terme de la suite
    printf("U0 = %d\n", U0);
    printf("U1 = %d\n", U1);
    int Un_2 = U0;  // U(n-2)
    int Un_1 = U1;  // U(n-1)
    for (int i=2; i<n; i++) {
        int Un = Un_1 + Un_2;  // Calcul du terme courant U(n) = U(n-1) + U(n-2)
        printf("U%d = %d\n", i, Un);  // On affiche le terme courant
        Un_2 = Un_1;  // Actualisation de U(n-2)
        Un_1 = Un;  // Actualisation de U(n-1)
    }
    return 0;
}