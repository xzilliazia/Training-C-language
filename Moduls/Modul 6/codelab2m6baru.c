#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_path "File Handling\\data_maha.txt"

void remove_newline (char* str){
    str[strcspn(str, "\n")] = 0;
}
void write(){
    char name[30], nim[20], jurusan[20];
    FILE* data = fopen(FILE_path, "a");

    if (data == NULL){
            printf("Gagal dibuka\n");
            return;
        }
    printf("\nBerhasil Dibuka\n");
    printf("Masukkan Nama: "); fgets(name, sizeof(name), stdin); remove_newline(name);
    printf("Masukkan NIM: "); fgets(nim, sizeof(nim), stdin); remove_newline(nim);
    printf("Masukkan Progam studi: "); fgets(jurusan, sizeof(jurusan), stdin); remove_newline(jurusan);

    fprintf(data, "\nNama: %s\nNIM: %s\nProgam Study: %s\n", name, nim, jurusan);
    fclose(data);
    printf("Data Berhasil Disimpan");
}
void read (){
        FILE* data = fopen(FILE_path, "r");
        if (data == NULL){
            printf("Gagal dibuka\n");
            return;
            }
            char kata[256];
                while (fgets(kata, sizeof(kata), data)) { // Membaca setiap baris
                    printf("%s", kata);
                }
            fclose(data);
}
void reset (){
    FILE* data = fopen(FILE_path, "w");
    if (data == NULL){
            printf("\nGagal dibuka\n");
            return;
        }    
        printf("\nFile Berhasil Dihapus");
    fclose(data);
}

int main(){
    int d;
 do {
    printf("\n\nPilih Aksi: \n");
    printf("1. Tulis data mahasiswa\n");
    printf("2. Baca data mahasiswa\n");
    printf("3. Reset isi file\n");
    printf("4. Keluar\n");
    printf("Masukkan Pilihan: ");
    scanf("%d", &d);
    getchar();

 switch(d){
    case 1:
    write();
    break;
    case 2:
    read();
    break;
    case 3:
    reset();
    break;
    case 4:
    printf("\nProgam selesai");
    return 1;
 }
 } while (d != 4);
system("pause");
return 0;
}