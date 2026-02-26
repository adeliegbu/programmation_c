#include <stdio.h>

// int main() {
//     int compteur;
//     do {
//         printf("Saisissez un entier strictement inférieur à 10 : ");
//         scanf("%d", &compteur);  // On demande à l'utilisateur de saisir un entier
//         while (getchar() != '\n') {};  // On vide le buffer pour éviter les erreurs de saisie
//     } while (compteur >= 10 || compteur <= 0);  // On vérifie que l'entier est bien strictement inférieur à 10 et supérieur à 0

//     int a = 0;
//     for (a = 0; a <= compteur; a++){  
//         int b = 0;
//         for (b = 0; b < a; b++){ 
//             if (b == 0 || b == (a-1) || a == compteur) {  // On affiche une étoile si on est sur la première ou la dernière colonne, ou sur la dernière ligne
//                 printf("*");
//             }
//             else {
//                 printf("#");  // Sinon, on affiche un dièse
//             }
//         }
//     printf("\n");
//     }
//     return 0;
// }


int main() {
    int compteur;
    do {
        printf("Saisissez un entier strictement inférieur à 10 : ");
        scanf("%d", &compteur);
        while (getchar() != '\n') {};
    } while (compteur >= 10 || compteur <= 0);

    int a = 1;
    int num = 0;
    do {
        num++;
        if (num == 1 || a == compteur || num == a) {
            printf("*");  // On affiche une étoile si on est sur la première ou la dernière colonne, ou sur la dernière ligne
        }
        else {
            printf("#");  // Sinon, on affiche un dièse
        }

        if (a == num) {
            a++;
            num = 0;
            printf("\n");  // On passe à la ligne suivante lorsque le nombre de caractères affichés est égal au numéro de la ligne
        }

    } while (a <= compteur);  // On continue tant que le numéro de la ligne est inférieur ou égal au compteur saisi par l'utilisateur
    return 0;
}