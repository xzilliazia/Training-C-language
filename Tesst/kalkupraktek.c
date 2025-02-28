#include <stdio.h>

int main() {
    char operator;
    double num1, num2, result;

    // Meminta input operator (karakter) dari pengguna
    printf("Masukkan operator (+, -, *, /): ");
    scanf("%c", &operator);  // Menggunakan %c untuk membaca karakter

    printf("Masukkan dua angka: \n");
    scanf("%lf %lf", &num1, &num2);

    // Melakukan operasi berdasarkan input operator
    if (operator == '+') {
        result = num1 + num2;
        printf("Hasil: %.2lf\n", result);
    } else if (operator == '-') {
        result = num1 - num2;
        printf("Hasil: %.2lf\n", result);
    } else if (operator == '*') {
        result = num1 * num2;
        printf("Hasil: %.2lf\n", result);
    } else if (operator == '/') {
        if (num2 != 0) {
            result = num1 / num2;
            printf("Hasil: %.2lf\n", result);
        } else {
            printf("Error: Pembagian dengan nol tidak diperbolehkan.\n");
        }
    } else {
        printf("Error: Operator tidak valid.\n");
    }

    return 0;
}
