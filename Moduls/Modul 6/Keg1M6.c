#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BOLD "\033[1m"
#define ITALIC "\033[3m"

#define RESET "\033[0m"
#define BOLD_RED "\033[1;31m"
#define BOLD_BLUE "\033[1;34m"
#define BOLD_GREEN "\033[1;32m"

void satu(){
    char name[30], ktk[30];
    int id, stk;
    double price;

 FILE* produc = fopen("E:\\C\\vsc\\Modul 6\\File Handling\\produk_toko.txt", "a");
    if (produc == NULL) {
        printf(BOLD_RED"Gagal membuka file.\n"RESET);
        return;
    }

    printf("\nMasukkan ID Produk: "); scanf("%d", &id); while (getchar()!='\n'); fprintf(produc, "\nID: %d", id);
    printf("Masukkan Nama Produk: "); fgets(name, sizeof(name), stdin); fprintf(produc, "\nNama: %s", name);
    printf("Masukkan Kategori Produk: "); fgets(ktk, sizeof(ktk), stdin); fprintf(produc, "Kategori: %s", ktk);
    printf("Masukkan Harga Produk: "); scanf("%lf", &price); while (getchar()!='\n'); fprintf(produc, "Harga: %.4lf", price);
    printf("Masukkan stok Produk: "); scanf("%d", &stk); while (getchar()!='\n'); fprintf(produc, "\nStok: %d", stk);

    fclose(produc);
    printf(BOLD_RED "Data Berhasil Disimpan" RESET);
 
}

void tiga (){
    FILE* produc = fopen("E:\\C\\vsc\\Modul 6\\File Handling\\produk_toko.txt", "a");
        if (produc == NULL){
            printf(BOLD_RED"Gagal dibuka\n"RESET);
            return;
            }
    char buffer[1000][256];
    int count = 0;
    while (fgets(buffer[count], sizeof(buffer[count]), produc)){
        count++;
    }
    fclose(produc);

    int newId;
    printf("Masukkan ID yang ingin di Update: "); scanf("%d", &newId); getchar();
    int found = -1;


int main(){
    int choise;
    FILE* produc;

 do {
    printf( BOLD_BLUE "\n===================================================" );
    printf("\nSelamat Datang di progam manajemen Toko Elektronik\n" );
    printf("===================================================\n" RESET);
    printf(BOLD_GREEN "Menu:\n" RESET);
    printf(BOLD"1. Tambah Produk baru\n"RESET);
    printf(BOLD"2. Tampilkan daftar Produk\n"RESET);
    printf(BOLD"3. Update informasi Produk\n"RESET);
    printf(BOLD"4. Hapus Produk\n"RESET);
    printf(BOLD"5. Keluar Progam\n"RESET);
    printf(BOLD_GREEN "Masukkan Pilihan: "RESET);
    
    while (scanf("%d", &choise) !=1 ) {
        printf("Input Invalid.\nMengulang . . . ");
        while (getchar()!='\n');
        printf(BOLD_GREEN"\nMasukkan Pilihan: "RESET);
    }

 switch (choise){
    case 1:
        satu();
        break;
    case 2:
        produc = fopen("E:\\C\\vsc\\Modul 6\\File Handling\\produk_toko.txt", "r");
        if (produc == NULL){
            printf(BOLD_RED"Gagal dibuka\n"RESET);
            return 1;
            }
        char cetak[256];
        while(fgets(cetak, sizeof(cetak), produc)){
            printf("%s", cetak);
        }
        fclose(produc);
        break;
    case 3:
        
        break;
    case 4:
        produc = fopen("E:\\C\\vsc\\Modul 6\\File Handling\\produk_toko.txt", "w");
        if (produc == NULL){
            printf(BOLD_RED"Gagal dibuka\n"RESET);
            return 1;
            }
        printf(BOLD_RED "File Berhasil Dihapus\n"RESET);
        fclose(produc);
        break;
    case 5:
        printf(BOLD_RED "Progam Selesai\n"RESET);
        break;
    default:
        printf("Pilihan tidak valid. Silakan pilih kembali.\n");
        break;
  }
 } while (choise !=5);

return 0;
}
}