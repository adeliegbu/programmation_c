#include <stdio.h>
#include <string.h>
#include "fichier.h"

int main() {
    struct etudiants{  // Structure pour stocker les informations des étudiants
        char prenom[30];
        char nom[30];
        char adresse[50];
        float programmation_c;
        float systeme_exploitation;
    };

    int nb_etudiants = 5;  // Nombre d'étudiants à gérer

    struct etudiants etudiant[nb_etudiants];  // Tableau de structures pour stocker les informations de plusieurs étudiants

    for (int i = 0; i < nb_etudiants; i++) {  
        printf("Entrez les détails de l'étudiant.e %d:\n", i+1);

        printf("Prénom : ");
        scanf(" %29[^\n]", etudiant[i].prenom);  // Lit jusqu'à 29 caractères ou jusqu'au retour à la ligne
        while (getchar() != '\n');

        printf("Nom : ");
        scanf(" %29[^\n]", etudiant[i].nom);  // Lit jusqu'à 29 caractères ou jusqu'au retour à la ligne
        while (getchar() != '\n');

        printf("Adresse : ");
        scanf(" %49[^\n]", etudiant[i].adresse);  // Lit jusqu'à 49 caractères ou jusqu'au retour à la ligne
        while (getchar() != '\n');

        printf("Note Programmation C : ");
        scanf(" %f", &etudiant[i].programmation_c);  // On demande à l'utilisateur de saisir la note de Programmation C de l'étudiant
        while (getchar() != '\n');

        printf("Note Système d'exploitation : ");
        scanf(" %f", &etudiant[i].systeme_exploitation);  // On demande à l'utilisateur de saisir la note de Système d'exploitation de l'étudiant
        while (getchar() != '\n');

        printf("\n");

        // On écrit les informations de l'étudiant dans un fichier texte
        char buffer[500];
        sprintf(buffer, "Etudiant.e %d : Prenom : %s Nom : %s Adresse : %s Note Programmation C : %.2f Note Système d'exploitation : %.2f\n",
                i+1, etudiant[i].prenom, etudiant[i].nom, etudiant[i].adresse, 
                etudiant[i].programmation_c, etudiant[i].systeme_exploitation);
        ecrire_dans_fichier("etudiants.txt", buffer);
    }
    return 0;
}