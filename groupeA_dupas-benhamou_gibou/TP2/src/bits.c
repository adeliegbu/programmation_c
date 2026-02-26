#include <stdio.h>

int main() {
    int d = 268439552; // Entier sur 32 bits
    int bit4 = (d >> 31 - 3) & 1; // 31 - 3 décalages à droite pour faire passer le 4ème bit de gauche en 1er bit de droite et faire "ET 1"
    int bit20 = (d >> 31 - 19) & 1; // 31 - 19 décalages à droite pour faire passer le 20ème bit de gauche en 1er bit de droite et faire "ET 1"
    printf("%d\n", (bit4 & bit20));
    return 0;
}