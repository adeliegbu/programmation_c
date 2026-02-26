#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int fd, size;
    char content;

    if (argc != 3) {
        printf("Pas le bon nombre d'arguments.\n");
        return 0;
    }

    
    char* nom_du_fichier = argv[1];
    int n = atoi(argv[2]);

    int nb_lignes = 1;

    int ligne = 1;

    fd = open (nom_du_fichier, O_RDONLY);  // On ouvre le fichier en lecture seule
    if (fd == -1) {
        printf("Erreur : impossible d'ouvrir le fichier '%s'\n", nom_du_fichier);
        return 1;  // Ou return -1 pour indiquer une erreur
    }

    while (1) {
        size = read(fd, &content, 1);  // On lit le fichier octet par octet
        if (size < 1) {
            break;
        } 

        if (content == '\n') {
            nb_lignes ++;
        }
        
    }
    close(fd);
    fd = open (nom_du_fichier, O_RDONLY);  // On ouvre le fichier en lecture seule

    while (1) {
        size = read(fd, &content, 1);  // On lit le fichier octet par octet
        if (size < 1) {
            break;
        }
        if (content == '\n') {
            ligne ++;
        }

        if (ligne <= n || ligne >= (nb_lignes - n + 1)) {
            printf("%c", content);  // On affiche le contenu du fichier
        }
        
    }
    close(fd);
    printf("\n");

return 0;

}