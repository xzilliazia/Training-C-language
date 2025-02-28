#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

#define MAX_ENTRIES 100
#define MAX_STRING_LENGTH 255
#define FILE_PATH "File isi\\prime_data.txt"  // Definisikan path file di sini

// Struktur untuk menyimpan entri
typedef struct {
    char category[MAX_STRING_LENGTH];
    char topic[MAX_STRING_LENGTH];
    char definition[MAX_STRING_LENGTH];
} Entry;

// Array untuk menyimpan entri kamus
Entry dictionary[MAX_ENTRIES];
int entryCount = 0;

// Check if the file exists
int fileExists(const char *filename) {
    struct stat buffer;
    return (stat(filename, &buffer) == 0);  // Returns 1 if file exists, 0 if it doesn't
}

// Function to load data from the file
int loadFromFile(Entry dictionary[], const char *filename) {
    if (!fileExists(filename)) {  // Check if the file exists
        printf("File tidak ditemukan. Membuat kamus baru.\n");
        return 0;  // No data to load if file doesn't exist
    }

    FILE *file = fopen(filename, "r");  // Open for reading only
    if (!file) {
        printf("Gagal membuka file untuk membaca.\n");
        return 0;
    }

    int entryCount = 0;
    // Read data from the file
    while (fscanf(file, " %49[^|]|%49[^|]|%254[^\n]\n", 
                  dictionary[entryCount].category, 
                  dictionary[entryCount].topic, 
                  dictionary[entryCount].definition) == 3) {
        entryCount++;
    }

    fclose(file);
    printf("Data berhasil dimuat dari file: %s\n", filename);
    return entryCount;
}

// Function to save data to the file
void saveToFile(Entry dictionary[], int entryCount, const char *filename) {
    // Open file in "r+" mode (read/write)
    FILE *file = fopen(filename, "r+");
    if (!file) {
        printf("File tidak ditemukan, membuat file baru.\n");

        // If the file doesn't exist, create it with "w+" mode
        file = fopen(filename, "w+");
        if (!file) {
            printf("Gagal membuka file untuk menulis.\n");
            return;
        }
    }

    // Move to the end of the file
    fseek(file, 0, SEEK_END);

    // Save all entries to the file
    for (int i = 0; i < entryCount; i++) {
        fprintf(file, "%s|%s|%s\n", dictionary[i].category, dictionary[i].topic, dictionary[i].definition);
    }

    fclose(file);
    printf("Data berhasil disimpan ke file: %s\n", filename);
}

// Function to display all entries
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

// Function to add a new entry
void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Kamus sudah penuh.\n");
        return;
    }

    printf("Masukkan kategori: ");
    fgets(dictionary[entryCount].category, MAX_STRING_LENGTH, stdin);
    dictionary[entryCount].category[strcspn(dictionary[entryCount].category, "\n")] = '\0'; // Menghapus newline

    printf("Masukkan topik: ");
    fgets(dictionary[entryCount].topic, MAX_STRING_LENGTH, stdin);
    dictionary[entryCount].topic[strcspn(dictionary[entryCount].topic, "\n")] = '\0'; // Menghapus newline

    printf("Masukkan definisi: ");
    fgets(dictionary[entryCount].definition, MAX_STRING_LENGTH, stdin);
    dictionary[entryCount].definition[strcspn(dictionary[entryCount].definition, "\n")] = '\0'; // Menghapus newline

    entryCount++;
    printf("Entri berhasil ditambahkan.\n");
}

// Function to search for an entry by category or topic
void searchEntry() {
    char searchTerm[MAX_STRING_LENGTH];
    printf("Masukkan kategori atau topik yang ingin dicari: ");
    fgets(searchTerm, MAX_STRING_LENGTH, stdin);
    searchTerm[strcspn(searchTerm, "\n")] = '\0'; // Menghapus newline

    int found = 0;
    for (int i = 0; i < entryCount; i++) {
        if (strstr(dictionary[i].category, searchTerm) || strstr(dictionary[i].topic, searchTerm)) {
            printf("Kategori: %s\n", dictionary[i].category);
            printf("Topik: %s\n", dictionary[i].topic);
            printf("Definisi: %s\n\n", dictionary[i].definition);
            found = 1;
        }
    }

    if (!found) {
        printf("Tidak ditemukan entri yang cocok.\n");
    }
}

