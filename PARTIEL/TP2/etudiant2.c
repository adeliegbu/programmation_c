#include <stdio.h>
#include <string.h>

int main() {
    struct etudiants{  // Structure pour stocker les informations des étudiants
        char prenom[30];
        char nom[30];
        char adresse[50];
        float programmation_c;
        float systeme_exploitation;
    };

    struct etudiants etudiant[5];  // Tableau de 5 structures pour stocker les informations de 5 étudiants

    strcpy(etudiant[0].prenom, "Adélie");
    strcpy(etudiant[0].nom, "GIBOU");
    strcpy(etudiant[0].adresse, "12 rue des Erables");
    etudiant[0].programmation_c = 20;
    etudiant[0].systeme_exploitation = 18;

    strcpy(etudiant[1].prenom, "Evan");
    strcpy(etudiant[1].nom, "BENHAMOU");
    strcpy(etudiant[1].adresse, "45 avenue du Soleil");
    etudiant[1].programmation_c = 19;
    etudiant[1].systeme_exploitation = 19.5;

    strcpy(etudiant[2].prenom, "Gauthier");
    strcpy(etudiant[2].nom, "BOVET");
    strcpy(etudiant[2].adresse, "8 impasse des Lilas");
    etudiant[2].programmation_c = 15;
    etudiant[2].systeme_exploitation = 2.75;

    strcpy(etudiant[3].prenom, "Loann");
    strcpy(etudiant[3].nom, "CORDEL");
    strcpy(etudiant[3].adresse, "27 boulevard des Horizons");
    etudiant[3].programmation_c = 6.5;
    etudiant[3].systeme_exploitation = 1.25;

    strcpy(etudiant[4].prenom, "Loris");
    strcpy(etudiant[4].nom, "MAZUEL");
    strcpy(etudiant[4].adresse, "99 chemin du Moulin Vert");
    etudiant[4].programmation_c = 11.25;
    etudiant[4].systeme_exploitation = 19.75;

    for (int i = 0; i < 5; i++) {  // On affiche les informations de chaque étudiant
        printf("Etudiant.e %d:\n", i+1);
        printf("  Prénom : %s\n", etudiant[i].prenom);
        printf("  Nom : %s\n", etudiant[i].nom);
        printf("  Adresse : %s\n", etudiant[i].adresse);
        printf("  Note Programmation C : %f\n", etudiant[i].programmation_c);
        printf("  Note Système d'exploitation : %f\n\n", etudiant[i].systeme_exploitation);
    }

    return 0;
}
