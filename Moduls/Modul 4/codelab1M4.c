#include <stdio.h>

int main(){
    int angka, total = 0, jumlah = 0;
    float rata = 0.0;

    printf("Masukkan Bilangan Bulat(Negatif Number to stop): ");
    scanf("%d", &angka);

while (angka >= 0){
    total += angka;
    jumlah++;
    printf("Masukkan Bilangan Bulat(Negatif Number to stop): ");
    scanf("%d", &angka);
}

rata = total / jumlah;
printf("Total Bilangan: %d\n", total);
printf("Rata-Rata Bilangan: %.2f\n", rata);
return 0;
}