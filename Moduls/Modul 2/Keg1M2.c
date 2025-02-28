#include <stdio.h>

#define PI 3.14159
#define AREA_CIRCLE(r) (PI * (r) * (r))
#define circumf(r) (2 * PI * (r))

int main() {
    float radius;

printf("=====Progam Penghitung Luas dan Keliling LIngkaran=====\n\n");

    printf("Masukkan Radius lingkaran: ");
//Cek apakah input angka atau huruf
if(scanf("%f", &radius) !=1){
    printf("Invalid. Radius harus angka.\n");
    return 1;
}
//cek apakah input radius bilangan positif atau tidak
if (radius <= 0){
    printf("Input tidak valid. Radius harus bilangan positif.\n");
    return 2;
}
printf("\n-HASIL-\n");
    printf("Luas lingkaran adalah: %.2f\n", AREA_CIRCLE(radius));
    printf("Keliling lingkaran adalah: %.2f", circumf(radius));

printf("\n\n=====Progam Berhasil Berjalan=====");
    return 0;
}