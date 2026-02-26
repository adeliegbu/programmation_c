#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[]) {  // Fonction qui compte le nombre de charactères, mots, lignes et valeurs numériques dans un fichier
    int fd, size;
    char content;

    if (argc != 2) {
        printf("Le nombre d'arguments rentrés est incorrect. \n");
        return 0;
    }

    char* nom_du_fichier = argv[1];

    int nb_char = 0;
    int nb_lign = 1;
    int nb_word = 0;
    int nb_int = 0;
    char old_content = ' ';

    fd = open (nom_du_fichier, O_RDONLY);  // On ouvre le fichier en lecture seule
    if (fd == -1) {
        printf("Erreur : impossible d'ouvrir le fichier '%s'\n", nom_du_fichier);
        return 1;  // Ou return -1 pour indiquer une erreur
    }
    while (1) {
        size = read(fd, &content, 1);  // On lit le fichier octet par octet
        if (size < 1) {
            if (old_content != ' ' && old_content != '\n' && !ispunct(old_content)) {
                nb_word ++;
            }
            break;
        } 

        if (content != '\n') {
            nb_char ++;
            if (isdigit(content) && !isdigit(old_content)) {
                nb_int ++;
            }
        } 
        else {
            nb_lign ++;
        }
        if ((content == ' ' || content == '\n' || ispunct(content)) && (old_content != ' ' && old_content != '\n' && !ispunct(old_content))) {
            nb_word ++;
        }
        old_content = content;
    }
    printf("Nombre total de charactères : %d \n", nb_char);
    printf("Nombre total de lignes : %d \n", nb_lign);
    printf("Nombre total de mots : %d \n", nb_word);
    printf("Nombre total de valeurs numériques : %d \n", nb_int);

    close(fd);
    return 0;
}