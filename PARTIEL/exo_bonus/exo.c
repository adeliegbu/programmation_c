#include <stdio.h>

 

union Valeur {

    int entier;

    float reel;

    char texte[20];

};

 

struct Variable {

    int type; // 0=int, 1=float, 2=string

    union Valeur v;

};

 

int main() {

    struct Variable var;

    var.type = 0;

    var.v.entier = 42;

    var.v.reel = 3.14; 

    printf("Valeur = %d\n", var.v.entier); 

    return 0;

}