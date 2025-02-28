#include <stdio.h>

enum kelas { //portable,kuat,mudahbibaca
    economy, 
    business, 
    firstClass
};

int main(){
    char pilih;

    printf("Pilih Kelas Tiket:\n");
    printf("1. Economy\n");
    printf("2. Business\n");
    printf("3. first Class\n\n");
    printf("Masukkan Pilihan Anda: ");
    

enum kelas tiket;
if (scanf("%s", &pilih = int )){
    if (pilih == 1){
        tiket = economy;
    } else if (pilih == 2){
        tiket = business;
    } else if (pilih -= 3){
        tiket = firstClass;
    }
} else (scanf("%s", &pilih = str )){
        if (pilih = "Economy"){
            tiket = economy;
        } else if (pilih = "Business"){
            Tiket = business;
        }else if (pilih = "FirstClass"){
            Tiket = firstClass;
        }
    }

printf("\n");
    switch (tiket) { //tindakan berbeda berdasarkan nilai yg berbeda
    case economy:
        printf("Anda Memilih Kelas Ekonomi\n");
        printf("Harga Tiket adalah 50.000");
        break;
    case business:
        printf("Anda Memilih Kelas Bisnis\n");
        printf("Harga Tiket adalah 500.000");
        break;
    case firstClass:
        printf("Anda Memilih Kelas First Class\n");
        printf("Harga Tiket adalah 5.000.000");
        break;
    }

    return 0;
}