#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h> // Include conio.h for getch()
#include <windows.h> // Include windows.h for color functions

#define MAX_MENU 10
#define FILE_NAME "menu.txt" // Nama file untuk menyimpan data menu

// Defining the Menu structure using typedef
typedef struct {
    char name[30];
    int stock;
    float price;
} Menu;

// Global variables
Menu menuList[MAX_MENU];
int menuCount = 0; // Current number of menu items
int cursor = 0;    // Cursor position
int prevCursor = 0; // Variabel untuk menyimpan posisi kursor sebelumnya
float totalPrice = 0; // Total price for payment

// Function prototypes
void displayMenu();
void controlCursor();
void selectMenu();
void addMenu();
void restockProduct();
void deleteMenu();
void processPayment();
void setColor(int textColor, int bgColor); // Function to set text color
void loadMenuFromFile();
void saveMenuToFile();
void buyProduct();
void confirmBackToMainMenu();

int main() {
    loadMenuFromFile(); // Load menu from file at the beginning

    while (1) {
        system("cls"); // Clear screen
        displayMenu(); // Display menu
        controlCursor(); // Control cursor movement
    }
    return 0;
}

void setColor(int textColor, int bgColor) {
    // Set the text and background color
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
}

void displayMenu() {
    printf("Daftar Produk:\n");
    for (int i = 0; i < menuCount; i++) {
        if (cursor == i) {
            setColor(15, 1); // Highlight selected menu
            printf("> %d. %s (Stok: %d) - Harga: %.2f\n", i + 1, menuList[i].name, menuList[i].stock, menuList[i].price);
        } else {
            setColor(7, 0); // Default color
            printf("  %d. %s (Stok: %d) - Harga: %.2f\n", i + 1, menuList[i].name, menuList[i].stock, menuList[i].price);
        }
    }

    printf("--------------------------\n");

    // Display "Lainnya" options
    char *options[] = {"Tambah Produk", "Restok Produk", "Hapus Produk", "Pembayaran", "Keluar"};
    for (int i = 0; i < 5; i++) {
        if (cursor == menuCount + i) {
            setColor(15, 1); // Highlight selected option
            printf("> %s\n", options[i]);
        } else {
            setColor(7, 0); // Default color
            printf("  %s\n", options[i]);
        }
    }
    setColor(7, 0); // Reset color
}

void controlCursor() {
    int ch = getch(); // Read user input without waiting for Enter
    
    // Menggunakan nilai ASCII untuk tombol kontrol
    if (ch == 's' || ch == 'S') { // Tombol S atau s untuk bergerak ke bawah
        prevCursor = cursor; // Simpan posisi kursor sebelumnya
        cursor = (cursor + 1) % (menuCount + 5); // Loop around options
    } else if (ch == 'w' || ch == 'W') { // Tombol W atau w untuk bergerak ke atas
        prevCursor = cursor; // Simpan posisi kursor sebelumnya
        cursor = (cursor - 1 + (menuCount + 5)) % (menuCount + 5); // Loop around options
    } else if (ch == 'a' || ch == 'A') { // Tombol A atau a untuk bergerak ke kiri
        prevCursor = cursor; // Simpan posisi kursor sebelumnya
        cursor = (cursor - 1 + (menuCount + 5)) % (menuCount + 5); // Bergerak ke kiri
    } else if (ch == 'd' || ch == 'D') { // Tombol D atau d untuk bergerak ke kanan
        prevCursor = cursor; // Simpan posisi kursor sebelumnya
        cursor = (cursor + 1) % (menuCount + 5); // Bergerak ke kanan
    } else if (ch == 13) { // Tombol Enter (ASCII 13)
        selectMenu();
    } else if (ch == 27) { // Tombol Esc (ASCII 27) untuk kembali ke posisi sebelumnya
        cursor = prevCursor; // Kembali ke posisi kursor sebelumnya
    }
}

void selectMenu() {
    system("cls"); // Clear screen

    if (cursor < menuCount) { // If selecting a food item
        buyProduct();
    } else if (cursor == menuCount) { // Add new menu
        addMenu();
    } else if (cursor == menuCount + 1) { // Restock product
        restockProduct();
    } else if (cursor == menuCount + 2) { // Delete product
        deleteMenu();
    } else if (cursor == menuCount + 3) { // Process payment
        processPayment();
    } else if (cursor == menuCount + 4) { // Exit
        printf("Terima kasih telah menggunakan program ini!\n");
        saveMenuToFile(); // Save menu before exiting
        exit(0);
    } else {
        printf("Pilihan tidak valid!\n");
    }

    printf("\nTekan tombol apa saja untuk kembali ke menu utama...");
    getch(); // Wait for user input
}

