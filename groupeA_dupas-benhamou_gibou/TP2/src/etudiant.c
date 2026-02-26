#include <stdio.h>

int main() {
    char identite[5][2][30] =  {  // Tableau 2D pour stocker le prénom et le nom de 5 étudiants
        {"Adélie", "GIBOU"},
        {"Evan", "BENHAMOU"},
        {"Gauthier", "BOVET"},
        {"Loann", "CORDEL"},
        {"Loris", "MAZUEL"}
    };
    char *adresses[5] = {  // Tableau de pointeurs pour stocker les adresses des 5 étudiants
        "12 rue des Erables",
        "45 avenue du Soleil",
        "8 impasse des Lilas",
        "27 boulevard des Horizons",
        "99 chemin du Moulin Vert"
    };
    float programmation_c[5] = {  // Tableau pour stocker les notes de Programmation en C des 5 étudiants
        20,
        19,
        15,
        6.5,
        11.25
    };
    float systeme_exploitation[5] = {  // Tableau pour stocker les notes de Système d'exploitation des 5 étudiants
        18,
        19.5,
        2.75,
        1.25,
        19.75
    };

    for (int i = 0; i < 5; i++) {  // On affiche les informations de chaque étudiant
        printf("Prénom : %s, Nom : %s, Adresse : %s, Note Programmation en C : %f, Note Système d'exploitation : %f.\n",
                identite[i][0], identite[i][1], adresses[i], programmation_c[i], systeme_exploitation[i]);
    };

    return 0;
}