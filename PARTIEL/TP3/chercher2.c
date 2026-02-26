#include <stdio.h>

int main() {
    char tableau[10][50] = {  // Déclaration et initialisation d'un tableau de 10 phrases
        "Bonjour, comment ça va ?",
        "Le temps est magnifique aujourd'hui.",
        "C'est une belle journée.",
        "La programmation en C est amusante.",
        "Les tableaux en C sont puissants.",
        "Les pointeurs en C peuvent être déroutants.",
        "Il fait beau dehors.",
        "La recherche dans un tableau est intéressante.",
        "Les structures de données sont importantes.",
        "Programmer en C, c'est génial.",
    };

    char phrase_chercher[50];  // Déclaration d'une variable pour stocker la phrase à chercher
    printf("Saisissez une phrase à chercher : ");
    fgets(phrase_chercher, sizeof(phrase_chercher), stdin);  // Lecture de la phrase à chercher
    
    for (int k = 0; phrase_chercher[k] != '\0'; k++) {  // Suppression du caractère de nouvelle ligne si présent
        if (phrase_chercher[k] == '\n') {
            phrase_chercher[k] = '\0';
            break;
        }
    }
    
    int phrase_trouvee = 0;  // Variable pour indiquer si la phrase a été trouvée

    for (int i = 0; i < 10; i++) {  // Parcours du tableau pour chercher la phrase
        int j = 0;  // Indice pour parcourir les caractères de la phrase
        int correspondance = 1;  // Variable pour indiquer si les caractères correspondent
        
        while (tableau[i][j] != '\0' && phrase_chercher[j] != '\0') {  // Parcours des caractères tant qu'on n'atteint pas la fin de l'une des phrases
            if (tableau[i][j] != phrase_chercher[j]) {  // Si les caractères ne correspondent pas
                correspondance = 0;
                break;  // On arrête la comparaison pour cette phrase, passage à la phrase suivante
            }
            j += 1;  // Passage au caractère suivant
        }
        
        if (correspondance && tableau[i][j] == '\0' && phrase_chercher[j] == '\0') {  // Si toutes les lettres correspondent et que les deux phrases sont de même longueur
            phrase_trouvee = 1;  // On indique que la phrase a été trouvée
            break;
        }
    }

    if (phrase_trouvee) {
        printf("Phrase trouvée\n");  // Si la phrase a été trouvée, on affiche le message
    } else {
        printf("Phrase non trouvée\n");  // Si la phrase n'a pas été trouvée, on affiche le message
    }

    return 0;
}