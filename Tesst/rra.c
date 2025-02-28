#include <stdio.h>

int main() {
    int grade[5] = {84, 90, 78, 92, 88};  // Array nilai siswa
    int i, studentIndex, newGrade;
    char choise[3]; 
    char *name[5] = {"Alice", "Bob", "Charlie", "David", "Eva"};  // Array nama siswa

    printf("Daftar Nama dan Nilai Siswa (before): \n");
    for (i = 0; i < 5; i++) {
        printf("%s = %d\n", name[i], grade[i]);
    }

    do {
        // Menanyakan apakah ingin mengubah nilai
        printf("Apakah anda ingin mengubah Nilai(Y/N): ");
        fgets(choise, sizeof(choise), stdin);  // Membaca input sebagai string
        
        // Menghapus newline yang mungkin ada setelah input
        choise[strcspn(choise, "\n")] = '\0';  // Menghapus newline dari input

        // Jika pengguna memilih untuk mengubah nilai
        if (choise[0] == 'Y' || choise[0] == 'y') {
            // Jika memilih 'Y', minta untuk memilih siswa
            printf("Pilih siswa untuk diubah nilainya:\n");
            for (i = 0; i < 5; i++) {
                printf("%d. %s\n", i+1, name[i]);  // Menampilkan daftar siswa
            }
            
            // Validasi input untuk memilih nomor siswa (1-5)
            int valid = 0;
            while (!valid) {
                printf("Masukkan nomor siswa (1-5): ");
                if (scanf("%d", &studentIndex) != 1 || studentIndex < 1 || studentIndex > 5) {
                    printf("Input salah! Harap masukkan nomor siswa yang valid (1-5).\n");
                    while (getchar() != '\n');  // Menghapus karakter newline yang tersisa
                } else {
                    valid = 1;  // Jika input valid, keluar dari loop
                }
            }

            // Validasi input untuk memasukkan nilai baru (angka)
            valid = 0;
            while (!valid) {
                printf("Masukkan nilai baru untuk %s: ", name[studentIndex-1]);
                if (scanf("%d", &newGrade) != 1) {
                    printf("Input salah! Harap masukkan nilai yang valid.\n");
                    while (getchar() != '\n');  // Menghapus karakter newline yang tersisa
                } else {
                    valid = 1;  // Jika input valid, keluar dari loop
                }
            }

            // Mengupdate nilai siswa di array grade
            grade[studentIndex-1] = newGrade;  // Mengupdate nilai siswa
            printf("Nilai %s telah diperbarui menjadi %d.\n", name[studentIndex-1], newGrade);
        } else {
            // Keluar jika input 'N' atau 'n', atau input lainnya
            if (choise[0] == 'N' || choise[0] == 'n') {
                printf("Program selesai.\n");
                break;
            }
            // Jika input tidak 'N' atau 'n', lanjutkan ke langkah berikutnya
            printf("Melanjutkan...\n");
        }

        // Menampilkan daftar siswa dan nilai setelah update (jika ada)
        printf("\nDaftar Nama dan Nilai Siswa (after): \n");
        for (i = 0; i < 5; i++) {
            printf("%s = %d\n", name[i], grade[i]);
        }

        // Membersihkan buffer input setelah scanf
        while (getchar() != '\n');  // Menghapus karakter newline yang tersisa

    } while (1);  // Ulangi sampai pengguna memilih keluar dengan 'N'

    return 0;
}
