#include <stdio.h>
#include <stdlib.h>

void faktorial(int n){
    int result = 1;
    for (int i = 1; i <= n; i++){
        result *= i;
    }
    printf("Faktorial dari %d adalah: %d", n, result);
}

void fibo(int p){
    int a = 0, b = 1, c;
    for (int i = 0; i < p; i++){
        printf("Deret Fibbonacci Ke-%d adalah: %d\n", i+1, a);
        c = a + b;
        a = b;
        b = c;
    }
    printf("\n");
}

int main(){
    int n, p;

    printf("\nMasukkan Angka Untuk menghitung Faktorial: ");
    scanf("%d", &n);
    faktorial(n);

    printf("\n\nMasukkan Angka Untuk Menghasilkan Fibbonacci: ");
    scanf("%d", &p);
    fibo(p);
    system("pause");
    return 0;
}