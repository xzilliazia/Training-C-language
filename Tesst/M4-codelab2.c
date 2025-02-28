#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, j;
    int unique;

    printf("Masukkan sebuah string: ");
    scanf("%[^\n]s", str);

    printf("Karakter unik: ");
    for (i = 0; str[i] != '\0'; i++) {
		unique = 1; 
        for (j = 0; j < i; j++) { 
            if (str[i] == str[j]) {  
                unique = 0; 
                break;
            }
        }
        if (!unique) continue; // Melompat ke iterasi berikutnya jika karakter sudah pernah muncul
        printf("%c", str[i]);
    }
return 0;
}