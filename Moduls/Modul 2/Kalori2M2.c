#include <stdio.h>

#define batas_kalori 2500

int main(){

    int makanan, i;
    float total, kalori = 0;

printf("===PROGAM PENGHITUNG KALORI HARIAN===\n\n");

printf("Masukkan jumlah makanan yang dimakan hari ini: ");
scanf("%d", &makanan);
printf("\n");
for (i = 1; i <= makanan; i++){
    printf("Masukkan Kalori makanan ke-%d: ", i);
    scanf("%f", &kalori);
    total += kalori;
}
printf("\n\n");
printf("Total Kalori Harian anda: %.2f\n", total);
if (total < batas_kalori){
    printf("Anda tidak melebihi batas harian sebesar %d kalori.", batas_kalori);
}else {
    printf("Anda melebihi batas kalori harian sebesar %d kalori.", batas_kalori);
}

printf("\n\n ====CODE EXECUTION SUCCESSFUL====");
 return 0;
}