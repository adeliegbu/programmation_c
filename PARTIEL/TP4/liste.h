#ifndef LISTE_H
#define LISTE_H

#include <stdio.h>
#include <stdlib.h>

struct couleur {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
};

struct element {
    struct couleur color;
    struct element *suivant;
};

struct liste_couleurs {
    struct element *tete;
};

void init_liste(struct liste_couleurs *liste);
void insertion(const struct couleur *c, struct liste_couleurs *liste);
void parcours(const struct liste_couleurs *liste);

#endif
