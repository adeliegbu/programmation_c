#include <stdio.h>

int main() {
    int somme = 0;
    int a;
    for (a = 0; a <= 1000; a++) {
        if (((a%5 == 0) || (a%7 == 0)) && (a%11) != 0) {  // On regarde si a est un multiple de 5 ou 7 mais pas de 11
            somme += a;  // On ajoute a à la somme
        }
        if (somme > 5000) {  // Si la somme dépasse 5000, on arrête la boucle
            break;
        }
    }
    printf("Somme = %d\n", somme);
    return 0;
}