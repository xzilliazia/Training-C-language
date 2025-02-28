#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    int d;
    char nim[20], name[50], jurusan[30];

while(1){
printf("\nPilih Aksi: \n");
 printf("1. Tulis data mahasiswa\n");
 printf("2. Baca data mahasiswa\n");
 printf("3. Reset isi file\n");
 printf("4. Keluar\n");
 printf("Masukkan Pilihan: ");
 scanf("%d", &d);
 getchar();

switch(d){
    case 1: {
    FILE* ftpr = fopen("E:\\C\\vsc\\Modul 6\\File Handling\\data_mahasiswa.txt", "a");
            if (ftpr == NULL){
            printf("Gagal dibuka\n");
            return 1;
            }
            // /////////////////////////
            printf("Berhasil dibuka\n");
            printf("\nMasukkan Nama: ");
            fgets(name, sizeof(name), stdin);
            printf("\nMasukkan NIM: ");
            fgets(nim, sizeof(nim), stdin);
            printf("\nMasukkan Progam study: ");
            fgets(jurusan, sizeof(jurusan), stdin);

            //memasukkan kedalam file                
            fprintf(ftpr, "\nNama: %s\n", name);
            fprintf(ftpr, "NIM: %s\n", nim);
            fprintf(ftpr, "Progam Studi: %s\n", jurusan);

            fclose(ftpr);
            printf("\nData Mahasiswa berhasil disimpan\n");
            break;
            }
        case 2: {
        FILE* ftpr = fopen("E:\\C\\vsc\\Modul 6\\File Handling\\data_mahasiswa.txt", "r");
        if (ftpr == NULL){
            printf("Gagal dibuka\n");
            return 1;
            }
            char kata[256];
                while (fgets(kata, sizeof(kata), ftpr)) { // Membaca setiap baris
                    printf("%s", kata);
                }
            fclose(ftpr);
            break; 
        }
        case 3: {
        FILE* ftpr = fopen("E:\\C\\vsc\\Modul 6\\File Handling\\data_mahasiswa.txt", "w");
            if (ftpr == NULL){
            printf("Gagal dibuka\n");
            return 1;
            }
            printf("\n\033[32mIsi File berhasil dihapus\033[0m\n");
            fclose(ftpr);
            break;
        }
        case 4: {
        printf("\n\033[32mKeluar Progam\033[0m");
        return 0;
        }      
 }//switch
}//while
return 0;
}