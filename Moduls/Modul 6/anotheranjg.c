#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILE_PATH "File Handling\\file_toko3.txt"

// Definisi struct dengan typedef
typedef struct {
    int id;
    char nama[50];
    char kategori[50];
    double harga;
    int stok;
} Produk;

void remove_newline(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

void add_produk() {
    Produk p;
    char input_buffer[20];

    FILE *produk = fopen(FILE_PATH, "a");
    if (produk == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    printf("\nMasukkan ID Produk: ");
    fgets(input_buffer, sizeof(input_buffer), stdin);
    remove_newline(input_buffer);
    sscanf(input_buffer, "%d", &p.id);

    printf("Masukkan Nama Produk: ");
    fgets(p.nama, sizeof(p.nama), stdin);
    remove_newline(p.nama);

    printf("Masukkan Kategori Produk: ");
    fgets(p.kategori, sizeof(p.kategori), stdin);
    remove_newline(p.kategori);

    printf("Masukkan Harga Produk: ");
    fgets(input_buffer, sizeof(input_buffer), stdin);
    remove_newline(input_buffer);
    sscanf(input_buffer, "%lf", &p.harga);

    printf("Masukkan Stok Produk: ");
    fgets(input_buffer, sizeof(input_buffer), stdin);
    remove_newline(input_buffer);
    sscanf(input_buffer, "%d", &p.stok);

    fprintf(produk, "%d|%s|%s|%.2lf|%d\n", p.id, p.nama, p.kategori, p.harga, p.stok);

    fclose(produk);
    printf("\nData Berhasil Disimpan\n");
    system("pause");
}

void show_produk() {
    FILE *produk = fopen(FILE_PATH, "r");
    if (produk == NULL) {
        printf("Gagal membuka file\n");
        return;
    }

    Produk p;
    char line[256];
    printf("\nDaftar Produk:\n");
    while (fgets(line, sizeof(line), produk)) {
        sscanf(line, "%d|%49[^|]|%49[^|]|%lf|%d", &p.id, p.nama, p.kategori, &p.harga, &p.stok);
        printf("ID: %d\nNama: %s\nKategori: %s\nHarga: %.2lf\nStok: %d\n\n", p.id, p.nama, p.kategori, p.harga, p.stok);
    }

    fclose(produk);
}

void update_produk() {
    FILE *produk = fopen(FILE_PATH, "r");
    if (produk == NULL) {
        printf("Gagal membuka file\n");
        return;
    }

    Produk daftar_produk[1000];
    int count = 0, idtarget, found = -1;
    char line[256];

    printf("\nMasukkan ID Produk yang akan diubah: ");
    scanf("%d", &idtarget);
    getchar(); // Menghapus newline

    while (fgets(line, sizeof(line), produk)) {
        sscanf(line, "%d|%49[^|]|%49[^|]|%lf|%d", &daftar_produk[count].id, daftar_produk[count].nama,
               daftar_produk[count].kategori, &daftar_produk[count].harga, &daftar_produk[count].stok);
        if (daftar_produk[count].id == idtarget) {
            found = count;
        }
        count++;
    }
    fclose(produk);

    if (found == -1) {
        printf("\nID tidak ditemukan\n");
        return;
    }

    printf("\nMasukkan Nama Baru: ");
    fgets(daftar_produk[found].nama, sizeof(daftar_produk[found].nama), stdin);
    remove_newline(daftar_produk[found].nama);

    printf("Masukkan Kategori Baru: ");
    fgets(daftar_produk[found].kategori, sizeof(daftar_produk[found].kategori), stdin);
    remove_newline(daftar_produk[found].kategori);

    printf("Masukkan Harga Baru: ");
    scanf("%lf", &daftar_produk[found].harga);

    printf("Masukkan Stok Baru: ");
    scanf("%d", &daftar_produk[found].stok);

    produk = fopen(FILE_PATH, "w");
    if (produk == NULL) {
        printf("Gagal membuka file untuk menulis ulang\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(produk, "%d|%s|%s|%.2lf|%d\n", daftar_produk[i].id, daftar_produk[i].nama, daftar_produk[i].kategori,
                daftar_produk[i].harga, daftar_produk[i].stok);
    }

    fclose(produk);
    printf("\nProduk berhasil diperbarui\n");
}

void erase_produk() {
    FILE *produk = fopen(FILE_PATH, "r");
    if (produk == NULL) {
        printf("Gagal membuka file\n");
        return;
    }

    Produk daftar_produk[1000];
    int count = 0, idtarget, found = -1;
    char line[256];

    printf("\nMasukkan ID Produk yang akan dihapus: ");
    scanf("%d", &idtarget);

    while (fgets(line, sizeof(line), produk)) {
        sscanf(line, "%d|%49[^|]|%49[^|]|%lf|%d", &daftar_produk[count].id, daftar_produk[count].nama,
               daftar_produk[count].kategori, &daftar_produk[count].harga, &daftar_produk[count].stok);
        if (daftar_produk[count].id == idtarget) {
            found = count;
        }
        count++;
    }
    fclose(produk);

    if (found == -1) {
        printf("\nID tidak ditemukan\n");
        return;
    }

    produk = fopen(FILE_PATH, "w");
    if (produk == NULL) {
        printf("Gagal membuka file untuk menulis ulang\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        if (i != found) {
            fprintf(produk, "%d|%s|%s|%.2lf|%d\n", daftar_produk[i].id, daftar_produk[i].nama, daftar_produk[i].kategori,
                    daftar_produk[i].harga, daftar_produk[i].stok);
        }
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
