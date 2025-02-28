#include <stdio.h>

int main()
{
    char nama[100];
    unsigned int nim;
    int nilai_tugas;
    int nilai_uts;
    int nilai_uas;

    printf("Masukkan Nama Mahasiswa: ");
    fgets(nama, sizeof(nama), stdin); // Menggunakan fgets untuk input nama

    printf("Masukkan Nim Mahasiswa: ");
    scanf("%u", &nim);

    printf("Masukkan Nilai Tugas: ");
    scanf("%d", &nilai_tugas);

    printf("Masukkan Nilai UTS: ");
    scanf("%d", &nilai_uts);

    printf("Masukkan Nilai UAS: ");
    scanf("%d", &nilai_uas);
    
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    printf("Nama Mahasiswa: %s", nama); // Tidak perlu newline karena fgets sudah menyertakan newline
    printf("NIM Mahasiswa: %u\n", nim);
    printf("Nilai Tugas: %d\n", nilai_tugas);
    printf("Nilai UTS: %d\n", nilai_uts);
    printf("Nilai UAS: %d\n", nilai_uas);
	
	float nilaiAkhir;
	nilaiAkhir = 0.2 * nilai_tugas + 0.35 * nilai_uts + 0.45 * nilai_uas;
	printf("Nilai Akhir: %.2f\n", nilaiAkhir);

    return 0;
}
