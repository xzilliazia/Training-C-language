#include <stdio.h>
#include <ctype.h>

int main(){
    float money, total = 0.0;
    char repeat[5];
    int i;
do {
    while (1){
        printf("\n--PENCATATAN TRANSAKSI--\n\n");
        printf("\nGunakan NOL(0) Untuk Menyelesaikan\nMasukkan Nilai Transaksi: ");
        scanf("%f", &money);
        for (i = 0; money[i] != '\0'; i++){
            if (isdigit(money[i])){
            printf("\nInvalid\ninput Harus Angka!!\n");
            while (getchar() != '\n');
            continue;
         }
        }
        if (money == 0){
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