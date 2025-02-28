#include <stdio.h>
#include <ctype.h>

int main()
{
    char nama[100];
    char nim[20]; //char karena agar tiap karakter bisa dibaca
    int nilai_tugas;
    int nilai_uts;
    int nilai_uas;
    char nimHasil[20];
    int j = 0; //index untuk angka

printf("````Progam penghitung Nilai akhir Mahasiswa````\n");
    printf("Masukkan Nama Mahasiswa: ");
    gets(nama); //fgets(nama, sizeof(nama), stdin); lebih aman fgets

    printf("Masukkan Nim Mahasiswa: ");
    scanf("%s", nim); //karena array

    printf("Masukkan Nilai Tugas: ");
    scanf("%d", &nilai_tugas);

    printf("Masukkan Nilai UTS: ");
    scanf("%d", &nilai_uts);

    printf("Masukkan Nilau UAS: ");
    scanf("%d", &nilai_uas);
//menghilkangkan huruf dalam nim 
    int i; //index dalam stirng nim i=0 berarti dimulai dari karakter pertama i++ berarti, analisa akan dilanjutkan ke karakter berikutnya
     for ( i =0; nim[i] != '\0'; i++) { //isdigit akan memeriksa i dalam string nim adalah angka 
        if (isdigit (nim[i]))
        {
        nimHasil[j] = nim[i]; // jika nim[i] digit akan disalin ke nimhasil
        j++;
        }
    }
    nimHasil[j]= '\0'; //\0 menandakan loop selesai
    
    printf("--------------------------------------\n");

    printf("Nama Mahasiswa: %s\n", nama);
    printf("NIM Mahasiswa: %s\n", nimHasil);
    printf("Nilai Tugas: %d\n", nilai_tugas);
	printf("Nilai UTS: %d\n", nilai_uts);
    printf("Nilai UAS: %d\n", nilai_uas);
	
	float nilaiAkhir;
	nilaiAkhir = 0.2 * nilai_tugas + 0.35 * nilai_uts + 0.45 * nilai_uas;
	printf("Nilai Akhir: %.2f\n", nilaiAkhir);

printf("-------------------------------------");
return 0;
}