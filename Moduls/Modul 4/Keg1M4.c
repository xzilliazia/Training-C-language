#include <stdio.h>

int main(){
    float money, total;
    char repeat[5];

do {
    total = 0.0;
    while (1){
        printf("\n---------PENCATATAN TRANSAKSI---------\n\n");
        printf("\nGunakan NOL(0) Untuk Menyelesaikan\nMasukkan Nilai Transaksi: ");
        if (scanf("%f", &money) != 1){ 
            printf("\nInvalid\ninput Harus Angka!!\n");
            while (getchar() != '\n');
            continue;
        }
        
    if (money <= 0) {
        if (money < 0) {
            printf("\nNilai transaksi tidak boleh negatif!\n");
            continue;
        }
         break;
        }
        total += money;
        printf("\nTotal Transaksi Tersebut Adalah: %.2f\n", total);
        
    }
    while (getchar() != '\n');

    printf("\nApakah Anda ingin mencatat Transaksi Baru (Ya)(tidak): ");
    fgets(repeat, sizeof(repeat), stdin);

} while (repeat[0] == 'y' || repeat[0] == 'Y');


printf("\n\n\tTerima Kasih\n---- Code Execution Successful ----");

    return 0;
}