#include <stdio.h>

int main(){
int grade[5] = {84, 90, 78, 92, 88}, i, newname, newgrade;
char choise[3];
char name[5][20] = {"Alice", "Bob", "Charlie", "David", "Eva"};

printf("Daftar Nama dan Nilai Siswa (before): \n");
 for (i = 0; i < 5; i++){
    printf("%s = %d\n", name[i], grade[i]);
 }
  
    printf("\nApakah anda ingin mengubah Nilai(Y/N): ");
    scanf("%s", choise);
    printf("\n");
    if (choise[0] == 'y' || choise[0] == 'Y'){
    for (i = 0; i < 5; i++){
        printf("%s = %d\n", name[i], grade[i]);
     } 
    } else {
      return 1;
   }

    printf("\nPilih Siswa yang ingin Diubah Nilainya(1-5): ");
    scanf("%d", &newname);

    printf("\nUbah Nilai %s: ", name[newname - 1]);
    scanf("%d", &newgrade);

    grade[newname -1] = newgrade;

printf("\nDaftar Nama dan Nilai Siswa (after): \n\n");
    for (i = 0; i < 5; i++){
        printf("%s = %d\n", name[i], grade[i]);
     }

return 0;
}
