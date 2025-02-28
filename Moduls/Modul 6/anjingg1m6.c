#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILE_path "File Handling\\produk2_toko.txt"
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

    // Menggunakan fgets untuk input dan remove_newline untuk menghapus karakter newline
    printf("\nMasukkan ID Produk: ");
    fgets(input_buffer, sizeof(input_buffer), stdin);
    remove_newline(input_buffer);
    sscanf(input_buffer, "%d", &id); //ubah input jadi int

    printf("Masukkan Nama Produk: ");
    fgets(name, sizeof(name), stdin);
    remove_newline(name);

    printf("Masukkan Kategori Produk: ");
    fgets(kategori, sizeof(kategori), stdin);
    remove_newline(kategori);

    printf("Masukkan Harga Produk: ");
    fgets(input_buffer, sizeof(input_buffer), stdin);
    remove_newline(input_buffer);
    sscanf(input_buffer, "%lf", &price); //ubah input jadi double

    printf("Masukkan Stok Produk: ");
    fgets(input_buffer, sizeof(input_buffer), stdin);
    remove_newline(input_buffer);
    sscanf(input_buffer, "%d", &stok); //ubah input jadi int

    // Menyimpan input dengan format dipisahkan koma
    fprintf(produk, "%d,%s,%s,%.2lf,%d\n", id, name, kategori, price, stok);

    fclose(produk);
    printf("\nData Berhasil Disimpan\n");
    system("pause");
}

void show_produk(){
    FILE* produk = fopen(FILE_path, "r");
    if (produk == NULL){
        printf("Gagal dibuka\n");
        return;
    }

    char word_buffer[256];

    // Membaca setiap baris dalam file
    while (fgets(word_buffer, sizeof(word_buffer), produk)) {
        // Menggunakan strtok untuk memisahkan data berdasarkan koma
        char *token = strtok(word_buffer, ","); // ID Produk
        if (token != NULL) {
            printf("ID: %s\n", token);
        }

        token = strtok(NULL, ","); // Nama Produk
        if (token != NULL) {
            printf("Nama: %s\n", token);
        }

        token = strtok(NULL, ","); // Kategori Produk
        if (token != NULL) {
            printf("Kategori: %s\n", token);
        }

        token = strtok(NULL, ","); // Harga Produk
        if (token != NULL) {
            printf("Harga: %.2lf\n", atof(token));
        }

        token = strtok(NULL, ","); // Stok Produk
        if (token != NULL) {
            printf("Stok: %d\n\n", atoi(token));
        }
    }

    fclose(produk);
}

void updateproduk() {
    FILE* produk = fopen(FILE_path, "r");
    if (produk == NULL) {
        printf("Gagal dibuka\n");
        return;
    }
    FILE* temp_produk = fopen(FILE_temp, "w");
    if (temp_produk == NULL){
        printf("Gagal membuka file sementara\n");
        fclose(produk);
        return;
    }

    char bufer[1000][256];
    int count = 0;

    // Membaca seluruh data ke dalam buffer
    while (fgets(bufer[count], sizeof(bufer[count]), produk)) {
        count++;
    }
    fclose(produk);

    int idtarget, new_id;
    printf("\nMasukkan ID Produk yang akan diubah: ");
    scanf("%d", &idtarget);
    getchar(); // Menghapus newline setelah input ID

    // Mencari ID yang ingin diubah
    int found = -1;
    for (int i = 0; i < count; i++) {
        if (strstr(bufer[i], "ID:")) {
            int id;
            sscanf(bufer[i], "ID: %d", &id); // Mengambil ID dari baris
            if (id == idtarget) {
                found = i; // Baris pertama dari data produk yang ditemukan
                break;
            }
        }
    }
    if (found == -1) {
        printf("\nID tidak ditemukan\n");
        return;
    }

    int stok;
    char input_buffer[20], name[50], kategori[50];
    double price;

    printf("\nMasukkan ID Baru Produk: ");
    fgets(input_buffer, sizeof(input_buffer), stdin);
    remove_newline(input_buffer);
    sscanf(input_buffer, "%d", &new_id); //ubah input jadi int

    printf("Masukkan Nama Produk: ");
    fgets(name, sizeof(name), stdin);
    remove_newline(name);

    printf("Masukkan Kategori Produk: ");
    fgets(kategori, sizeof(kategori), stdin);
    remove_newline(kategori);

    printf("Masukkan Harga Produk: ");
    fgets(input_buffer, sizeof(input_buffer), stdin);
    remove_newline(input_buffer);
    sscanf(input_buffer, "%lf", &price); //ubah input jadi double

    printf("Masukkan Stok Produk: ");
    fgets(input_buffer, sizeof(input_buffer), stdin);
    remove_newline(input_buffer);
    sscanf(input_buffer, "%d", &stok);

    // Menambahkan data produk baru dengan ID yang baru dan semua informasi yang diperbarui
    snprintf(bufer[found], sizeof(bufer[found]), "%d,%s,%s,%.2lf,%d\n", new_id, name, kategori, price, stok);

    // Menulis ulang data ke file temp
    for (int i = 0; i < count; i++) {
        fputs(bufer[i], temp_produk);
    }
    fclose(temp_produk);

    if (rename(FILE_temp, FILE_path) != 0) {
        printf("Gagal Mengganti File\n");
    } else {
        printf("Produk dengan ID-%d berhasil diperbarui dengan ID baru %d\n", idtarget, new_id);
    }
}

void erase_produk() {
    FILE* produk = fopen(FILE_path, "r");
    if (produk == NULL) {
        printf("Gagal dibuka\n");
        return;
    }
    FILE* temp_produk = fopen(FILE_temp, "w");
    if (temp_produk == NULL) {
        printf("Gagal membuka file sementara\n");
        fclose(produk);
        return;
    }

    char bufer[1000][256];
    int count = 0, idtarget;

    printf("\nMasukkan ID Produk yang akan dihapus: ");
    scanf("%d", &idtarget); getchar();

    // Membaca setiap baris file produk dan menyimpannya dalam buffer
    while (fgets(bufer[count], sizeof(bufer[count]), produk)) {
        count++;
    }
    fclose(produk);

    // Mencari data terkait ID
    int startLine = -1, endLine = -1;
    // Cari ID yang cocok
    for (int i = 0; i < count; i++) {
        if (strstr(bufer[i], "ID:")) {
            int id;
            sscanf(bufer[i], "ID: %d", &id);
            if (id == idtarget) {
                // Baris awal data dari id yang ditemukan
                startLine = i;
                // Mencari baris akhir
                endLine = startLine;
                // Jadi endLine akan terus loop sampai ada kondisi false karena pakai &&
                while (endLine + 1 < count && !strstr(bufer[endLine + 1], "ID:")) {
                    endLine++;
                }
                break;
            }
        }
    }

    if (startLine == -1) {
        printf("\nID tidak ditemukan\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        if (i < startLine || i > endLine) {
            fputs(bufer[i], temp_produk);
        }
    }
    fclose(temp_produk);

    if (remove(FILE_path) != 0) {
        printf("Gagal menghapus file lama\n");
        return;
    }
    if (rename(FILE_temp, FILE_path) != 0) {
        printf("Gagal Mengganti File\n");
    } else {
        printf("\nProduk berhasil dihapus\n");
    }
}

int main() {
    int choise;
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

        while (scanf("%d", &choise) != 1) {
            printf("Input Invalid.\nMengulang . . . ");
            getchar();
            printf("\nMasukkan Pilihan: ");
        }
        getchar();

        switch (choise) {
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
                printf("Program selesai...\n");
                return 1;
        }
    } while (choise != 5);

    return 0;
}
