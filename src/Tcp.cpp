#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <thread>
#include "App.h"

using namespace std;

App *app = nullptr; // Global pointer for App object

void handleFirstClient(int client_sock) {
    char buffer[4096];

    // Receive initial data from the first client
    int read_bytes = recv(client_sock, buffer, sizeof(buffer) - 1, 0);
    if (read_bytes <= 0) {
        perror("Error receiving data from first client");
        close(client_sock);
        return;
    }

    // Initialize the App object with received data
    buffer[read_bytes] = '\0'; // Ensure null termination for string processing
    cout << "Received initial data from first client: " << buffer << endl;
    app = new App(buffer); // Initialize App object with received data

    // Close the client socket after initialization
    close(client_sock);
}

void handleClient(int client_sock) {
    if (!app) {
        cout << "Error: App object not initialized." << endl;
        close(client_sock);
        return;
    }

    char buffer[4096];

    // Receive data from the client
    int read_bytes = recv(client_sock, buffer, sizeof(buffer) - 1, 0);
    if (read_bytes <= 0) {
        perror("Error receiving data");
        close(client_sock);
        return;
    }

    // Process the received data using the initialized App object
    buffer[read_bytes] = '\0'; // Ensure null termination for string processing
    cout << "Received from client: " << buffer << endl;
    string bf(buffer);
    app->setUserInput(bf);
    string bfResult = app->run();
    cout << "Bloom Filter result: " << bfResult << endl;

    // Send back the result to the client
    int sent_bytes = send(client_sock, bfResult.c_str(), bfResult.length(), 0);
    if (sent_bytes < 0) {
        perror("Error sending data to client");
    }

    // Close the client socket
    close(client_sock);
}

int main() {
    const int server_port = 5555;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error creating socket");
        return 1;
    }

    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);

    if (bind(sock, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
        perror("Error binding socket");
        return 1;
    }

    if (listen(sock, 15) < 0) {
        perror("Error listening on socket");
        return 1;
    }

    // Wait for the first client to initialize the App object
    struct sockaddr_in client_sin;
    unsigned int addr_len = sizeof(client_sin);
    int first_client_sock = accept(sock, (struct sockaddr *)&client_sin, &addr_len);
    if (first_client_sock < 0) {
        perror("Error accepting first client");
        close(sock); // Close the main listening socket on error
        return 1;
    }

    // Handle the first client to initialize the App object
    handleFirstClient(first_client_sock);

    // Continue accepting and handling subsequent client connections
    while (true) {
        int client_sock = accept(sock, (struct sockaddr *)&client_sin, &addr_len);
        if (client_sock < 0) {
            perror("Error accepting client");
            continue;
        }

        // Create a new thread to handle each client connection
        thread clientThread(handleClient, client_sock);
        clientThread.detach();
    }

    // Clean up the App object (if initialized)
    if (app) {
        delete app;
    }

    // Close the main listening socket
    close(sock);

    return 0;
}