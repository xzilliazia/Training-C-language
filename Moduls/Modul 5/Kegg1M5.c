#include <stdio.h>
#include <string.h>

// Fungsi untuk menukar dua string
void swap(char* a, char* b) {
    char temp[20];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

// Fungsi BubbleSort untuk mengurutkan array string
void BubbleSort(char fruit[][20], int j) {
    int x, y;
    for (x = 0; x < j - 1; x++) {
        for (y = 0; y < j - x - 1; y++) {
            if (strcmp(fruit[y], fruit[y + 1]) > 0) {
                swap(fruit[y], fruit[y + 1]);
            }
        }
    }
}

int main() {
    int u, i;

    printf("Masukkan jumlah buah: ");
    scanf("%d", &u);
    getchar(); // Membersihkan newline dari buffer

    char fruit[u][20]; // Array untuk menyimpan nama buah

    for (i = 0; i < u; i++) {
        printf("Masukkan Nama Buah Ke-%d: ", i + 1);
        fgets(fruit[i], 20, stdin); // Membaca input string dengan spasi
        fruit[i][strcspn(fruit[i], "\n")] = '\0'; // Menghapus karakter newline
    }

    printf("\nSebelum Diurutkan:\n");
    for (i = 0; i < u; i++) {
        printf("%s\n", fruit[i]);
    }

    BubbleSort(fruit, u);

    printf("\nHasil Setelah diurutkan:\n");
    for (i = 0; i < u; i++) {
        printf("%s\n", fruit[i]);
    }

    return 0;
}
