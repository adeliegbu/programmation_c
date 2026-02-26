#include <stdio.h>
#include <stdlib.h>
#include "operator.h"

int main(int argc, char** argv) {
    if (argc < 4) {
        printf("Usage: %s <operateur> <nombre1> <nombre2>\n", argv[0]);
        return 1;
    }

    int num1 = atoi(argv[2]);  // On convertit le premier argument en entier
    int num2 = atoi(argv[3]);  // On convertit le second argument en entier
    char op = argv[1][0];  // On récupère l'opérateur

    switch (op) {
        case '+' : 
            printf("%d\n", somme(num1, num2));  // On affiche le résultat de l'opération
            break;  // On sort du switch quand l'opérateur a été trouvé
        case '-' : 
            printf("%d\n", difference(num1, num2));
            break;
        case '*' :
            printf("%d\n", produit(num1, num2));
            break;
        case '/' :
            printf("%f\n", (float)quotient(num1, num2));
            break;
        case '%' :
            printf("%d\n", modulo(num1, num2));
            break;
        case '&' :
            printf("%d\n", et(num1, num2));
            break;
        case '|' :
            printf("%d\n", ou(num1, num2));
            break;
        case '~' :
            printf("%d\n", negation(num1));
            break;
    }
    return 0;
}