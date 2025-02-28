#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ENTRIES 100
#define MAX_STRING_LENGTH 255

typedef struct {
    char category[MAX_STRING_LENGTH];
    char topic[MAX_STRING_LENGTH];
    char definition[MAX_STRING_LENGTH];
} Entry;

Entry dictionary[MAX_ENTRIES];
int entryCount = 0;

// Fungsi untuk menambah entri ke kamus
void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Kamus penuh, tidak dapat menambah entri baru.\n");
        return;
    }

    printf("Masukkan kategori: ");
    scanf(" %[^\n]", dictionary[entryCount].category);
    printf("Masukkan topik: ");
    scanf(" %[^\n]", dictionary[entryCount].topic);
    printf("Masukkan definisi: ");
    scanf(" %[^\n]", dictionary[entryCount].definition);

    entryCount++;
    printf("Entri berhasil ditambahkan!\n");
}

// Fungsi untuk mencari entri berdasarkan topik
void searchEntry() {
    char searchTopic[MAX_STRING_LENGTH];
    int found = 0;

    printf("Masukkan topik yang ingin dicari: ");
    scanf(" %[^\n]", searchTopic);

    for (int i = 0; i < entryCount; i++) {
        if (strcmp(dictionary[i].topic, searchTopic) == 0) {
            printf("Kategori: %s\n", dictionary[i].category);
            printf("Topik: %s\n", dictionary[i].topic);
            printf("Definisi: %s\n", dictionary[i].definition);
            found = 1;
        }
    }

    if (!found) {
        printf("Topik tidak ditemukan.\n");
    }
}

// Fungsi untuk menampilkan semua entri
void displayAllEntries() {
    if (entryCount == 0) {
        printf("Kamus kosong.\n");
        return;
    }

    for (int i = 0; i < entryCount; i++) {
        printf("Kategori: %s\n", dictionary[i].category);
        printf("Topik: %s\n", dictionary[i].topic);
        printf("Definisi: %s\n\n", dictionary[i].definition);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nKAMUS ELEKTRONIK\n");
        printf("1. Tambah Entri\n");
        printf("2. Cari Entri\n");
        printf("3. Tampilkan Semua Entri\n");
        printf("4. Keluar\n");
        printf("Pilih opsi: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                searchEntry();
                break;
            case 3:
                displayAllEntries();
                break;
            case 4:
                printf("Keluar dari program.\n");
                return 0;
            default:
                printf("Pilihan tidak valid.\n");
        }
    }

    return 0;
}
