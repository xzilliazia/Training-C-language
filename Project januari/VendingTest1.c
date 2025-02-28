#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING_LEN 25
#define FILE_PATH "projek_data.txt"

typedef struct {
    char name[MAX_STRING_LEN];
    int price;
    int stock;
} Product;

void showMenu(Product *products, int productCount, int selected) {
    system("cls"); // Membersihkan layar
    printf("====== AUTOMATIC VENDING MACHINE ======\n");
    for (int i = 0; i < productCount; i++) {
        if (i == selected) {
            printf("-> ");
        } else {
            printf("   ");
        }
        printf("%d. %s - Rp%d (Stock: %d)\n", i + 1, products[i].name, products[i].price, products[i].stock);
    }
    printf("\nUse W/S to navigate, Enter to select, Q to quit.\n");
}

int main() {
    Product products[] = {
        {"Coca-Cola", 5000, 10},
        {"Pepsi", 5000, 10},
        {"Sprite", 5000, 10}
    };
    int productCount = sizeof(products) / sizeof(products[0]);
    int selected = 0;
    char choice;

    do {
        showMenu(products, productCount, selected);
        choice = getchar(); // Membaca input tombol

        if (choice == 'w' || choice == 'W') {
            if (selected > 0) {
                selected--;
            }
        } else if (choice == 's' || choice == 'S') {
            if (selected < productCount - 1) {
                selected++;
            }
        } else if (choice == '\r') { // Enter
            if (products[selected].stock > 0) {
                printf("You selected: %s\n", products[selected].name);
                printf("Price: Rp%d\n", products[selected].price);
                printf("Enter amount: ");
                int amount;
                scanf("%d", &amount);

                if (amount >= products[selected].price) {
                    int change = amount - products[selected].price;
                    printf("Purchase successful. Your change: Rp%d\n", change);
                    products[selected].stock--;
                } else {
                    printf("Insufficient funds. Transaction cancelled.\n");
                }
            } else {
                printf("Product out of stock.\n");
            }
            getchar(); // Menunggu input sebelum melanjutkan
        } else if (choice == 'q' || choice == 'Q') {
            printf("Exiting...\n");
            break;
        }
    } while (1);

    return 0;
}
