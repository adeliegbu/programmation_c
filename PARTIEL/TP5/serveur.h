#ifndef SERVEUR_H
#define SERVEUR_H

#define PORT 8080
#define BUF_SIZE 1024

int envoie_recois_message(int client_socket_fd);

#endif