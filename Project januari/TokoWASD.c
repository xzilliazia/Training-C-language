#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#define MAX_MENU 25
#define FILE_PATH "FILE isi\\dataVending2.txt"

typedef struct {
    char name[30];
    float price;
    int stock;
} Menu;

//global
Menu menuList[MAX_MENU];
int menuCount =0;
int cursor = 0;
float totalPrice =0;
int prevCursor = 0;

//function prototype
void showMenu();
void controlCursor();
void selectMenu();
void addMenu();
void restokMenu();
void payment();
void deleteMenu();
void setColor(int textColor, int bgColor);
void loadFile();
void saveMenuToFile();
void buying();
void backtomainmenu();

int main (){
    loadFile();

    while (1) {
        system("cls");
        showMenu();
        controlCursor();
    } return 0;
}

void setColor(int textColor, int bgColor){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
}

void showMenu(){
    printf("VENDING MACHINE BANG JAYA\n");
    printf("========================\n\n");

    for (int i=0;i<menuCount;i++){
        if (cursor == 1){
            setColor(15, 1);
            printf("%d. %s (Stok: %d) - Harga: %.2f\n", i + 1, menuList[i].name, menuList[i].stock, menuList[i].price);
        } else {
            setColor(7, 0);
            printf("%d. %s (Stok: %d) - Harga: %.2f\n", i + 1, menuList[i].name, menuList[i].stock, menuList[i].price);
        }
    }
    char *options[] = {"Tambah Produk", "Restok Produk", "Hapus Produk", "Pembayaran", "Keluar"};
    for (int i =0; i<5;i++){
        if (cursor == menuCount + i) {
            setColor(17, 2); 
            printf(" %s\n", options[i]);
        } else {
            setColor(7, 0);
            printf("%s\n", options[i]);
        }
    }
    setColor(7, 0);
}

void controlCursor(){
    char ch = getch();

    if (ch  == 's' || ch == 'S'){ //kebawah
        prevCursor = cursor;
        cursor = (cursor + 1) % (menuCount + 5);
    } else if (ch == 'w' || ch == 'W'){ //keatas
        prevCursor = cursor;
        cursor = (cursor-1 + (menuCount + 5)) % (menuCount + 5);
    } else if (ch == 'a' || ch == 'A'){ //kiri
        prevCursor = cursor;
        cursor = (cursor - 1 + (menuCount + 5)) % (menuCount + 5);
    } else if (ch == 'd' || ch == 'D'){ //kanan
        prevCursor = cursor;
        cursor = (cursor + 1) % (menuCount + 5);
    } else if (ch == 13){ //enter
        selectMenu();
    } else if (ch == 27){ //esc
        cursor = prevCursor;
    }
}

void selectMenu(){
    system("cls");

    if (cursor < menuCount) {
        buying();
    } else if (cursor == menuCount){
        addMenu();
    } else if (cursor == menuCount + 1){
        restokMenu();
    } else if (cursor == menuCount + 2){
        deleteMenu();
    } else if (cursor == menuCount + 3){
        payment();
    } else if (cursor == menuCount + 4){
        printf("Terimakasih Telah menggunakan progam ini!\n");
        saveMenuToFile();
        exit(0);
    } else {
        printf("Pilihan invalid\n");
    }

    printf("Tekan tombol apa saja untuk kembali ke Menu utama...");
    getch();
}

void buying(){
    int quantity;
    printf("Masukkan jumlah produk yang ingin dibeli: ");
    scanf("%d", &quantity); getchar();

    if (quantity <= 0) {
        printf("Jumlah Produk tidak valid!\n");
        getch();
        return;
    }

    if (menuList[cursor].stock >= quantity){
        menuList[cursor].stock -= quantity;
        totalPrice += menuList[cursor].price * quantity;
        printf("Anda Membeli %d %s. Total Harga: %.2f\n", quantity, menuList[cursor].name, menuList[cursor].price * quantity);
    } else {
        printf("Stok tidak mencukupi\n");
    }
    backtomainmenu();
}

