#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAMA 20

// Struktur Barang
typedef struct {
    char nama[MAX_NAMA];
    int harga;
    int stok;
} Barang;

// Fungsi menampilkan menu
void tampilkan_menu(Barang *barang, int jumlah_barang) {
    printf("\nMenu Barang:\n");
    for (int i = 0; i < jumlah_barang; i++) {
        printf("%d. %s - Rp%d (Stok: %d)\n", i + 1, barang[i].nama, barang[i].harga, barang[i].stok);
    }
    printf("%d. Tambah Produk\n%d. Restock Barang\n%d. Keluar\n", jumlah_barang + 1, jumlah_barang + 2, jumlah_barang + 3);
}

// Fungsi input pilihan dengan validasi
int input_pilihan(int batas) {
    int pilihan;
    do {
        printf("Masukkan pilihan (1-%d): ", batas);
        scanf("%d", &pilihan);
        if (pilihan < 1 || pilihan > batas) printf("Pilihan tidak valid. Coba lagi.\n");
    } while (pilihan < 1 || pilihan > batas);
    return pilihan;
}

// Fungsi tambah produk
Barang *tambah_produk(Barang *barang, int *jumlah_barang) {
    (*jumlah_barang)++;
    barang = realloc(barang, (*jumlah_barang) * sizeof(Barang));
    if (!barang) {
        printf("Gagal menambah produk.\n");
        exit(1);
    }
    printf("Nama produk: "); scanf(" %[^\n]", barang[*jumlah_barang - 1].nama);
    printf("Harga produk: Rp"); scanf("%d", &barang[*jumlah_barang - 1].harga);
    printf("Stok produk: "); scanf("%d", &barang[*jumlah_barang - 1].stok);
    printf("Produk '%s' berhasil ditambahkan!\n", barang[*jumlah_barang - 1].nama);
    return barang;
}

// Fungsi restock barang
void restock_barang(Barang *barang, int jumlah_barang) {
    int pilihan = input_pilihan(jumlah_barang);
    int tambahan;
    printf("Masukkan jumlah stok tambahan untuk %s: ", barang[pilihan - 1].nama);
    scanf("%d", &tambahan);
    barang[pilihan - 1].stok += tambahan;
    printf("Stok %s sekarang %d.\n", barang[pilihan - 1].nama, barang[pilihan - 1].stok);
}

// Fungsi pembelian barang
void beli_barang(Barang *barang, int pilihan) {
    int uang, kembalian;
    if (barang[pilihan - 1].stok == 0) {
        printf("Stok %s habis.\n", barang[pilihan - 1].nama);
        return;
    }
    printf("Harga %s: Rp%d\nMasukkan uang: Rp", barang[pilihan - 1].nama, barang[pilihan - 1].harga);
    scanf("%d", &uang);
    if (uang >= barang[pilihan - 1].harga) {
        kembalian = uang - barang[pilihan - 1].harga;
        barang[pilihan - 1].stok--;
        printf("Pembelian sukses! Kembalian Anda: Rp%d\n", kembalian);
    } else {
        printf("Uang tidak cukup. Anda kurang Rp%d.\n", barang[pilihan - 1].harga - uang);
    }
}

int main() {
    Barang *barang;
    int jumlah_barang = 4, pilihan;
    char lanjut;

    // Alokasi awal memori
    barang = malloc(jumlah_barang * sizeof(Barang));
    if (!barang) return 1;

    // Data awal
    strcpy(barang[0].nama, "Air Mineral"); barang[0].harga = 5000; barang[0].stok = 10;
    strcpy(barang[1].nama, "Kopi"); barang[1].harga = 10000; barang[1].stok = 5;
    strcpy(barang[2].nama, "Snack"); barang[2].harga = 7000; barang[2].stok = 8;
    strcpy(barang[3].nama, "Susu"); barang[3].harga = 12000; barang[3].stok = 6;

    printf("===== MESIN PENJUAL OTOMATIS =====\n");
    do {
        tampilkan_menu(barang, jumlah_barang);
        pilihan = input_pilihan(jumlah_barang + 3);

        if (pilihan == jumlah_barang + 1) {
            barang = tambah_produk(barang, &jumlah_barang);
        } else if (pilihan == jumlah_barang + 2) {
            restock_barang(barang, jumlah_barang);
        } else if (pilihan == jumlah_barang + 3) {
            printf("Terima kasih telah menggunakan mesin ini!\n");
            break;
        } else {
            beli_barang(barang, pilihan);
        }

        printf("\nIngin melanjutkan? (y/n): ");
        scanf(" %c", &lanjut);
    } while (lanjut == 'y' || lanjut == 'Y');

    // Bebaskan memori
    free(barang);
    return 0;
}
