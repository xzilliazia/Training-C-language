#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char nama[100];
    char nim[20];  // Ubah nim menjadi array string
    int nilai_tugas;
    int nilai_uts;
    int nilai_uas;

    printf("Masukkan Nama Mahasiswa: ");
    fgets(nama, sizeof(nama), stdin); // Menggunakan fgets untuk input nama

    // Input NIM dengan validasi
    while (1) {
        printf("Masukkan NIM Mahasiswa: ");
        fgets(nim, sizeof(nim), stdin);

        // Hapus newline di akhir input
        nim[strcspn(nim, "\n")] = 0;

        // Validasi NIM hanya mengandung digit
        int valid = 1; // Flag untuk menandakan validitas
        for (int i = 0; i < strlen(nim); i++) {
            if (!isdigit(nim[i])) {
                valid = 0;
                break;
            }
        }

        if (valid) {
            break; // Keluar dari loop jika valid
        } else {
            printf("NIM harus berupa angka. Silakan coba lagi.\n");
        }
    }

    // Mengkonversi nim ke long long int
    long long int nimLong = atoll(nim);

    printf("Masukkan Nilai Tugas: ");
    scanf("%d", &nilai_tugas);
    printf("Masukkan Nilai UTS: ");
    scanf("%d", &nilai_uts);
    printf("Masukkan Nilai UAS: ");
    scanf("%d", &nilai_uas);

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Nama Mahasiswa: %s", nama);
    printf("NIM Mahasiswa: %lld\n", nimLong);
    printf("Nilai Tugas: %d\n", nilai_tugas);
    printf("Nilai UTS: %d\n", nilai_uts);
    printf("Nilai UAS: %d\n", nilai_uas);

    float nilaiAkhir;
    nilaiAkhir = 0.2 * nilai_tugas + 0.35 * nilai_uts + 0.45 * nilai_uas;
    printf("Nilai Akhir: %.2f\n", nilaiAkhir);

    return 0;
}
