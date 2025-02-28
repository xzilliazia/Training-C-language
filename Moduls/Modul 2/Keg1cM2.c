#include <stdio.h>

#define PI 3.14159

int main() {
    int pilihan;
    float radius, area, circum;

printf("=====Progam Penghitung Luas Dan Keliling Lingkaran=====\n\n");

    printf("1. Hitung Luas Lingkaran\n");
    printf("2. Hitung Keliling Lingkaran\n\n");
    printf("Pilih no: ");
    scanf("%d", &pilihan);
    
    printf("Masukkan Jari-Jari: ");
    if(scanf("%f", &radius)!=1){
        printf("Invalid. jari-jari harus angka!!");
        return 1;
    }
    if (radius <= 0){
        printf("Input tidak valid. Radius harus bilangan positif.\n");
        return 2;
    }
    area = PI * radius * radius;
    circum = 2 * PI * radius;

if(pilihan == 1){
    printf("Luas Lingkaran: %.2f", area);
}
else if (pilihan == 2){
    printf("Keliling Lingkaran: %.2f", circum);
}
printf("\n\n=====Progam Berhasil Dijalankan=====");
printf("\n|^-^||^-^||^-^||^-^||^-^||^-^||^-^||^-^|\n");

    return 0;
}