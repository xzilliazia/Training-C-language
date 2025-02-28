#include <stdio.h>

int main(){
    int angka, total=0;
    float rata = 0.0;
    float jumlah;

while (1){
    printf("Masukkan Bilangan Bulat(Negatif Number to stop): ");
    if (scanf("%d", &angka)!=1){
    printf("Input Invalid.Masukkan bilangan bulat\n");
    while(getchar() != '\n');
    continue;
    }
    if (angka < 0){
    break;
 }
    total += angka;
    jumlah++;
 }

printf("\n\n");
rata = total / jumlah;
printf("Total Bilangan: %d\n", total);
printf("Rata-Rata Bilangan: %.2f\n", rata);

return 0;
}