#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "serveur.h"

int socketfd;

int envoie_recois_message(int client_socket_fd)
{
    char data[BUF_SIZE];
    memset(data, 0, sizeof(data));

    // Recevoir le message du client
    int valread = read(client_socket_fd, data, BUF_SIZE);
    if (valread <= 0)
    {
        return -1;
    }

    printf("Message reçu: %s\n", data);

    // Parser le message: "operateur nombre1 nombre2"
    char operateur;
    double num1, num2, resultat = 0;
    
    if (sscanf(data, "%c %lf %lf", &operateur, &num1, &num2) == 3)
    {
        switch (operateur)
        {
            case '+':
                resultat = num1 + num2;
                break;
            case '-':
                resultat = num1 - num2;
                break;
            case '*':
                resultat = num1 * num2;
                break;
            case '/':
                if (num2 != 0)
                    resultat = num1 / num2;
                else
                {
                    strcpy(data, "Erreur: division par zéro");
                    write(client_socket_fd, data, strlen(data));
                    return 0;
                }
                break;
            default:
                strcpy(data, "Erreur: opérateur inconnu");
                write(client_socket_fd, data, strlen(data));
                return 0;
        }

        // Envoyer le résultat au client
        sprintf(data, "%.2f", resultat);
        printf("Résultat envoyé: %s\n", data);
        write(client_socket_fd, data, strlen(data));
    }
    else
    {
        strcpy(data, "Erreur: format de message invalide");
        write(client_socket_fd, data, strlen(data));
    }

    return 0;
}

int main()
{
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    // Création du socket
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd < 0)
    {
        perror("Erreur: impossible de créer le socket");
        exit(EXIT_FAILURE);
    }

    // Option pour réutiliser l'adresse
    int opt = 1;
    setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // Configuration de l'adresse du serveur
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind
    if (bind(socketfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Erreur: bind échoué");
        close(socketfd);
        exit(EXIT_FAILURE);
    }

    // Listen
    if (listen(socketfd, 5) < 0)
    {
        perror("Erreur: listen échoué");
        close(socketfd);
        exit(EXIT_FAILURE);
    }

    printf("Serveur en écoute sur le port %d...\n", PORT);

    // Boucle infinie pour accepter les connexions
    while (1)
    {
        int client_socket_fd = accept(socketfd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket_fd < 0)
        {
            perror("Erreur: accept échoué");
            continue;
        }

        printf("Client connecté\n");

        // Boucle pour traiter plusieurs messages du même client
        while (envoie_recois_message(client_socket_fd) == 0)
        {
            // Continue à recevoir des messages
        }

        printf("Client déconnecté\n");
        close(client_socket_fd);
    }

    close(socketfd);
    return 0;
}