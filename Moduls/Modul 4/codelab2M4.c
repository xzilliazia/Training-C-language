#include <stdio.h>
#include <string.h>

int main(){
    char strings[20], hasil[20];
    int ch, j = 0;

    printf("Masukkan Kalimat atau Kata: ");
    fgets(strings, sizeof(strings), stdin);

for (ch = 0; ch < strlen(strings); ch++){
    if (strchr(hasil, strings[ch]) != NULL){
        continue;
    }

    hasil[j++] = strings[ch];
    printf("%c ", strings[ch]);

    if (j >= 10){
    break;
    }
 }

printf("\n");
return 0;
}