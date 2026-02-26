#include <stdio.h>
#include "operator.h"

int somme(int num1, int num2) {  // Fonction pour additionner deux entiers
    return num1 + num2;
}

int difference(int num1, int num2) {  // Fonction pour soustraire deux entiers
    return num1 - num2;
}

int produit(int num1, int num2) {  // Fonction pour multiplier deux entiers
    return num1 * num2;
}

float quotient(int num1, int num2) {  // Fonction pour diviser deux entiers
    if (num2 == 0) {  // Vérification de la division par zéro
        printf("Division par 0 impossible\n");
        return 0;
    }
        return (float)num1 / (float)num2;
}

int modulo(int num1, int num2) {  // Fonction pour calculer le reste de la division de deux entiers
    return num1 % num2;
}

int et(int num1, int num2) {  // Fonction pour effectuer un ET logique entre deux entiers
    return num1 & num2;
}

int ou(int num1, int num2) {  // Fonction pour effectuer un OU logique entre deux entiers
    return num1 | num2;
}

int negation(int num1) {  // Fonction pour effectuer une négation logique sur un entier
    return ~ num1;
}