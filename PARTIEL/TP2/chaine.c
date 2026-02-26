#include <stdio.h>

int compter_caracteres(char chaine[]) {  // Fonction pour compter le nombre de caractères dans une chaîne
    int i = 0;
    while (chaine[i] != '\0') {  // On compte les caractères jusqu'au caractère nul
        i ++;
    }
    return i;
}

void copier_chaine(char chaine[], char chaine_dest[], int taille) {  // Fonction pour copier une chaîne de caractères
    for (int j = 0; j <= taille; j++) {  // On copie jusqu'au caractère nul inclus
        chaine_dest[j] = chaine[j];  // On copie chaque caractère de la chaîne source vers la chaîne destination
    }
}

void concatener(char chaine[], char chaine2[]) {  // Fonction pour concaténer deux chaînes de caractères
    int taille1 = compter_caracteres(chaine);
    int taille2 = compter_caracteres(chaine2);
    for (int i = 0; i<=taille2; i++) {  // On parcourt la deuxième chaîne jusqu'au caractère nul inclus
        chaine[taille1 + i] = chaine2[i];  // On ajoute chaque caractère de la deuxième chaîne à la fin de la première chaîne, y compris le caractère nul
    }
}

int main() {
    char chaine[100] = "Hello ";

    int i = compter_caracteres(chaine);  // On fait appel à la fonction pour compter les caractères
    printf("Il y a %d charactères dans la chaine %s.\n", i, chaine);  
    
    char chaine_dest[i+1];
    copier_chaine(chaine, chaine_dest, i);  // On fait appel à la fonction pour copier la chaîne
    printf("Chaine destination : %s\n", chaine_dest);
    
    char chaine2[] = "world!";
    concatener(chaine, chaine2);  // On fait appel à la fonction pour concaténer les deux chaînes
    printf("Concaténation chaines 1 et 2 : %s\n", chaine);

    return 0;
}