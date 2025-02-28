#include <stdio.h>
#include <string.h>

int main() {
    char karakter[20], hasil[20];
    int ch = 0, j = 0;

    // Meminta input dari pengguna
    printf("Masukkan Kalimat atau Kata: ");
    fgets(karakter, sizeof(karakter), stdin);

    // Menghapus karakter newline dari fgets
    karakter[strcspn(karakter, "\n")] = '\0';

    // Memeriksa setiap karakter dalam string
    for (ch = 0; ch < strlen(karakter); ch++) {
        // Gunakan strchr untuk memeriksa apakah karakter sudah ada di 'hasil'
        if (strchr(hasil, karakter[ch]) != NULL) {
            continue;  // Jika karakter ditemukan, lompat ke karakter berikutnya
        }

        // Menyimpan karakter ke 'hasil' dan mencetaknya
        hasil[j++] = karakter[ch];
        printf("%c ", karakter[ch]);
    }

    printf("\n");

    return 0;
}
