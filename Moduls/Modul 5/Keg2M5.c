#include <stdio.h>

int main (){
//variable loop
 int i, j;
//banyak mahasiswa
 printf("Masukkan jumlah Mahasiswa: ");
 scanf("%d", &j);

 float value[j][3];
 float total = 0.0, total1 = 0.0, total2 = 0.0, total3 = 0.0;

//inputan dan penjumlahan
 for (i = 0; i < j; i++){
    printf("Masukkan nilai untuk mahasiswa ke-%d (Matematika, Fisika, Kimia): ", i+1);
    scanf("%f %f %f", &value[i][0], &value[i][1], &value[i][2]);
    total += value[i][0] + value[i][1] + value[i][2];
    total1 += value[i][0];
    total2 += value[i][1];
    total3 += value[i][2];
    while (getchar()!= '\n');
 }
//layout
 printf("================================\n");
 printf("Daftar Nilai Mahasiswa: \n");
 printf("Mahasiswa\t Matematika\t Fisika\t\t Kimia\n");
// Cetak Nilai
 for (i = 0; i < j; i++){
    printf("Mhs %d\t\t%.2f\t\t%.2f\t\t%.2f\n", i+1, value[i][0], value[i][1], value[i][2]);
 }
//rata rata
 float avr = total / (j*3);
 float avr1 = total1 / j;
 float avr2 = total2 / j;
 float avr3 = total3 / j;

//cetak avg
 printf("\nRata-rata Nilai: \n");
 printf("Matematika: %.2f\n", avr1);
 printf("Fisika: %.2f\n", avr2);
 printf("Kimia: %.2f\n", avr3);
 printf("Rata-rata Nilai Keseluruhan: %.2f\n", avr);

//avg tiap mahasiswa
 printf("===================\nRata-rata Nilai Per-mahasiswa: \n");
 for (i = 0; i < j; i++){
 float totalMhs = (value[i][0] + value[i][1] + value[i][2]) / 3.0;
 printf("Rata-rata Mhs %d: %.2f\n", i+1,totalMhs);
 }


return 0;
}