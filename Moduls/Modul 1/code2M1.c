#include <stdio.h>

int main()
{
    char nama[50];// change () to [] and add nama for variable
    int umur;
    float gaji_pokok;

    printf("Masukkan nama: ");
    gets(nama);

    printf("Masukkan umur: ");
    scanf("%d", &umur); // if scanf you must add "&" before variable

    printf("Masukkan gaji pokok: ");
    scanf("%f", &gaji_pokok);// if scanf you must add "&" before variable

    float tunjangan = gaji_pokok * 0.1;
    float total_gaji = gaji_pokok + tunjangan;

    printf("Nama: %s\n", nama);
    printf("Umur: %d\n", umur);
    printf("Gaji Pokok: %.2f\n", gaji_pokok);
    printf("Tunjangan: %.2f\n", tunjangan);
    printf("Total Gaji: %.2f\n", total_gaji);

    return 0; //in function you must add return 0; in end
}
