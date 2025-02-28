#include <stdio.h>

int main()
{
    double num1;
    double num2;
    double hasil;
    char operator;

    printf("Masukkan angka pertama: ");
    scanf("%lf", &num1);
    printf("Masukkan angka kedua: ");
    scanf("%lf", &num2);
    
    printf("Masukkan Operator (+, -, *, /): ");
    scanf(" %c", &operator);

    if (operator == '+')
    { hasil = num1 + num2;
    printf("Hasil: %.2f", hasil);
    } else if (operator == '-') 
    { hasil = num1 - num2;
    printf("Hasil: %.2f", hasil);
    } else if (operator == '*')
    { hasil = num1 * num2;
    printf("Hasil: %.2f", hasil);
    } else if (operator =='/'){
        if (num2 != 0){
        hasil = num1 / num2;
        printf("Hasil: %.2f\n", hasil);
    }
    else {printf("eror: pembagian tidak valid");
    }
    }

return 0;
}