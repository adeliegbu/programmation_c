#include <stdio.h> 

int main() {
    int a = 5;
    int b = 20;
    int puissance = 1;
    int i;
    for (i = 0; i < b; i++){
        puissance *= a;  // On multiplie puissance par a, b fois
    }
    printf("%d**%d = %d\n", a, b, puissance);  // On affiche le résultat

    return 0;
}