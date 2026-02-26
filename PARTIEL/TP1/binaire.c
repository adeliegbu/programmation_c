#include <stdio.h>

int main() {
    int num;
    printf("Saisissez un entier à convertir en binaire : ");
    scanf("%d", &num);  // On demande à l'utilisateur de saisir un entier

    int num_base = num;  // On stocke la valeur initiale de num pour pouvoir l'afficher à la fin du code
    long int select_bit = 1;  // Variable qui sélectionne la position du bit (1, 10, 100, 1000, ...)
    long int bin = 0;  // Variable qui contiendra le nombre binaire final
    int a;
    for (a=0; num!=0; a++) {  
        if (num%2 != 0) {  // Si le reste de la division par 2 est différent de 0, on ajoute le bit correspondant à la position sélectionnée
            bin += select_bit;
        }
        num /= 2;
        select_bit *= 10;
    }
    printf("%d en binaire vaut %ld\n", num_base, bin);  // On affiche le résultat
    return 0;
}