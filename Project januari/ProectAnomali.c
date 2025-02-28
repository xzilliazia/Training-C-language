#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LEN 25
#define FILE_PATH "FILE isi\\dataVending.txt"
#define MAX_PRODUCTS 100

typedef struct {
    char name[MAX_STRING_LEN];
    int price;
    int stock;
} Product;

void clearInputBuffer() {
    while (getchar() != '\n');
}

void saveToFile(Product *products, int productCount) {
    FILE *file = fopen(FILE_PATH, "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file for writing\n");
        return;
    }
    for (int i = 0; i < productCount; i++) {
        fprintf(file, "%s %d %d\n", products[i].name, products[i].price, products[i].stock);
    }
    fclose(file);
    printf("Data successfully saved\n");
}

int readFromFile(Product **products) {
    int productCount = 0;
    FILE *file = fopen(FILE_PATH, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file for reading\n");
        return 0;
    }
    Product temp;
    while (fscanf(file, "%s %d %d", temp.name, &temp.price, &temp.stock) != EOF) {
        (*products) = realloc(*products, (productCount + 1) * sizeof(Product));
        if (*products == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            fclose(file);
            return 0;
        }
        (*products)[productCount] = temp;
        productCount++;
    }
    fclose(file);
    return productCount;
}

void showMenu(Product *products, int productCount) {
    printf("\nProduct Menu:\n");
    for (int i = 0; i < productCount; i++) {
        printf("%d. %s - Rp%d (Stock: %d)\n", i + 1, products[i].name, products[i].price, products[i].stock);
    }
    printf("%d. Add Product\n%d. Restock Product\n%d. Exit\n", productCount + 1, productCount + 2, productCount + 3);
}

int inputChoice(int limit) {
    int choice;
    do {
        printf("Enter choice (1-%d): ", limit);
        scanf("%d", &choice);
        clearInputBuffer();
        if (choice < 1 || choice > limit) {
            printf("Invalid choice. Please try again\n");
        }
    } while (choice < 1 || choice > limit);
    return choice;
}

Product *addProduct(Product *products, int *productCount) {
    if (*productCount >= MAX_PRODUCTS) {
        printf("Cannot add more products. Maximum limit reached.\n");
        return products;
    }
    (*productCount)++;
    products = realloc(products, (*productCount) * sizeof(Product));
    if (products == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    printf("Product name: ");
    fgets(products[*productCount - 1].name, MAX_STRING_LEN, stdin);
    products[*productCount - 1].name[strcspn(products[*productCount - 1].name, "\n")] = '\0';
    printf("Product price: ");
    scanf("%d", &products[*productCount - 1].price);
    clearInputBuffer();
    printf("Product stock: ");
    scanf("%d", &products[*productCount - 1].stock);
    clearInputBuffer();
    printf("Product '%s' successfully added\n", products[*productCount - 1].name);
    saveToFile(products, *productCount);
    return products;
}

void restockProduct(Product *products, int productCount) {
    int choice = inputChoice(productCount);
    int addValue;
    printf("Enter additional stock for %s: ", products[choice - 1].name);
    scanf("%d", &addValue);
    clearInputBuffer();
    products[choice - 1].stock += addValue;
    printf("Stock of %s is now %d.\n", products[choice - 1].name, products[choice - 1].stock);
    saveToFile(products, productCount);
}

void buyProduct(Product *products, int productCount) {
    int choice = inputChoice(productCount);
    int money, change;
    if (products[choice - 1].stock == 0) {
        printf("Stock of %s is out.\n", products[choice - 1].name);
        return;
    }
    printf("Price of %s: Rp%d\nEnter money: Rp", products[choice - 1].name, products[choice - 1].price);
    scanf("%d", &money);
    clearInputBuffer();
    if (money >= products[choice - 1].price) {
        change = money - products[choice - 1].price;
        products[choice - 1].stock--;
        printf("Purchase successful! Your change: Rp%d\n", change);
        saveToFile(products, productCount);
    } else {
        printf("Insufficient funds. You are short Rp%d.\n", products[choice - 1].price - money);
    }
}

int main() {
    Product *products = NULL;
    int productCount, choice;
    char continueChoice;

    productCount = readFromFile(&products);

    printf("====== AUTOMATIC VENDING MACHINE ======\n");
    do {
        showMenu(products, productCount);
        choice = inputChoice(productCount + 3);

        if (choice >= 1 && choice <= productCount) {
            buyProduct(products, productCount);
        } else if (choice == productCount + 1) {
            products = addProduct(products, &productCount);
        } else if (choice == productCount + 2) {
            restockProduct(products, productCount);
        } else if (choice == productCount + 3) {
            printf("Thank you for using this machine!\n");
        } else {
            printf("Invalid choice\n");
        }

        if (choice != productCount + 3) {
            printf("\nDo you want to continue (y/n): ");
            scanf(" %c", &continueChoice);
            clearInputBuffer();
        }
    } while (continueChoice == 'y' || continueChoice == 'Y');

    free(products);
    return 0;
}