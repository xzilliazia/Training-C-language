#include <stdio.h>

void ubahNilai(int *p) {
    *p = 20;  // Mengubah nilai variabel melalui pointer
}

int main() {
    int x = 10;
    printf("Nilai x sebelum: %d\n", x);
    ubahNilai(&x);  // Mengirimkan alamat x ke fungsi ubahNilai
    printf("Nilai x sesudah: %d\n", x);
    
    return 0;
}
