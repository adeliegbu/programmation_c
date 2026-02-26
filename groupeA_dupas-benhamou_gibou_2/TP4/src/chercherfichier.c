#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int compter_occurrences(char* ligne, char* phrase) {  // Fonction pour compter les occurrences d'une phrase dans une ligne
    int count = 0;
    char* ptr = ligne;  // Pointeur pour parcourir la ligne
    
    while ((ptr = strstr(ptr, phrase)) != NULL) {  // Trouve la phrase dans la ligne
        count++;
        ptr += strlen(phrase);  // Avance le pointeur pour chercher la prochaine occurrence
    }
    
    return count;
}

int chercher_dans_fichier(char* nom_de_fichier, char* phrase) {  // Fonction pour chercher une phrase dans un fichier
    FILE* fichier = fopen(nom_de_fichier, "r");  // Ouvre le fichier en mode lecture
    if (fichier == NULL) {  // Vérifie si le fichier a été ouvert avec succès
        printf("Erreur : Impossible d'ouvrir le fichier '%s'\n", nom_de_fichier);
        return -1;
    }
    
    char ligne[1024];  // Buffer pour stocker chaque ligne du fichier
    int numero_ligne = 0;  // Compteur de lignes
    int total_occurrences = 0;  // Compteur total d'occurrences trouvées
    
    printf("\nRésultats de la recherche :\n");
    
    while (fgets(ligne, sizeof(ligne), fichier)) {  // Lit chaque ligne du fichier
        numero_ligne++;  // Incrémente le numéro de ligne
        int occurrences = compter_occurrences(ligne, phrase);  // Compte les occurrences dans la ligne courante
        
        if (occurrences > 0) {  // Si des occurrences sont trouvées, affiche le résultat
            printf("Ligne %d, %d fois\n", numero_ligne, occurrences);
            total_occurrences += occurrences;
        }
    }
    
    if (total_occurrences == 0) {  // Si aucune occurrence n'a été trouvée, affiche un message
        printf("Aucune occurrence de la phrase '%s' trouvée dans le fichier.\n", phrase);
    } else {
        printf("\nTotal : %d occurrence(s) trouvée(s)\n", total_occurrences);
    }
    
    fclose(fichier);
    return total_occurrences;
}

int main() {
    char nom_de_fichier[256];
    printf("Saisissez le nom du fichier dans lequel vous souhaitez effectuer la recherche : ");  // Demande du nom de fichier
    scanf("%255s", nom_de_fichier);
    
    while (getchar() != '\n');  // Vider le buffer d'entrée
    
    char phrase[256];
    printf("Saisissez la phrase que vous souhaitez rechercher : ");
    fgets(phrase, sizeof(phrase), stdin);
    
    phrase[strcspn(phrase, "\n")] = '\0';  // Supprimer le caractère de nouvelle ligne à la fin
    
    chercher_dans_fichier(nom_de_fichier, phrase);  // Appel de la fonction de recherche
    
    return 0;
}