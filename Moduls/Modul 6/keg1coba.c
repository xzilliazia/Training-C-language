#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILE_path "File Handling\\file2_toko.txt"

void remove_newline(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

void add_produk() {
    int id, stok;
    char nama[50], kategori[50], input_buffer[20];
    double harga;

    FILE *produk = fopen(FILE_path, "a");
    if (produk == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    printf("\nMasukkan ID Produk: ");
    fgets(input_buffer, sizeof(input_buffer), stdin);
    remove_newline(input_buffer);
    sscanf(input_buffer, "%d", &id);

    printf("Masukkan Nama Produk: ");
    fgets(nama, sizeof(nama), stdin);
    remove_newline(nama);

    printf("Masukkan Kategori Produk: ");
    fgets(kategori, sizeof(kategori), stdin);
    remove_newline(kategori);

    printf("Masukkan Harga Produk: ");
    fgets(input_buffer, sizeof(input_buffer), stdin);
    remove_newline(input_buffer);
    sscanf(input_buffer, "%lf", &harga);

    printf("Masukkan Stok Produk: ");
    fgets(input_buffer, sizeof(input_buffer), stdin);
    remove_newline(input_buffer);
    sscanf(input_buffer, "%d", &stok);

    fprintf(produk, "ID: %d\nNama: %s\nKategori: %s\nHarga: %.2lf\nStok: %d\n", id, nama, kategori, harga, stok);

    fclose(produk);
    printf("\nData Berhasil Disimpan\n");
}

void show_produk() {
    FILE *produk = fopen(FILE_path, "r");
    if (produk == NULL) {
        printf("Gagal membuka file\n");
        return;
    }

    char line[256];
    printf("\nDaftar Produk:\n");
    while (fgets(line, sizeof(line), produk)) {
        printf("%s", line);
    }

    fclose(produk);
}

void update_produk() {
    FILE *produk = fopen(FILE_path, "r");
    if (produk == NULL) {
        printf("Gagal membuka file\n");
        return;
    }

    char buffer[1000][256];
    int count = 0;

    // Membaca semua data produk ke dalam buffer
    while (fgets(buffer[count], sizeof(buffer[count]), produk)) {
        count++;
    }
    fclose(produk);

    int idtarget, new_id;
    printf("\nMasukkan ID Produk yang akan diubah: ");
    scanf("%d", &idtarget);
    getchar(); // Menghapus newline

    // Mencari data yang akan diubah
    int found = -1;
    for (int i = 0; i < count; i++) {
        if (strstr(buffer[i], "ID:")) {
            int id;
            sscanf(buffer[i], "ID: %d", &id);
            if (id == idtarget) {
                found = i;
                break;
            }
        }
    }

    if (found == -1) {
        printf("\nID tidak ditemukan\n");
        return;
    }

    char nama[50], kategori[50], input_buffer[20];
    double harga;
    int stok;

    printf("\nMasukkan ID Baru: ");
    fgets(input_buffer, sizeof(input_buffer), stdin);
    remove_newline(input_buffer);
    sscanf(input_buffer, "%d", &new_id);

    printf("Masukkan Nama Baru: ");
    fgets(nama, sizeof(nama), stdin);
    remove_newline(nama);

    printf("Masukkan Kategori Baru: ");
    fgets(kategori, sizeof(kategori), stdin);
    remove_newline(kategori);

    printf("Masukkan Harga Baru: ");
    fgets(input_buffer, sizeof(input_buffer), stdin);
    remove_newline(input_buffer);
    sscanf(input_buffer, "%lf", &harga);

    printf("Masukkan Stok Baru: ");
    fgets(input_buffer, sizeof(input_buffer), stdin);
    remove_newline(input_buffer);
    sscanf(input_buffer, "%d", &stok);

    snprintf(buffer[found], sizeof(buffer[found]), "ID: %d\nNama: %s\nKategori: %s\nHarga: %.2lf\nStok: %d\n", new_id, nama, kategori, harga, stok);

    produk = fopen(FILE_path, "w");
    if (produk == NULL) {
        printf("Gagal membuka file untuk menulis ulang\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fputs(buffer[i], produk);
    }

    fclose(produk);
    printf("\nProduk berhasil diperbarui\n");
}

void erase_produk() {
    FILE *produk = fopen(FILE_path, "r");
    if (produk == NULL) {
        printf("Gagal membuka file\n");
        return;
    }

    char buffer[1000][256];
    int count = 0, idtarget;

    printf("\nMasukkan ID Produk yang akan dihapus: ");
    scanf("%d", &idtarget);
    getchar();

    // Membaca semua data produk ke dalam buffer
    while (fgets(buffer[count], sizeof(buffer[count]), produk)) {
        count++;
    }
    fclose(produk);

    // Mencari data yang akan dihapus
    int found = -1;
    for (int i = 0; i < count; i++) {
        if (strstr(buffer[i], "ID:")) {
            int id;
            sscanf(buffer[i], "ID: %d", &id);
            if (id == idtarget) {
                found = i;
                break;
            }
        }
    }

    if (found == -1) {
        printf("\nID tidak ditemukan\n");
        return;
    }

    int lines_to_delete = 1;
    for (int i = found + 1; i < count; i++) {
        if (strstr(buffer[i], "ID:") != NULL) {
            break;
        }
        lines_to_delete++;
    }

    for (int i = found; i < count - lines_to_delete; i++) {
        strcpy(buffer[i], buffer[i + lines_to_delete]);
    }
    count -= lines_to_delete;

    produk = fopen(FILE_path, "w");
    if (produk == NULL) {
        printf("Gagal membuka file untuk menulis ulang\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fputs(buffer[i], produk);
    }

    fclose(produk);
    printf("\nProduk berhasil dihapus\n");
}

int main() {
    int choice;
    do {
        printf("\n===================================================");
        printf("\nSelamat Datang di program manajemen Toko Elektronik\n");
        printf("===================================================\n");
        printf("Menu:\n");
        printf("1. Tambah Produk baru\n");
        printf("2. Tampilkan daftar Produk\n");
        printf("3. Update informasi Produk\n");
        printf("4. Hapus Produk\n");
        printf("5. Keluar Program\n");
        printf("Masukkan Pilihan: ");

        while (scanf("%d", &choice) != 1) {
            printf("Input Invalid.\nMengulang . . . ");
            getchar();
            printf("\nMasukkan Pilihan: ");
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
                printf("Program selesai...\n");
                return 0;
        }
    } while (choice != 5);
    return 0;
}
