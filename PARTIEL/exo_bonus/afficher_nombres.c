#include <stdio.h>

int main() {
    int i = 0;
    while (i <= 1000) {
        if (i%5 == 0 & i%3 != 0) {
            printf("%d\n", i);
        }
        i++;
    }
    return 0;
}



int main() {
    int i = 0;
    do {
        if (i%5 == 0 & i%3 != 0) {
            printf("%d\n", i);
        }
        i++;
    } while (i <= 1000);
}