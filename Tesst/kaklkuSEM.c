#include <stdio.h>

int main()
{
    double num1, num2;
    double hasil;
    char operator;

    printf("Masukkan Angka dan (+, -,*, /): ");
    scanf("%lf %c %lf", &num1, &operator, &num2);

     if (operator == '+')
    {
    hasil = num1 + num2;
    printf("Hasil: %.2f", hasil);
    }

    else if (operator == '-') 
    {
    hasil = num1 - num2;
    printf("Hasil: %.2f", hasil);
    }

    else if (operator == '*')
    {
    hasil = num1 * num2;
    printf("Hasil: %.2f", hasil);
    }

    else if (operator =='/'){
        if (num2 != 0){
        hasil = num1 / num2;
        printf("Hasil: %.2f\n", hasil);
    }
    else {printf("eror: pembagian tidak valid");
    }
    }

return 0;
}