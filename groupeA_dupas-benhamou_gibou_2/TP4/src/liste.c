#include <stdio.h>
#include "liste.h"

void init_liste(struct liste_couleurs *liste) {  // initialisation de la liste
    liste->tete = NULL;
}

void insertion(const struct couleur *c, struct liste_couleurs *liste) {  // insertion d'une couleur dans la liste
    struct element *nouveau = malloc(sizeof(struct element));  // allocation mémoire pour le nouvel élément
    if (nouveau == NULL) {
        perror("Erreur d'allocation mémoire");
        exit(EXIT_FAILURE);
    }

    nouveau->color = *c;  // copie de la couleur
    nouveau->suivant = liste->tete;  // insertion en tête
    liste->tete = nouveau;  // mise à jour de la tête de la liste
}

void parcours(const struct liste_couleurs *liste) {  // parcours et affichage de la liste
    struct element *courant = liste->tete;

    while (courant != NULL) {  // tant qu'on n'est pas à la fin de la liste
        printf("R:%3d  G:%3d  B:%3d  A:%3d\n",  // affichage de la couleur
               courant->color.r,
               courant->color.g,
               courant->color.b,
               courant->color.a);
        courant = courant->suivant;
    }
}