void backtomainmenu(){
    char ch;
    printf("Apakah anda ingin kembali ke Menu utama (Y/N)?");
    scanf("%c", &ch);

    if (ch == 'Y' || ch == 'y') {
        return;
    } else if (ch == 'N' || ch == 'n'){
        payment();
    } else {
        printf("Pilihan Invalid\n");
        getch();
    }
}

void payment(){
    if (totalPrice == 0){
        printf("Tidak ada item yg dibeli\n");
        return;
    }

    printf("Total belanja anda: %.2f\n", totalPrice);

    float pay;
    printf("Masukkan Jumlah Uang anda: ");
    scanf("%f", &pay);

    if (pay >= totalPrice){
        printf("Pembayaran Berhasil! Kembalian Anda: %.2f\n", pay - totalPrice);
        totalPrice = 0;
    } else {
        printf("Uang anda Tidak cukup\n");
    }
    getch();
}

void addMenu(){
    if (menuCount >= MAX_MENU){
        printf("Menu sudah penuh, tidak bisa menambah menu baru lagi\n");
        getch();
        return;
    }

    char newName[30];
    int newStok;
    float newPrice;

    printf("Masukkan Nama Produk Baru:");
    scanf("%[^\n]", newName);
    printf("Masukkan Jumlah stok: ");
    scanf("%d", &newStok);
    printf("Masukkan Harga: ");
    scanf("%f", &newPrice);

    strcpy(menuList[menuCount].name, newName);
    menuList[menuCount].stock = newStok;
    menuList[menuCount].price = newPrice;

    menuCount++;
    printf("Menu baru Berhasil Ditambahkan!\n");
    saveMenuToFile();
    getch();
}

void restokMenu(){
    printf("Restok Menu:\n");
    for (int i = 0;i < menuCount;i++){
        printf("%d. %s (Stok: %d) - Harga %.2f\n", i+1, menuList[i].name, menuList[i].stock, menuList[i].price);
    }

    int choise, amount;
    printf("Pilih menu yang ingin di Restok(1-%d):", menuCount);
    scanf("%d", &choise);

    if (choise < 1 || choise > menuCount){
        printf("Pilihan Invalid\n");
        getch();
        return;
    }

    printf("Masukkan Jumlah Stok yang inign ditambahkan: ");
    scanf("%d", &amount);
    menuList[choise - 1].stock += amount;

    printf("Stok %s berhasil di-restok\n", menuList[choise-1].name);
    saveMenuToFile();
    getch();
}

void deleteMenu(){
    for (int i = 0;i < menuCount;i++){
        printf("%d. %s (Stok: %d) - Harga %.2f\n", i+1, menuList[i].name, menuList[i].stock, menuList[i].price);
    }
    int choise;
    printf("Pilih menu yang ingin dihapus (1-%d):", menuCount);
    scanf("%d", &choise);

    if (choise < 1 || choise > menuCount){
        printf("Pilihan Invalid\n");
        getch();
        return;
    }
    for (int i=choise-1;i<menuCount-1;i++){
        menuList[i] = menuList[i+1];
    }
    menuCount--;
    saveMenuToFile();
    printf("Menu Berhasil dihapus!\n");
    getch();
}

void loadFile(){
    FILE *file = fopen(FILE_PATH, "r");
    if (file != NULL){
        while (fscanf(file, " %[^\n],%d,%f\n", menuList[menuCount].name, &menuList[menuCount].stock, &menuList[menuCount].price)==3){
            menuCount++;
        }
        fclose(file);
    }
}

void saveMenuToFile(){
    FILE *file = fopen(FILE_PATH, "a");
    if (file != NULL){
        for (int i=0;i<menuCount;i++){
        fprintf(file, "%s,%d,%.2f\n", menuList[i].name, &menuList[i].stock, &menuList[i].price);
            menuCount++;
        }
        fclose(file);
    }
}