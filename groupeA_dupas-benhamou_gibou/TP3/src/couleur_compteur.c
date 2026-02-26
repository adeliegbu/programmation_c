#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct couleurs{  // Structure pour stocker les détails d'une couleur (RGBA)
    int R;
    int G;
    int B;
    int A;
};

struct compteur_couleurs{  // Structure pour stocker les occurrences de chaque couleur
    struct couleurs couleur;
    int occurences;
};

int meme_couleur(struct couleurs couleur1, struct couleurs couleur2) {  // Fonction pour comparer deux couleurs
    return (couleur1.R == couleur2.R && couleur1.G == couleur2.G && couleur1.B == couleur2.B && couleur1.A == couleur2.A);
};

int main() {
    int size = 100;

    struct couleurs couleur[size];  // Déclaration d'un tableau de 100 couleurs
    struct compteur_couleurs distinctes[size];  // Déclaration d'un tableau pour stocker les couleurs distinctes et leurs occurrences
    int couleurs_distinctes = 0;

    srand(time(NULL));  // Initialisation de la graine pour la génération de nombres aléatoires

    for (int i = 0; i < size; i++) {  // Remplissage du tableau avec des couleurs aléatoires
        couleur[i].R = rand() % 256;
        couleur[i].G = rand() % 256;
        couleur[i].B = rand() % 256;
        couleur[i].A = 255;
    }
    
    for (int i = 0; i < size; i++) {  // Parcours du tableau pour compter les occurrences de chaque couleur
        int trouve = 0;
        for (int j = 0; j < couleurs_distinctes; j++) {  // Vérification si la couleur a déjà été rencontrée
            if (meme_couleur(couleur[i], distinctes[j].couleur)) {
                distinctes[j].occurences += 1;  // Si la couleur a été rencontrée, on incrémente son compteur
                trouve = 1;  
                break;
            }
        }
        if (!trouve) {  // Si la couleur n'a pas été rencontrée, on l'ajoute au tableau des couleurs distinctes
            distinctes[couleurs_distinctes].couleur = couleur[i];
            distinctes[couleurs_distinctes].occurences = 1;
            couleurs_distinctes += 1;
        }            
    }
    
    printf("Couleurs distinctes trouvées :\n");  // Affichage des couleurs distinctes et de leurs occurrences
    for (int i = 0; i < couleurs_distinctes; i++) {
        printf("%02x %02x %02x %02x : %d\n", 
               distinctes[i].couleur.R, distinctes[i].couleur.G, 
               distinctes[i].couleur.B, distinctes[i].couleur.A, 
               distinctes[i].occurences);
    }

    printf("\nNombre total de couleurs distinctes : %d\n", couleurs_distinctes);

    return 0;
}