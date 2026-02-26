#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int max = atoi(argv[1]);
    for (int i = 2; i < argc; i++) {
        if (atoi(argv[i]) > max) {
            max = atoi(argv[i]);
        }
    }
    
    int min = atoi(argv[1]);
    for (int i = 2; i < argc; i++) {
        if (atoi(argv[i]) < min) {
            min = atoi(argv[i]);
        }
    }

    float som = atoi(argv[1]);
    for (int i = 2; i < argc; i++) {
        som += atoi(argv[i]);
    }
    som /= (argc-1);

    printf("Nombre de nombre %d\n", (argc-1));
    printf("Nombre le plus grand %d\n", max);
    printf("Nombre le plus petit %d\n", min);
    printf("Moyenne %f\n", som);
    return 0;
}
