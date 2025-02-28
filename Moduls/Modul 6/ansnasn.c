#include <stdio.h>
#include <stdlib.h>

// Fungsi untuk menghitung faktorial
int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Fungsi untuk mencetak deret Fibonacci
void fibonacci(int p) {
    int a = 0, b = 1, c;
    for (int i = 0; i < p; i++) {  // Deklarasi variabel di dalam for-loop (fitur C99)
        printf("Deret Fibonacci Ke-%d adalah: %d\n", i + 1, a);
        c = a + b;
        a = b;
        b = c;
    }
}

int main() {
    int n;

    // Meminta input dari pengguna
    printf("Masukkan angka untuk menghitung faktorial: ");
    scanf("%d", &n);

    // Menampilkan hasil faktorial
    printf("Faktorial dari %d adalah: %d\n", n, factorial(n));

    // Menampilkan deret Fibonacci
    printf("\nMenampilkan %d angka pertama dari deret Fibonacci:\n", n);
    fibonacci(n);

    system("pause");
    return 0;
}