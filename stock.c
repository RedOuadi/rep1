#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 1
#define MAX_PRODUCTS_PER_CATEGORY 2
#define MAX_NAME_LENGTH 20

void displayMenu();
void displayStock(char stock[][MAX_PRODUCTS_PER_CATEGORY][MAX_NAME_LENGTH], int quantities[][MAX_PRODUCTS_PER_CATEGORY]);
void addProduct(char stock[][MAX_PRODUCTS_PER_CATEGORY][MAX_NAME_LENGTH], int quantities[][MAX_PRODUCTS_PER_CATEGORY]);
void removeProduct(char stock[][MAX_PRODUCTS_PER_CATEGORY][MAX_NAME_LENGTH], int quantities[][MAX_PRODUCTS_PER_CATEGORY]);
void fillStock(char stock[][MAX_PRODUCTS_PER_CATEGORY][MAX_NAME_LENGTH], int quantities[][MAX_PRODUCTS_PER_CATEGORY]);
void exitProgram();

int main() {
    char stock[MAX_CATEGORIES][MAX_PRODUCTS_PER_CATEGORY][MAX_NAME_LENGTH];
    int quantities[MAX_CATEGORIES][MAX_PRODUCTS_PER_CATEGORY];
    for (int i = 0; i < MAX_CATEGORIES; i++) {
        for (int j = 0; j < MAX_PRODUCTS_PER_CATEGORY; j++) {
            stock[i][j][0] = '\0';
            quantities[i][j] = 0;
        }
    }

    int choix;
    do {
        displayMenu();
        printf("Choisissez l'operation desiree : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                fillStock(stock, quantities);
                break;
            case 2:
                addProduct(stock, quantities);
                break;
            case 3:
                removeProduct(stock, quantities);
                break;
            case 4:
                displayStock(stock, quantities);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }

    } while (choix != 5);

    return 0;
}

void displayMenu() {
    printf("\nMenu\n");
    printf("1. Remplir le stock\n");
    printf("2. Ajouter un produit\n");
    printf("3. Retirer un produit\n");
    printf("4. Afficher le stock\n");
    printf("5. Sortir\n");
}

void displayStock(char stock[][MAX_PRODUCTS_PER_CATEGORY][MAX_NAME_LENGTH], int quantities[][MAX_PRODUCTS_PER_CATEGORY]) {
    printf("\nStock:\n");
    for (int i = 0; i < MAX_CATEGORIES; i++) {
        printf("Cat %d:\n", i + 1);
        for (int j = 0; j < MAX_PRODUCTS_PER_CATEGORY; j++) {
            if (stock[i][j][0] != '\0') {
                printf("   %s (Quantite : %d)\n", stock[i][j], quantities[i][j]);
            }
        }
    }
}

void addProduct(char stock[][MAX_PRODUCTS_PER_CATEGORY][MAX_NAME_LENGTH], int quantities[][MAX_PRODUCTS_PER_CATEGORY]) {
    char newProduct[MAX_NAME_LENGTH];
    int code, quantity;

    printf("Entrez le code du nouveau produit : ");
    scanf("%d", &code);

    printf("Entrez le nom du nouveau produit : ");
    scanf("%s", newProduct);

    printf("Entrez la quantite du produit : ");
    scanf("%d", &quantity);
    int category = (code - 1) / MAX_PRODUCTS_PER_CATEGORY;
    int index = (code - 1) % MAX_PRODUCTS_PER_CATEGORY;

    if (code >= 1 && code <= MAX_CATEGORIES * MAX_PRODUCTS_PER_CATEGORY) {
        if (stock[category][index][0] == '\0') {
            strcpy(stock[category][index], newProduct);
            quantities[category][index] = quantity;
            printf("Le produit a ete ajoute avec succes.\n");
        } else {
            quantities[category][index] += quantity;
            printf("La quantite a ete ajoutee au produit existant.\n");
        }
    } else {
        printf("Code invalide. Ajout de produit annule.\n");
    }
}


void removeProduct(char stock[][MAX_PRODUCTS_PER_CATEGORY][MAX_NAME_LENGTH], int quantities[][MAX_PRODUCTS_PER_CATEGORY]) {
    int code, quantity;

    printf("Entrez le code du produit a retirer : ");
    scanf("%d", &code);

    printf("Entrez la quantite du produit a retirer : ");
    scanf("%d", &quantity);
    int category = (code - 1) / MAX_PRODUCTS_PER_CATEGORY;
    int index = (code - 1) % MAX_PRODUCTS_PER_CATEGORY;

    if (code >= 1 && code <= MAX_CATEGORIES * MAX_PRODUCTS_PER_CATEGORY) {
        if (stock[category][index][0] != '\0') {
            if (quantities[category][index] >= quantity) {
                quantities[category][index] -= quantity;
                printf("La quantite a ete retiree du produit avec succes.\n");
            } else {
                printf("Erreur : La quantite a retirer est superieure a la quantite en stock.\n");
            }
        } else {
            printf("Erreur : Le produit avec le code %d n'existe pas.\n", code);
        }
    } else {
        printf("Erreur : Code invalide. Retrait de produit annule.\n");
    }
}
void fillStock(char stock[][MAX_PRODUCTS_PER_CATEGORY][MAX_NAME_LENGTH], int quantities[][MAX_PRODUCTS_PER_CATEGORY]) {
    int code, quantity;

    printf("Remplir le stock :\n");

    for (int i = 0; i < MAX_CATEGORIES; i++) {
        for (int j = 0; j < MAX_PRODUCTS_PER_CATEGORY; j++) {
            int productCode = i * MAX_PRODUCTS_PER_CATEGORY + j + 1;

            printf("Entrez le nom du produit pour la categorie %d, index %d (Code %d) : ", i + 1, j + 1, productCode);
            scanf("%s", stock[i][j]);

            printf("Entrez la quantite du produit : ");
            scanf("%d", &quantity);
            quantities[i][j] = quantity;
        }
    }

    printf("Le stock a ete rempli avec succes.\n");
}



