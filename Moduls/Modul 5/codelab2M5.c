#include <stdio.h>

int main(){
int product [2][3] = {{5, 8, 6}, {3, 7, 9}};
int i, choise, count = 0;;
char name[3][2] = {"A", "B", "C"};

do {
    printf("\nToko mana Yang ingin anda Lihat Produknya\n");
    printf("Toko (1/2): ");
    scanf("%d", &choise);
switch (choise){
    case 1:
    printf("\nToko 1: \n");
    for (i = 0; i < 3; i++){
    printf("Produk %s = %d\n", name[i], product[0][i]);
 }
 count++;
 break;
    case 2:
    printf("\nToko 2: \n");
    for (i = 0; i < 3; i++){
    printf("Produk %s = %d\n", name[i], product[1][i]);
 }
 count++;
 break;
}

} while (count < 2);
printf("====================================================");
printf("\nTotal penjualan Per-Produk dari Toko 1 dan Toko 2: \n");
for (i = 0; i < 3; i++){
    printf("Produk %s = %d\n", name[i], product[0][i]+product[1][i]);
}
return 0;
}