#include <stdio.h> 
#include <math.h>

int main () {
    float rayon;
    printf("Saisissez une valeur de rayon : ");  
    scanf("%f", &rayon);  // On demande à l'utilisateur de saisir un rayon
    float aire = M_PI * rayon * rayon;  // Calcul de l'aire du cercle
    float perimetre = 2.0 * M_PI * rayon;  // Calcul du périmètre du cercle
    printf("Aire : %f\n", aire);  // On affiche l'aire du cercle
    printf("Périmètre : %f\n", perimetre);  // On affiche le périmètre du cercle
    return 0;
}