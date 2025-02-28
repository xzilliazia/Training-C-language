#include <stdbool.h> 
#include <string.h> 
#include <stdio.h> // kurang menambahkan stdio untuk printf 

int main() { 
    // Boolean tulisan dalam c itu bool
    bool isTrue = true; 
    bool isFalse = false; 
 
    printf("Boolean values:\n"); 
    printf("isTrue: %d\n", isTrue); // kurang alamat
    printf("isFalse: %d\n", isFalse); 
 
    // Strings 
    char str1[] = "Hello"; 
    char str2[10]; 
    strcpy(str2, str1); // harusnya strcpy bukan strcopy
 
    printf("\nStrings:\n"); 
    printf("str1: %s\n", str1); //harusnya str1 dan str2 saja sesuai nama variable diatas
    printf("str2: %s\n", str2); 
 
    // Pointers 
    int num = 42; 
    int *ptr = &num; 
 
    printf("\nPointers:\n"); 
    printf("Value of num: %d\n", num); //kurang nama variable
    printf("Address of num:  \n", &num); //cetak menggunakan format apa?
    printf("Value of ptr:   \n", ptr); //cetak menggunakan format apa?
    printf("Value pointed by ptr: %d\n",   ); // dari mana?
 
    return 0; 
}