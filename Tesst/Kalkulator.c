#include <stdio.h>

int main()
{
    int a, b;
    printf("Masukan dua angka: ");
    scanf("%d %d", &a, &b);

    int sum = a + b;
    printf("Penjumlahan: %d\n", sum);

    int difference = a - b;
    printf("Pengurangan: %d\n", difference);

    int product = a * b;
    printf("Perkalian: %d\n", product);

    if (b != 0){
        float division = (float) a/b;
        printf("Pembagian: %.1f\n", division);
    }
    else {
        printf("Eror: Pembagian dengan Nol\n");
    }

return 0;
}