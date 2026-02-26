#include <stdio.h>
#include "operator.h"
#include "fichier.h"
#include "liste.h"

int operator() {  // Fonction pour exécuter les opérations arithmétiques et logiques
    int num1;
    printf("Saisissez un entier : ");
    scanf(" %d", &num1);  // On demande à l'utilisateur de saisir un entier
    while (getchar() != '\n');

    int num2;
    printf("Saisissez un second entier : ");
    scanf(" %d", &num2);  // On demande à l'utilisateur de saisir un second entier
    while (getchar() != '\n');

    char op;
    printf("Saisissez un opérateur : ");
    scanf(" %c", &op);  // On demande à l'utilisateur de saisir un opérateur (+, -, *, /, %, &, |, ~)
    while (getchar() != '\n');

    switch (op) {  // On utilise un switch pour déterminer l'opération à effectuer en fonction de l'opérateur saisi
        case '+' : 
            printf("%d %c %d = %d\n", num1, op, num2, somme(num1, num2));  // On affiche le résultat de l'opération
            break;  // On sort du switch quand l'opérateur a été trouvé
        case '-' : 
            printf("%d %c %d = %d\n", num1, op, num2, difference(num1, num2));
            break;
        case '*' :
            printf("%d %c %d = %d\n", num1, op, num2, produit(num1, num2));
            break;
        case '/' :
            printf("%d %c %d = %f\n", num1, op, num2, (float)quotient(num1, num2));
            break;
        case '%' :
            printf("%d %c %d = %d\n", num1, op, num2, modulo(num1, num2));
            break;
        case '&' :
            printf("%d %c %d = %d\n", num1, op, num2, et(num1, num2));
            break;
        case '|' :
            printf("%d %c %d = %d\n", num1, op, num2, ou(num1, num2));
            break;
        case '~' :
            printf("%c %d = %d\n", op, num1, negation(num1));
            break;
    }
    return 0;
}

int fichier() {  // Fonction pour lire ou écrire dans un fichier
    int question;
    printf("Que voulez vous faire ?\n1: lire un fichier\n2: écrire dans un fichier\nVotre choix : ");  // On demande à l'utilisateur ce qu'il veut faire
    scanf(" %d", &question);
    while (getchar() != '\n');

    if (question == 1) {  // Si l'utilisateur veut lire un fichier
        char nom_de_fichier[256];
        printf("Entrez le nom du fichier à lire : ");
        scanf(" %s", nom_de_fichier);  // On demande le nom du fichier à lire
        while (getchar() != '\n');

        lire_fichier(nom_de_fichier);  // On appelle la fonction pour lire le fichier
    }
    if (question == 2) {  // Si l'utilisateur veut écrire dans un fichier
        char nom_de_fichier[256];
        printf("Entrez le nom du fichier dans lequel vous souhaitez écrire : ");
        scanf(" %s", nom_de_fichier);  // On demande le nom du fichier dans lequel écrire
        while (getchar() != '\n');

        char message[1024];
        printf("Entrez le message à écrire : ");
        scanf(" %[^\n]", message);  // On demande le message à écrire dans le fichier
        while (getchar() != '\n');

        ecrire_dans_fichier(nom_de_fichier, message);  // On appelle la fonction pour écrire dans le fichier
    }
    return 0;
}

int liste() {  // Fonction pour gérer une liste de couleurs
    struct liste_couleurs ma_liste;  // déclaration de la liste de couleurs
    init_liste(&ma_liste);  // initialisation de la liste

    struct couleur couleurs[10] = {  // tableau de couleurs prédéfinies
        {255, 0, 0, 255},     // rouge
        {0, 255, 0, 255},     // vert
        {0, 0, 255, 255},     // bleu
        {255, 255, 0, 255},   // jaune
        {255, 0, 255, 255},   // magenta
        {0, 255, 255, 255},   // cyan
        {128, 128, 128, 255}, // gris
        {255, 128, 0, 255},   // orange
        {128, 0, 255, 255},   // violet
        {255, 255, 255, 255}  // blanc
    };

    for (int i = 0; i < 10; i++) {
        insertion(&couleurs[i], &ma_liste);  // insertion de chaque couleur dans la liste à l'aide de la fonction d'insertion
    }

    printf("Liste des couleurs :\n");
    parcours(&ma_liste);  // parcours et affichage de la liste des couleurs à l'aide de la fonction de parcours
    return 0;
}

int main() {  // Fonction principale
    int exo;
    printf("Quel exercice voulez vous exécuter ? ");
    scanf(" %d", &exo);  // On demande à l'utilisateur quel exercice il veut exécuter
    while (getchar() != '\n');


    if (exo == 1) {  // Si l'utilisateur choisit l'exercice 1, appeler la fonction operator
        operator();
    }

    else if (exo == 2) {  // Si l'utilisateur choisit l'exercice 2, appeler la fonction fichier
        fichier();
    }

    else if (exo == 7) {  // Si l'utilisateur choisit l'exercice 7, appeler la fonction liste
        liste(); 
    }

    else {  // Si l'utilisateur entre un numéro d'exercice invalide, afficher un message d'erreur
        printf("Option invalide.\n");
    }

    return 0;
    }