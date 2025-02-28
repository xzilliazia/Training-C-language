#include <stdio.h>

int main(){
    float pertama;
    float kedua;
    float ketiga;
    float total;

printf("====Progam Penghitung Kalori Harian====\n\n");

printf("Masukkan Kalori Makanan Pertama: ");
scanf("%f", &pertama);
printf("Masukkan Kalori Makanan Kedua: ");
scanf("%f", &kedua);
printf("Masukkan Kalori Makanan Ketiga: ");
scanf("%f", &ketiga);
printf("\n");
total = pertama + kedua + ketiga;
printf("Total Kalori Hari ini: %.2f\n", total);

if (total >2500){
    printf("Kalori Melebihi Batas! Harap lebih diperhatikan");
}else
printf("Kalori hari ini tidak melebihi batas");

printf("\n\n----------Progam Sukses----------");
return 0;
}