#include <stdio.h>
#include <ctype.h>
//enum film dan tiket
  enum Film { SPIDERMAN, BATMAN, SUPERMAN, AVENGERS, JOKER };
  enum Tiket { REGULER, VIP, VVIP };

int main() {//deklarasi 
  int pilihan_film, pilihan_tiket, Jumlah_tiket; 
  char member [5]; //array yg bisa menyimpan ...
  float total = 0, totalsem = 0, dibayar; //Menghitung total

  //list harga
  float list_harga_film[5] = {50000, 55000, 60000, 70000, 45000}; //array simpan harga 
  float list_harga_tiket[3] = {30000, 100000, 150000};


printf("======== Bioskop =======\n");
//film
  printf("Film:\n");
    printf("1. Spiderman - Rp.50.000\n");
    printf("2. Batman - Rp.55.000\n");
    printf("3. Superman - Rp.60.000\n");
    printf("4. Avengers - Rp.70.000\n");
    printf("5. Joker - Rp.45.000\n");
    //pilihan film
    printf("FILM Yang ingin anda Tonton(1~5): ");
    scanf("%d", &pilihan_film);
    if (pilihan_film < 1 || pilihan_film > 5){ //jika input duluar yg diharapkan
    printf("Pilihan Tidak Valid\n");
    return 1;
  }

//tiket
  printf("\nTiket:\n");
    printf("1. Reguler - Rp.30.000\n");
    printf("2. VIP - Rp.100.000\n");
    printf("3. VVIP - Rp.150.000\n");
    //pilihan tiket
    printf("Pilih Tiket yang anda inginkan (1~3): ");
    scanf("%d", &pilihan_tiket);
    printf("Berapa Tiket yang ingin anda Pesan: ");
    scanf("%d", &Jumlah_tiket);
    if (pilihan_tiket < 1 || pilihan_tiket > 3){
    printf("Pilihan Tidak Valid\n");
    return 1;
  }

//total seb diskon
  totalsem = list_harga_film[pilihan_film -1] + (list_harga_tiket[pilihan_tiket -1] * Jumlah_tiket);
printf("\n");
  switch (pilihan_film){
    case 1:
    printf("Anda Memilih film Spiderman\n");
    break;
    case 2:
    printf("Anda Memilih film Batman\n");
    break;
    case 3:
    printf("Anda Memilih film Superman\n");
    break;
    case 4:
    printf("Anda Memilih film Avengers\n");
    break;
    case 5:
    printf("Anda Memilih film Joker\n");
    break;
    default:
    printf("Pilihan Invalid \n");
    return 1;
  }
  switch (pilihan_tiket){
    case 1:
    printf("Anda Memilih Reguler Tiket\n");
    break;
    case 2:
    printf("Anda Memilih VIP Tiket\n");
    break;
    case 3:
    printf("Anda Memilih VVIP Tiket\n");
    break;
    default:
    printf("Pilihan Invalid \n");
    return 1;
  }                                                                                //Kenapa harus -1 karena index array dimulai dari 0                                                                                  //dan tidak dapat diubah
  printf("\nTotal Harga Sementara Rp.%.2f\n", totalsem);
                                                                                  //walaupun anda memberi nilai 1 pada enum
                                                                                  //index array tetap dimulai dari 0
// Member                                                                                  
  printf("Apakah Anda MEMBER (Y/N): ");
  scanf("%s", member);
//menghilangkan buffer
int clear;
while ((clear = getchar()) != '\n' && clear != EOF){}

char member_ch = member [0];
  if (!isalpha(member_ch )){
    printf("Input Tidak Valid. \nHarap Masukkan Y atau N");
    printf("\n\n==========Progam Dihentkan==========\n");
    return 1;
    }
//yes no
  if (member_ch  == 'y' || member_ch  == 'Y'){
    total = totalsem * 0.9;
    printf("\nSelamat Anda Mendapatkan Diskon Member sebesar 10%%"); //diskon!!
    } else if (member_ch  == 'n' || member_ch  == 'N'){
    total = totalsem;
    printf("Anda Bukan Member, Tidak Mendapatkan Diskon");
    } else {
    printf("Input Tidak Valid\n");
    return 1;
    }

//total setelah diskon
  printf("\n\n!! Harap Membayar Tagihan Dibawah ini !!");
  printf("\nTotal Harga: Rp. %.2f\n", total);
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");

//Pembayaran
  printf("\nMasukkan Jumlah Pembayaran: Rp.");
  if (scanf("%f", &dibayar) != 1 ){
  printf("\nInput Tidak Valid untuk Pembayaran.");
  return 1;
  }

float tambah; //menambah input pembayaran
int kesempatan; //untuk membayar

// pembayaran biasa
/*
if (dibayar < total){                                                            //bisa menggunakan while atau for untuk mengulang sisa tagihan 
  printf("\nSisa Tagihan Anda Rp. %.2f\n", total - dibayar);
  printf("Masukkan Jumlah Pembayaran: ");// sisa tagihan
  scanf("%f", &tambah);
  dibayar += tambah;
  }
*/
//Ini pembayaran loop
/**/
if (dibayar < total){
  printf("Kesempatan Melunasi Tagihan anda adalah 3 kali !!!\n");
  for (kesempatan = 1; kesempatan <=3; kesempatan++){
    printf("\nSisa Tagihan Anda Rp.%.2f\n", total - dibayar);
    printf("Masukkan Jumlah Pembayaran: Rp.");
  
  if (scanf("%f", &tambah) !=1 ){
    printf("input tidak valid");
    return 1;
  }
 dibayar += tambah;
 if (dibayar >= total){
 break;
  }
 }
}/**/
printf("Alamat Memori Total: %p\n", &total);
if (dibayar == total){
  printf("\nPembayaran Berhasil. \nSemoga Harimu Cerah\n");
  } else if (dibayar > total){
  printf("\nKembalian Anda Sebesar Rp.%.2f\n", dibayar - total);
  } else if (dibayar < total){
    printf("\nSisa Tagihan anda sebesar Rp. %.2f", total - dibayar);
    printf("\nSILAHKAN LANJUTKAN PEMBAYARAN DI KASIR\n\n");
  }

printf("\n~~~~~~~~~~~~~TERIMA KASIH~~~~~~~~~~~~~");
  return 0;
}