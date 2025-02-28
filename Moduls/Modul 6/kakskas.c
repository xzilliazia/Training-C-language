#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILE_path "File Handling\\produktes_toko.txt"
#define FILE_temp "File Handling\\temp.txt"

void remove_newline(char *str) {
    str[strcspn(str, "\n")] = '\0';
}
void add_produk(){
    int id, stok;
    char input_buffer[20], name[50], kategori[50];
    double price;

    FILE* produk = fopen(FILE_path, "a");
    if (produk == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

        //Kenapa saya menggunalan fgets, karena fgets lebih stabil dan aman serta memudahkan untuk menghapus newline menggunakan fungsi strcspn.
    
        printf("\nMasukkan ID Produk: "); fgets(input_buffer, sizeof(input_buffer), stdin); remove_newline(input_buffer); sscanf(input_buffer, "%d", &id); //ubah input jadi int
        printf("Masukkan Nama Produk: "); fgets(name, sizeof(name), stdin); remove_newline(name);
        printf("Masukkan Kategori Produk: "); fgets(kategori, sizeof(kategori), stdin); remove_newline(kategori);
        printf("Masukkan Harga Produk: "); fgets(input_buffer, sizeof(input_buffer), stdin); remove_newline(input_buffer); sscanf(input_buffer, "%lf", &price); //ubah inpoutjadi double
        printf("Masukkan Stok Produk: "); fgets(input_buffer, sizeof(input_buffer), stdin); remove_newline(input_buffer); sscanf(input_buffer, "%d", &stok); //ubnah input jadi int

        //simpan input dengan format ini
        fprintf(produk, "%d,%s,%s,%.2lf,%d\n", id, name, kategori, price, stok);

    fclose(produk);
    printf("\nData Berhasil Disimpan\n");
    system("pause");
}
void show_produk(){
    int id, stok;
    char name[50], kategori[50];
    double price;

     FILE* produk = fopen(FILE_path, "r");
        if (produk == NULL){
            printf("Gagal dibuka\n");
            return;
            }
            char word_buffer[256];
            while (fgets(word_buffer, sizeof(word_buffer), produk)) { // Membaca setiap baris
            sscanf(word_buffer,  "%d,%49[^,],%49[^,],%lf,%d", &id, name, kategori, &price, &stok);
            printf("ID: %d\n", id);
            printf("Nama: %s\n", name);
            printf("Kategori: %s\n", kategori);
            printf("Harga: %.2lf\n", price);
            printf("Stok: %d\n\n", stok);
            }

    fclose(produk);
}
void updateproduk() {
    double price;
    char input_buffer[20], name[50], kategori[50];
    int stok, idtarget, new_id;

    FILE* produk = fopen(FILE_path, "r");
    FILE* temp_produk = fopen(FILE_temp, "w");
    if (produk == NULL || temp_produk == NULL) {
        printf("Gagal dibuka\n");
        return;
    }

    printf("\nMasukkan ID Produk yang akan diubah: ");
    scanf("%d", &idtarget);
    getchar();
    printf("\nMasukkan ID Baru Produk: "); fgets(input_buffer, sizeof(input_buffer), stdin); remove_newline(input_buffer); sscanf(input_buffer, "%d", &new_id); //ubah input jadi int
    printf("Masukkan Nama Produk: "); fgets(name, sizeof(name), stdin); remove_newline(name);
    printf("Masukkan Kategori Produk: "); fgets(kategori, sizeof(kategori), stdin); remove_newline(kategori);
    printf("Masukkan Harga Produk: "); fgets(input_buffer, sizeof(input_buffer), stdin); remove_newline(input_buffer); sscanf(input_buffer, "%lf", &price); //ubah inpoutjadi double
    printf("Masukkan Stok Produk: "); fgets(input_buffer, sizeof(input_buffer), stdin); remove_newline(input_buffer); sscanf(input_buffer, "%d", &stok);

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), produk)) {
        int id;
        sscanf(buffer, "%d,", &id);
    if (id == idtarget) {
        fprintf(temp_produk, "%d,%s,%s,%.2lf,%d\n", new_id, name, kategori, price, stok);
    } else {
            fputs(buffer, temp_produk);
    }
    } 
   

    fclose(produk);
    fclose(temp_produk);

    if (remove(FILE_path) !=0 ){
        printf("Gagal menghapus file lama\n");
        return;
    }
    if (rename(FILE_temp, FILE_path) != 0){
    printf("Gagal Mengganti File\n");
    } else {
         printf("\nProduk berhasil dihapus\n");
    }
}
void erase_produk(){
    FILE* produk = fopen(FILE_path, "r");
    FILE* temp_produk = fopen(FILE_temp, "w");
    if (produk == NULL || temp_produk == NULL) {
        printf("Gagal dibuka\n");
        return;
    }
    char bufer[1000][256];
    int count = 0, idtarget;

    printf("\nMasukkan ID Produk yang akan dihapus: ");
    scanf("%d", &idtarget); getchar();

    // Membaca setiap baris file produk dan menyimpanya dalam bufer
    while (fgets(bufer[count], sizeof(bufer[count]), produk)){
            count++;
    }
    fclose(produk);

    //Mencari data terkait ID
        int startLine = -1, endLine = -1;
        //cari ID yamg cocok
        for (int i = 0; i < count; i++){
            if (strstr(bufer[i], "ID:")){
                int id;
                sscanf(bufer[i], "ID: %d", &id);
                if (id == idtarget) {
                    //baris awal data dari id yg ditemukan
                    startLine = i;
                //mencari baris akhir
                endLine = startLine;
                /*jadi endline akan terus loop sampai ada kondisi false karena pakai &&.
                kondisi false ketika bertemu dengan string ID: yang berarti baris data produk lain.
                jika tidak ada ID baru maka endline sampai EOF dan sudah dibatasi menggunakan < count*/
                while (endLine + 1 < count && !strstr(bufer[endLine + 1], "ID:")){
                    endLine++;
                }
                break;
                }
            }
        }
        
        if(startLine == -1){
            printf("\nID tidak ditemukan\n");
            return;
        }
        for (int i = 0; i < count; i++) {
        if (i < startLine || i > endLine) {
            fputs(bufer[i], temp_produk);
            }
        }
        fclose(temp_produk);

        if (remove(FILE_path) !=0 ){
            printf("Gagal menghapus file lama\n");
            return;
        }
        if (rename(FILE_temp, FILE_path) != 0){
        printf("Gagal Mengganti File\n");
        } else {
         printf("\nProduk berhasil dihapus\n");
        }
}
int main(){
    int choise;
 do {
    printf("\n===================================================" );
    printf("\nSelamat Datang di program manajemen Toko Elektronik\n" );
    printf("===================================================\n" );
    printf("Menu:\n" );
    printf("1. Tambah Produk baru\n");
    printf("2. Tampilkan daftar Produk\n");
    printf("3. Update informasi Produk\n");
    printf("4. Hapus Produk\n");
    printf("5. Keluar Progam\n");
    printf("Masukkan Pilihan: ");

    while (scanf("%d", &choise) !=1 ) {
        printf("Input Invalid.\nMengulang . . . ");
        getchar();
        printf("\nMasukkan Pilihan: ");
    } getchar();
    
    switch(choise){
        case 1:
        add_produk();
        break;
        case 2:
        show_produk();
        break;
        case 3:
        updateproduk();
        break;
        case 4:
        erase_produk();
        break;
        case 5:
        printf("Progam selesai...");
        return 1;
    }
 } while (choise != 5);
return 0;
}