void buyProduct() {
    int quantity;
    printf("Masukkan jumlah produk yang ingin dibeli: ");
    scanf("%d", &quantity);

    if (quantity <= 0) {
        printf("Jumlah produk tidak valid!\n");
        getch();
        return;
    }

    if (menuList[cursor].stock >= quantity) {
        menuList[cursor].stock -= quantity;
        totalPrice += menuList[cursor].price * quantity;
        printf("Anda membeli %d %s. Total harga: %.2f\n", quantity, menuList[cursor].name, menuList[cursor].price * quantity);
    } else {
        printf("Stok tidak cukup untuk membeli %d %s.\n", quantity, menuList[cursor].name);
    }

    confirmBackToMainMenu();
}

void confirmBackToMainMenu() {
    char ch;
    printf("Apakah Anda ingin Kembali ke Menu utama (Y/N)? ");
    scanf(" %c", &ch); // Notice the space before %c to handle newline character

    if (ch == 'Y' || ch == 'y') {
        // Jika Y, kembali ke menu utama
        return;
    } else if (ch == 'N' || ch == 'n') {
        // Jika N, langsung ke pembayaran
        processPayment();
    } else {
        printf("Pilihan tidak valid!\n");
        getch();
    }
}

void processPayment() {
    if (totalPrice == 0) {
        printf("Tidak ada item yang dibeli.\n");
        return;
    }

    printf("Total belanja Anda: %.2f\n", totalPrice);

    float payment;
    printf("Masukkan jumlah uang yang dibayarkan: ");
    scanf("%f", &payment);

    if (payment >= totalPrice) {
        printf("Pembayaran berhasil! Kembalian Anda: %.2f\n", payment - totalPrice);
        totalPrice = 0; // Reset total price after payment
    } else {
        printf("Uang Anda tidak cukup. Silakan coba lagi.\n");
    }

    getch();
}

void addMenu() {
    if (menuCount >= MAX_MENU) { // Adjust for additional options
        printf("Menu sudah penuh, tidak bisa menambah menu baru!\n");
        getch();
        return;
    }

    char newName[30];
    int newStock;
    float newPrice; // Variable for new price

    printf("Masukkan nama menu baru: ");
    scanf(" %[^\n]", newName);
    printf("Masukkan jumlah stok: ");
    scanf("%d", &newStock);
    printf("Masukkan harga: ");
    scanf("%f", &newPrice); // Input for new price

    // Add new menu item at the end of the list
    strcpy(menuList[menuCount].name, newName);
    menuList[menuCount].stock = newStock;
    menuList[menuCount].price = newPrice;

    menuCount++;
    printf("Menu baru berhasil ditambahkan!\n");
    saveMenuToFile(); // Save menu to file
    getch();
}

void restockProduct() {
    printf("Restok menu: \n");
    for (int i = 0; i < menuCount; i++) {
        printf("%d. %s (Stok: %d) - Harga: %.2f\n", i + 1, menuList[i].name, menuList[i].stock, menuList[i].price);
    }

    int choice, amount;
    printf("Pilih menu untuk di-restok (1-%d): ", menuCount);
    scanf("%d", &choice);

    if (choice < 1 || choice > menuCount) {
        printf("Pilihan tidak valid!\n");
        getch();
        return;
    }

    printf("Masukkan jumlah stok yang ingin ditambahkan: ");
    scanf("%d", &amount);
    menuList[choice - 1].stock += amount;

    printf("Stok %s berhasil di-restok!\n", menuList[choice - 1].name);
    saveMenuToFile(); // Save menu to file
    getch();
}

void deleteMenu() {
    printf("Hapus menu: \n");
    for (int i = 0; i < menuCount; i++) {
        printf("%d. %s (Stok: %d) - Harga: %.2f\n", i + 1, menuList[i].name, menuList[i].stock, menuList[i].price);
    }

    int choice;
    printf("Pilih menu untuk dihapus (1-%d): ", menuCount);
    scanf("%d", &choice);

    if (choice < 1 || choice > menuCount) {
        printf("Pilihan tidak valid!\n");
        getch();
        return;
    }

    // Shift the menu items to delete the selected item
    for (int i = choice - 1; i < menuCount - 1; i++) {
        menuList[i] = menuList[i + 1];
    }

    menuCount--; // Decrease the menu count
    saveMenuToFile(); // Save menu to file after deletion
    printf("Menu berhasil dihapus!\n");
    getch();
}

void loadMenuFromFile() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file != NULL) {
        while (fscanf(file, " %[^\n],%d,%f\n", menuList[menuCount].name, &menuList[menuCount].stock, &menuList[menuCount].price) == 3) {
            menuCount++;
        }
        fclose(file);
    }
}

void saveMenuToFile() {
    FILE *file = fopen(FILE_NAME, "w");
    if (file != NULL) {
        for (int i = 0; i < menuCount; i++) {
            fprintf(file, "%s,%d,%.2f\n", menuList[i].name, menuList[i].stock, menuList[i].price);
        }
        fclose(file);
    }
}
