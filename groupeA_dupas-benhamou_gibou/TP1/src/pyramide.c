
#include <stdio.h>

int main() {
    int n;
    printf("Saisissez un entier pour définir la hauteur de la pyramide : ");
    scanf("%d", &n);  // On demande à l'utilisateur de saisir un entier

    int i;
    int j;

    int a;
    int b;
    for (a=1; a<=n; a++) {
        for (b=1; b<=n-a; b++) {
            printf(" ");  // On affiche des espaces pour centrer la pyramide
        }
        for (b=1; b<=a; b++) {
            printf("%d", b);  // On affiche les chiffres de 1 à a
        }
        for (b=a-1; b>0; b--) {
            printf("%d", b);  // On affiche les chiffres de a-1 à 1
        }
        printf("\n");
    }
    return 0;
}