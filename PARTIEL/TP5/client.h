#ifndef CLIENT_H
#define CLIENT_H

#define PORT 8080
#define BUF_SIZE 1024

int envoie_operateur_numeros(int socketfd, char operateur, double num1, double num2);
double lire_note(const char *chemin_fichier);
double calculer_somme_etudiant(int socketfd, int num_etudiant);
double calculer_moyenne_classe(int socketfd);

#endif