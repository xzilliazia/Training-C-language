#include <stdio.h>
#include <string.h>

void swap(char* a, char* b){
    char temp[20];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}
void BubbleSort(char fruit[][20], int j){
    int x, y;
    for (x = 0; x < j - 1; x++){
        for (y = 0; y < j - x - 1; y++){
            if (strcmp(fruit[y], fruit[y+1]) > 0){
                swap(fruit[y], fruit[y+1]);
            }
        }
    }
}

int main (){
    int u, an = 1;

    printf("Masukkan jumlah buah: ");
    scanf("%d", &u);
    getchar();

    char fruit[u][20];
    
int i;
for (i = 0; i < u; i++){
    printf("Masukkan Nama Buah Ke-%d: ", an++);
    scanf("%s", fruit[i]);
 }

printf("Sebelum Diurutkan:\n");
for (i = 0; i < u; i++){
    printf("%s\n", fruit[i]);
 }

BubbleSort(fruit, u);
printf("\n");

printf("Hasil Setelah diurutkan:\n");
for (i = 0; i < u; i++){
 printf("%s\n", fruit[i]);
 }
 

return 0;

}
