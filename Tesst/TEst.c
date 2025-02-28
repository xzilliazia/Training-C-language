#include <stdio.h>

int main() {
    char gender;
    int tinggi_badan;

    printf("Masukkan Gender anda (Male/Female): ");
    scanf("%c", &gender);

if (gender == 'M' || gender == 'm'){
    printf("Male\n");
    printf("Masukkan Tinggi badan anda: ");
    scanf("%d", &tinggi_badan);
    if (tinggi_badan >= 163){
        printf("\nanda di atas rata rata");
    } else {printf("\nAnda rata rata");}
    }


if (gender == 'F' || gender == 'f'){
    printf("Female");
    printf("Masukkan Tinggi badan anda: ");
    scanf("%d", &tinggi_badan);
    if (tinggi_badan >= 155){
        printf("\nanda di atas rata rata");
    } else {
        printf("\nAnda rata rata");
    }
}
}
