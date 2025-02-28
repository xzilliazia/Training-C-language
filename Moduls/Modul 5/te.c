#include <stdio.h>

int main(){
int product [2][3] = {{5, 8, 6}, {3, 7, 9}};
int i, choise, count = 0;;
char *name[3] = {"A", "B", "C"};

    printf("\nToko 1: \n");
    for (i = 0; i < 3; i++){
    printf("Produk %s = %d\n", name[i], product[0][i]);
    }
 
    printf("\nToko 2: \n");
    for (i = 0; i < 3; i++){
    printf("Produk %s = %d\n", name[i], product[1][i]);
    }
 
printf("\n====================================================\n");
printf("\nTotal penjualan Per-Produk dari Toko 1 dan Toko 2: \n");
for (i = 0; i < 3; i++){
    printf("Produk %s = %d\n", name[i], product[0][i]+product[1][i]);
}
return 0;
}