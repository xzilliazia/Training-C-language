#include <stdio.h>

int main(){
int grade[5] = {84, 90, 78, 92, 88};

printf("Daftar Nama dan Nilai Siswa (before): \n");
 printf("Alice: %d\n", grade[0]);
 printf("Bob: %d\n", grade[1]);
 printf("Charlie: %d\n", grade[2]);
 printf("David: %d\n", grade[3]);
 printf("Eva: %d\n", grade[4]);

grade[3] = 95;

printf("\nDaftar Nama dan Nilai Siswa (after): \n");
 printf("Alice: %d\n", grade[0]);
 printf("Bob: %d\n", grade[1]);
 printf("Charlie: %d\n", grade[2]);
 printf("David: %d\n", grade[3]);
 printf("Eva: %d\n", grade[4]);

return 0;
}