#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "client.h"

// Fonction pour lire une note depuis un fichier
double lire_note(const char *chemin_fichier)
{
    FILE *file = fopen(chemin_fichier, "r");
    if (file == NULL)
    {
        perror("Erreur: impossible d'ouvrir le fichier");
        return 0.0;
    }

    double note;
    if (fscanf(file, "%lf", &note) != 1)
    {
        fprintf(stderr, "Erreur: lecture de la note échouée\n");
        fclose(file);
        return 0.0;
    }

    fclose(file);
    return note;
}

// Fonction pour envoyer une opération au serveur
int envoie_operateur_numeros(int socketfd, char operateur, double num1, double num2)
{
    char message[BUF_SIZE];
    char response[BUF_SIZE];

    // Créer le message: "operateur num1 num2"
    sprintf(message, "%c %.2f %.2f", operateur, num1, num2);
    printf("Envoi: %s\n", message);

    // Envoyer au serveur
    if (write(socketfd, message, strlen(message)) < 0)
    {
        perror("Erreur: envoi échoué");
        return -1;
    }

    // Recevoir la réponse
    memset(response, 0, sizeof(response));
    int valread = read(socketfd, response, BUF_SIZE);
    if (valread < 0)
    {
        perror("Erreur: réception échouée");
        return -1;
    }

    printf("Résultat reçu: %s\n", response);

    return atof(response);
}

// Fonction pour calculer la somme des notes d'un étudiant
double calculer_somme_etudiant(int socketfd, int num_etudiant)
{
    char chemin[256];
    double notes[5];
    double somme = 0;

    printf("\n=== Calcul de la somme pour l'étudiant %d ===\n", num_etudiant);

    // Lire les 5 notes
    for (int i = 1; i <= 5; i++)
    {
        sprintf(chemin, "../etudiant/%d/note%d.txt", num_etudiant, i);
        notes[i - 1] = lire_note(chemin);
        printf("Note %d: %.2f\n", i, notes[i - 1]);
    }

    // Calculer la somme via le serveur
    somme = envoie_operateur_numeros(socketfd, '+', notes[0], notes[1]);
    somme = envoie_operateur_numeros(socketfd, '+', somme, notes[2]);
    somme = envoie_operateur_numeros(socketfd, '+', somme, notes[3]);
    somme = envoie_operateur_numeros(socketfd, '+', somme, notes[4]);

    printf("Somme totale de l'étudiant %d: %.2f\n", num_etudiant, somme);
    return somme;
}

// Fonction pour calculer la moyenne de la classe
double calculer_moyenne_classe(int socketfd)
{
    double somme_totale = 0;
    double moyennes[5];

    printf("\n=== Calcul de la moyenne de la classe ===\n");

    // Calculer la somme pour chaque étudiant
    for (int i = 1; i <= 5; i++)
    {
        moyennes[i - 1] = calculer_somme_etudiant(socketfd, i);
    }

    // Calculer la somme totale de tous les étudiants
    somme_totale = envoie_operateur_numeros(socketfd, '+', moyennes[0], moyennes[1]);
    somme_totale = envoie_operateur_numeros(socketfd, '+', somme_totale, moyennes[2]);
    somme_totale = envoie_operateur_numeros(socketfd, '+', somme_totale, moyennes[3]);
    somme_totale = envoie_operateur_numeros(socketfd, '+', somme_totale, moyennes[4]);

    printf("\nSomme totale de tous les étudiants: %.2f\n", somme_totale);

    // Calculer la moyenne (diviser par le nombre total de notes: 5 étudiants × 5 notes = 25)
    double moyenne = envoie_operateur_numeros(socketfd, '/', somme_totale, 25.0);

    printf("Moyenne de la classe: %.2f\n", moyenne);
    return moyenne;
}

int main()
{
    struct sockaddr_in server_addr;
    int socketfd;

    // Création du socket
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd < 0)
    {
        perror("Erreur: impossible de créer le socket");
        exit(EXIT_FAILURE);
    }

    // Configuration de l'adresse du serveur
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0)
    {
        perror("Erreur: adresse invalide");
        close(socketfd);
        exit(EXIT_FAILURE);
    }

    // Connexion au serveur
    if (connect(socketfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Erreur: connexion échouée");
        close(socketfd);
        exit(EXIT_FAILURE);
    }

    printf("Connecté au serveur\n");

    // Calculer la moyenne de la classe
    calculer_moyenne_classe(socketfd);

    // Fermer la connexion
    close(socketfd);
    printf("\nConnexion fermée\n");

    return 0;
}