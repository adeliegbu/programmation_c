#include <stdio.h>

int main() {
    int a = 16, b = 3;
    printf("%d + %d = %d\n", a, b, (a+b));  // On affiche le résultat de l'addition
    printf("%d - %d = %d\n", a, b, (a-b));  // On affiche le résultat de la soustraction
    printf("%d * %d = %d\n", a, b, (a*b));  // On affiche le résultat de la multiplication
    printf("%d / %d = %f\n", a, b, ((float)a/(float)b));  // On affiche le résultat de la division en convertissant les entiers en float pour avoir un résultat décimal
    printf("%d %% %d = %d\n", a, b, (a%b));  // On affiche le reste de la division entière
    printf("%d == %d ? %d\n", a, b, (a==b));  // On affiche le résultat de la comparaison d'égalité (1 si vrai, 0 si faux)
    printf("%d != %d ? %d\n", a, b, (a!=b));  // On affiche le résultat de la comparaison de différence (1 si vrai, 0 si faux)
    printf("%d >= %d ? %d\n", a, b, (a>=b));  // On affiche le résultat de la comparaison de supériorité ou égalité (1 si vrai, 0 si faux)
    return 0;
}
