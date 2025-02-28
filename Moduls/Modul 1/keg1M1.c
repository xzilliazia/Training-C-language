#include <stdio.h>

int main()
{
    char nama[100];
    char nim [20];
    int nilai_tugas;
    int nilai_uts;
    int nilai_uas;

    printf("Masukkan Nama Mahasiswa: ");
    fgets(nama);

    printf("Masukkan Nim: ");
    fgets(nim);

    printf("Masukkan Nilai Tugas: ");
    scanf(%d, nilai_tugas);

    printf("Masukkan Nilai UTS: ");
    scanf(%d, nilai_uts);

    printf("Masukkan Nilau UAS: ");
    scanf(%d\n, nilai_uas);

    printf("Nama Mahasiswa:%s \n", nama)
    printf("NIM Mahasiswa:%d \n", nim)
    printf("Nilai Tugas:%d \n", nilai_tugas)
    printf("Nilai UAS:%d \n", nilai_uas)
    printf("Nilai UTS:%d \n", nilai_uts)
    float nilai_akhir = nilai_tugas * (20/100) + nilai_uas * (45/100) + nilai_uts * (35/100);
    printf("Nilai Akhir:%.2f\n", nilai_akhir);

return 0;

}