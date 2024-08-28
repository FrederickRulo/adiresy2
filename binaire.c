#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Prototypes */
void convert_to_binary(char *ip);
void print_binary(int octet);

int main() {
    char *data;
    char ip[16];

    // En-tête HTTP pour le navigateur
    printf("Content-Type: text/html\n\n");

    // Récupération de l'adresse IP depuis la requête (QUERY_STRING)
    data = getenv("QUERY_STRING");
    if (data != NULL) {
        sscanf(data, "ip=%15s", ip);  // Extraction de l'adresse IP
        printf("<!DOCTYPE html>\n");
        printf("<html lang=\"fr\">\n");
        printf("<head>\n");
        printf("<meta charset=\"UTF-8\">\n");
        printf("<title>Résultat de la conversion</title>\n");
        printf("<style>\n");
        printf("body { font-family: Arial, sans-serif; background-color: #f0f0f0; padding: 20px; }\n");
        printf(".container { background-color: #fff; padding: 20px; border-radius: 10px; box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.1); }\n");
        printf("h1 { color: #333; }\n");
        printf("</style>\n");
        printf("</head>\n");
        printf("<body>\n");
        printf("<div class=\"container\">\n");
        printf("<h1>Adresse IP : %s</h1>\n", ip);

        // Appel de la fonction pour convertir en binaire et afficher
        printf("<h2>Adresse IP en binaire :</h2>\n");
        convert_to_binary(ip);
        printf("</div>\n");
        printf("</body>\n");
        printf("</html>\n");
    } else {
        printf("<p>Aucune adresse IP fournie.</p>\n");
    }

    return 0;
}

// Fonction qui convertit chaque octet de l'adresse IP en binaire
void convert_to_binary(char *ip) {
    int octet;
    char *token = strtok(ip, ".");  // Séparer l'IP en octets

    while (token != NULL) {
        octet = atoi(token);  // Convertir chaque segment en entier
        print_binary(octet);  // Afficher en binaire
        token = strtok(NULL, ".");  // Passer au segment suivant
    }
}

// Fonction qui imprime un octet en binaire
void print_binary(int octet) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (octet >> i) & 1);  // Affichage bit par bit
    }
    printf(" ");  // Espace entre les octets
}