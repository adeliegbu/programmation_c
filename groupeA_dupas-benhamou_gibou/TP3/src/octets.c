#include <stdio.h>

// Fonction pour afficher les octets d'une variable
void afficher_octets(const char* nom_type, void* ptr, size_t taille) {
    printf("Octets de %s :\n", nom_type);
    unsigned char* byte_ptr = (unsigned char*)ptr;
    for (size_t j = 0; j < taille; j++) {
        printf(" %02x", byte_ptr[j]);
    }
    printf("\n");
}

int main() {
    short s = 0x1234;
    int i = 0x12345678;
    long int li = 0x123456789ABCDEF0;
    float f = 1.234f;
    double d = 1.234;
    long double ld = 1.234L;
    
    // Affichage des octets pour chaque type
    afficher_octets("short", &s, sizeof(short));
    afficher_octets("int", &i, sizeof(int));
    afficher_octets("long int", &li, sizeof(long int));
    afficher_octets("float", &f, sizeof(float));
    afficher_octets("double", &d, sizeof(double));
    afficher_octets("long double", &ld, sizeof(long double));
    
    return 0;
}