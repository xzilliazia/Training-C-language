#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILE_path "File Handling\\produk_toko.txt"
#define FILE_temp "File Handling\\temp.txt"

void remove_newline(char *str) {
    str[strcspn(str, "\n")] = '\0';
}
int is_id_exist(int id) {
    FILE *produk = fopen(FILE_path, "r");
    if (produk == NULL) {
        printf("Gagal membuka file.\n");
        return 0;  // Jika file gagal dibuka, kita anggap ID belum ada
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), produk)) {
        int id_in_file;
        sscanf(buffer, "%d,", &id_in_file);
        if (id_in_file == id) {
            fclose(produk);
            return 1;  // ID sudah ada
        }
    }

    fclose(produk);
    return 0;  // ID tidak ditemukan
}
void show_produk() {
    int id, stok;
    char name[50], kategori[50];
    double price;

    FILE *produk = fopen(FILE_path, "r");
    if (produk == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    char word_buffer[256];
    while (fgets(word_buffer, sizeof(word_buffer), produk)) {
        sscanf(word_buffer, "%d,%49[^,],%49[^,],%lf,%d", &id, name, kategori, &price, &stok);
        printf("ID: %d\n", id);
        printf("Nama: %s\n", name);
        printf("Kategori: %s\n", kategori);
        printf("Harga: %.2lf\n", price);
        printf("Stok: %d\n\n", stok);
    }

    fclose(produk);
}
void add_produk() {
    int id, stok;
    char input_buffer[20], name[50], kategori[50];
    double price;

    FILE *produk = fopen(FILE_path, "a");
    if (produk == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }
    while (1) {
        printf("\nMasukkan ID Produk: ");
        fgets(input_buffer, sizeof(input_buffer), stdin);
        remove_newline(input_buffer);
        sscanf(input_buffer, "%d", &id);

    if (is_id_exist(id)) {
        printf("ID SUDAH TERDAFTAR. Silakan masukkan ID lain.\n");
    } else {
        break;  
    }
    }
    printf("Masukkan Nama Produk: ");
    fgets(name, sizeof(name), stdin);
    remove_newline(name);

    printf("Masukkan Kategori Produk: ");
    fgets(kategori, sizeof(kategori), stdin);
    remove_newline(kategori);

    printf("Masukkan Harga Produk: ");
    fgets(input_buffer, sizeof(input_buffer), stdin);
    remove_newline(input_buffer);
    sscanf(input_buffer, "%lf", &price);

    printf("Masukkan Stok Produk: ");
    fgets(input_buffer, sizeof(input_buffer), stdin);
    remove_newline(input_buffer);
    sscanf(input_buffer, "%d", &stok);

    fprintf(produk, "%d,%s,%s,%.2lf,%d\n", id, name, kategori, price, stok);

    fclose(produk);
    printf("\nData Berhasil Disimpan\n");
}
void update_produk() {
    int id_target, id_baru, stok;
    char name[50], kategori[50];
    double price;

    FILE *produk = fopen(FILE_path, "r");
    FILE *temp_produk = fopen(FILE_temp, "w");
    if (produk == NULL || temp_produk == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    printf("\nMasukkan ID Produk yang akan diupdate: ");
    scanf("%d", &id_target);
    getchar();

    printf("\nMasukkan ID Baru Produk: ");
    scanf("%d", &id_baru);
    getchar();

    // Validasi ID baru agar tidak duplikat
    if (is_id_exist(id_baru)) {
        printf("ID SUDAH TERDAFTAR. Pembaruan dibatalkan.\n");
        fclose(produk);
        fclose(temp_produk);
        return;
    }

    printf("Masukkan Nama Produk: ");
    fgets(name, sizeof(name), stdin);
    remove_newline(name);

    printf("Masukkan Kategori Produk: ");
    fgets(kategori, sizeof(kategori), stdin);
    remove_newline(kategori);

    printf("Masukkan Harga Produk: ");
    scanf("%lf", &price);
    getchar();

    printf("Masukkan Stok Produk: ");
    scanf("%d", &stok);
    getchar();

    char buffer[256];
    int found = 0;

    while (fgets(buffer, sizeof(buffer), produk)) {
        int id;
        sscanf(buffer, "%d,", &id);

        if (id == id_target) {
            fprintf(temp_produk, "%d,%s,%s,%.2lf,%d\n", id_baru, name, kategori, price, stok);
            found = 1;
        } else {
            fputs(buffer, temp_produk);
        }
    }

    fclose(produk);
    fclose(temp_produk);

    if (!found) {
        printf("\nID Produk tidak ditemukan.\n");
        remove(FILE_temp);
    } else {
        printf("\nProduk berhasil diperbarui.\n");
        remove(FILE_path);
        rename(FILE_temp, FILE_path);
    }
}
void erase_produk() {
    int id_target, found = 0;

    printf("\nMasukkan ID Produk yang akan dihapus: ");
    scanf("%d", &id_target);
    getchar();

    FILE *produk = fopen(FILE_path, "r");
    FILE *temp_produk = fopen(FILE_temp, "w");
    if (produk == NULL || temp_produk == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), produk)) {
        int id;
        sscanf(buffer, "%d,", &id);

        if (id != id_target) {
            fputs(buffer, temp_produk);
        } else {
            found = 1;
        }
    }

    fclose(produk);
    fclose(temp_produk);

    if (!found) {
        printf("\nID Produk tidak ditemukan.\n");
        remove(FILE_temp);
    } else {
        printf("\nProduk berhasil dihapus.\n");
        remove(FILE_path);
        rename(FILE_temp, FILE_path);
    }
}
int main() {
    int choice;
 do {
    printf("\n===================================================\n");
    printf("Selamat Datang di program manajemen Toko Elektronik\n");
    printf("===================================================\n");
    printf("Menu:\n");
    printf("1. Tambah Produk baru\n");
    printf("2. Tampilkan daftar Produk\n");
    printf("3. Update informasi Produk\n");
    printf("4. Hapus Produk\n");
    printf("5. Keluar Program\n");
    printf("Masukkan Pilihan: ");

    while (scanf("%d", &choice) != 1) {
        printf("Input tidak valid. Coba lagi: ");
        getchar();
    }
    getchar();

    switch (choice) {
        case 1:
            add_produk();
            break;
        case 2:
            show_produk();
            break;
        case 3:
            update_produk();
            break;
        case 4:
            erase_produk();
            break;
        case 5:
            printf("Program selesai.\n");
            return 0;
        default:
            printf("Pilihan tidak valid. Coba lagi.\n");
        }
 } while (choice != 5);
 return 0;
}