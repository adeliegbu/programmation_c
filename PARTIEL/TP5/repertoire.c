#define _GNU_SOURCE  // Pour obtenir la définition de DT_DIR

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "repertoire.h"

int lire_dossier(char* nom_repertoire) {  // Fonction qui lit le contenu d'un dossier
    DIR* dirp = opendir(nom_repertoire);
    if (dirp == NULL) {  // Si l'ouverture du dossier a échoué
        perror("opendir");
        return(EXIT_FAILURE);  // On retourne une erreur
    }
    struct dirent * ent;
    while(1) {
        ent = readdir(dirp);  // Lecture des entrées du dossier
        if (ent == NULL) {
            break;
        }
        printf("%s\n", ent->d_name);  // Affichage du nom de chaque fichier/dossier
    }
    closedir(dirp);
    return(0);
}

int lire_dossier_recursif(char* nom_repertoire) {  // Fonction qui lit le contenu d'un dossier de manière récursive
    DIR* dirp = opendir(nom_repertoire);  
    if (dirp == NULL) {  // Si l'ouverture du dossier a échoué
        perror("opendir");
        return(EXIT_FAILURE);  // On retourne une erreur
    }
    
    struct dirent * ent;
    char chemin_complet[1024];  // Pour stocker le chemin complet du fichier/dossier
    
    while(1) {
        ent = readdir(dirp);  // Lecture des entrées du dossier
        if (ent == NULL) {  // Si on a lu toutes les entrées
            break;  // On sort de la boucle
        }
        
        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {  // Ignorer les entrées "." et ".."
            continue;
        }
        
        printf("%s/%s\n", nom_repertoire, ent->d_name);  // Afficher le nom du fichier/dossier avec son chemin complet
    
        if (ent->d_type == DT_DIR) {  // Vérifier si c'est un dossier
            snprintf(chemin_complet, sizeof(chemin_complet), "%s/%s", nom_repertoire, ent->d_name);  // Construire le chemin complet
            lire_dossier_recursif(chemin_complet);  // Appel récursif
        }
    }
    closedir(dirp);
    return(0);
}

int lire_dossier_iteratif(char *nom_repertoire) {  // Fonction qui lit le contenu d'un dossier de manière itérative
    char *pile[1024];
    int top = 0;

    pile[top++] = strdup(nom_repertoire);  // On ajoute le répertoire de départ à la pile

    while (top > 0) {
        char *repertoire_courant = pile[--top];  // On dépile un répertoire
        DIR *dirp = opendir(repertoire_courant);  // On ouvre le répertoire
        if (!dirp) {  // Si l'ouverture a échoué
            perror("opendir");
            free(repertoire_courant);  // On libère la mémoire
            continue;
        }

        struct dirent *ent;  // Lecture des entrées du répertoire
        while ((ent = readdir(dirp)) != NULL) {  
            if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0)  // Ignorer les entrées "." et ".."
                continue;

            char chemin[1024];
            snprintf(chemin, sizeof(chemin), "%s/%s", repertoire_courant, ent->d_name);  // Construire le chemin complet
            printf("%s\n", chemin);

            if (ent->d_type == DT_DIR && top < 1024)  // Si c’est un répertoire, on l’ajoute à la pile
                pile[top++] = strdup(chemin);
        }

        closedir(dirp);
        free(repertoire_courant);
    }

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Utilisation : %s <nom_du_repertoire>\n", argv[0]);  // Vérification du nombre d'arguments
        return 1;
    }

    char* nom_repertoire = argv[1];
    // lire_dossier(nom_repertoire);  // Appel de la fonction pour lire le contenu du dossier
    // lire_dossier_recursif(nom_repertoire);  // Appel de la fonction pour lire le contenu du dossier de manière récursive
    lire_dossier_iteratif(nom_repertoire);

    return 0;
}
