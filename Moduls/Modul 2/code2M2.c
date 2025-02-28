#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
    // Boolean values   //1
    bool flagTrue = true;
    bool flagFalse = false;

    printf("Boolean values demonstration:\n");
    printf("flagTrue: %d\n", flagTrue);  //2
    printf("flagFalse: %d\n", flagFalse);  

    // String operations
    char greeting[] = "Hello, World!";
    char copyGreeting[20];
    strcpy(copyGreeting, greeting);  //3

    printf("\nString operations:\n");       //4
    printf("Original greeting: %s\n", greeting);  
    printf("Copied greeting: %s\n", copyGreeting);  

    // Pointer demonstrations
    int number = 100;
    int *pointer = &number;

    printf("\nPointer demonstrations:\n");
    printf("Value of number: %d\n", number);  //5
    printf("Address of number: %x\n", &number);
    printf("Value of pointer: %p\n", pointer);
    printf("Value pointed by pointer: %d\n", *pointer); //6

    return 0;
}