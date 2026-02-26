#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "fichier.h"

int lire_fichier(char* nom_de_fichier) {  // Fonction qui lit le contenu d'un fichier
    int fd, size;
    char content;
    fd = open (nom_de_fichier, O_RDONLY);  // On ouvre le fichier en lecture seule
    printf("Contenu du fichier %s :\n", nom_de_fichier);  
    while (1) {
        size = read(fd, &content, 1);  // On lit le fichier octet par octet
        if (size < 1) {
            break;
        }
        printf("%c", content);  // On affiche le contenu du fichier
    }
    printf("\n");
    close(fd);
    return 0;
}

int ecrire_dans_fichier(char* nom_de_fichier, char* message) {  // Fonction qui écrit un message dans un fichier
    int fd, size;
    fd = open(nom_de_fichier, O_CREAT|O_WRONLY|O_APPEND, S_IRUSR|S_IWUSR);  // On ouvre le fichier en écriture seule, on le crée s'il n'existe pas, on ajoute à la fin du fichier
    if (fd == -1) {
        printf("Erreur: impossible d'ouvrir le fichier %s\n", nom_de_fichier);
        return -1;
    }
    size = write(fd, message, strlen(message));  // On écrit le message dans le fichier
    close(fd);
    printf("Le message a été écrit dans le fichier %s\n", nom_de_fichier);  
    return 0;
}