// Function to update an entry by topic
void updateEntry() {
    char searchTerm[MAX_STRING_LENGTH];
    printf("Masukkan topik yang ingin diupdate: ");
    fgets(searchTerm, MAX_STRING_LENGTH, stdin);
    searchTerm[strcspn(searchTerm, "\n")] = '\0'; // Menghapus newline

    int found = 0;
    for (int i = 0; i < entryCount; i++) {
        if (strstr(dictionary[i].topic, searchTerm)) {
            found = 1;
            printf("Entri ditemukan!\n");
            printf("Kategori: %s\n", dictionary[i].category);
            printf("Topik: %s\n", dictionary[i].topic);
            printf("Definisi: %s\n\n", dictionary[i].definition);

            printf("Masukkan kategori baru: ");
            fgets(dictionary[i].category, MAX_STRING_LENGTH, stdin);
            dictionary[i].category[strcspn(dictionary[i].category, "\n")] = '\0'; // Menghapus newline

            printf("Masukkan topik baru: ");
            fgets(dictionary[i].topic, MAX_STRING_LENGTH, stdin);
            dictionary[i].topic[strcspn(dictionary[i].topic, "\n")] = '\0'; // Menghapus newline

            printf("Masukkan definisi baru: ");
            fgets(dictionary[i].definition, MAX_STRING_LENGTH, stdin);
            dictionary[i].definition[strcspn(dictionary[i].definition, "\n")] = '\0'; // Menghapus newline

            printf("Entri berhasil diupdate.\n");
            break;
        }
    }

    if (!found) {
        printf("Topik tidak ditemukan.\n");
    }
}

// Function to delete an entry by topic
void deleteEntry() {
    char searchTerm[MAX_STRING_LENGTH];
    printf("Masukkan topik yang ingin dihapus: ");
    fgets(searchTerm, MAX_STRING_LENGTH, stdin);
    searchTerm[strcspn(searchTerm, "\n")] = '\0'; // Menghapus newline

    int found = 0;
    for (int i = 0; i < entryCount; i++) {
        if (strstr(dictionary[i].topic, searchTerm)) {
            found = 1;
            printf("Entri ditemukan dan akan dihapus!\n");
            printf("Kategori: %s\n", dictionary[i].category);
            printf("Topik: %s\n", dictionary[i].topic);
            printf("Definisi: %s\n\n", dictionary[i].definition);

            // Shift entries to the left
            for (int j = i; j < entryCount - 1; j++) {
                dictionary[j] = dictionary[j + 1];
            }
            entryCount--;
            printf("Entri berhasil dihapus.\n");
            break;
        }
    }

    if (!found) {
        printf("Topik tidak ditemukan.\n");
    }
}

int main() {
    // Load data from file at the start of the program
    entryCount = loadFromFile(dictionary, FILE_PATH);

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Tampilkan semua entri\n");
        printf("2. Tambah entri\n");
        printf("3. Cari entri\n");
        printf("4. Update entri\n");
        printf("5. Hapus entri\n");
        printf("6. Simpan data ke file\n");
        printf("0. Keluar\n");
        printf("Pilih opsi: ");
        scanf("%d", &choice);
        getchar();  // To capture newline after number input

        switch (choice) {
            case 1:
                displayAllEntries();
                break;
            case 2:
                addEntry();
                break;
            case 3:
                searchEntry();
                break;
            case 4:
                updateEntry();
                break;
            case 5:
                deleteEntry();
                break;
            case 6:
                saveToFile(dictionary, entryCount, FILE_PATH); // Save with FILE_PATH
                break;
            case 0:
                printf("Keluar program...\n");
                break;
            default:
                printf("Opsi tidak valid.\n");
        }
    } while (choice != 0);

    return 0;
}
