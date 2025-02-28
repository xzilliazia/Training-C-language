#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char nama[100];
    char nim[20];
    int nilai_tugas;
    int nilai_uts;
    int nilai_uas;
    char nimHasil[20];
    int j = 0;

    printf("````Program penghitung Nilai akhir Mahasiswa````\n");
    
    printf("Masukkan Nama Mahasiswa: ");
    fgets(nama, sizeof(nama), stdin); // Menggunakan fgets

    printf("Masukkan NIM Mahasiswa: ");
    fgets(nim, sizeof(nim), stdin); // Menggunakan fgets
    nim[strcspn(nim, "\n")] = 0; // Menghapus newline

    printf("Masukkan Nilai Tugas: ");
    scanf("%d", &nilai_tugas);

    printf("Masukkan Nilai UTS: ");
    scanf("%d", &nilai_uts);

    printf("Masukkan Nilai UAS: ");
    scanf("%d", &nilai_uas);
    
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    // Proses NIM: Menghilangkan huruf
    int i;
    for ( i = 0; nim[i] != '\0'; i++) {
        if (isdigit(nim[i])) {
            nimHasil[j] = nim[i]; 
            j++;
        }
    }
    nimHasil[j] = '\0';  // Tambahkan null terminator

    // Menampilkan hasil
    printf("Nama Mahasiswa: %s", nama);
    printf("NIM Mahasiswa: %s\n", nimHasil);
    printf("Nilai Tugas: %d\n", nilai_tugas);
    printf("Nilai UTS: %d\n", nilai_uts);
    printf("Nilai UAS: %d\n", nilai_uas);

    float nilaiAkhir;
    nilaiAkhir = 0.2 * nilai_tugas + 0.35 * nilai_uts + 0.45 * nilai_uas;
    printf("Nilai Akhir: %.2f\n", nilaiAkhir);

    printf("-------------------------------------\n");
    return 0;
}
