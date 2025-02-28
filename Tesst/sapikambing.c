#include <stdio.h>

#define sapi_jantan_1 550.0
#define sapi_jantan_2 535.6
#define sapi_betina_1 498.23
#define sapi_betina_2 628.0

#define goat_jantan_1 120.0
#define goat_jantan_2 85.8
#define goat_betina_1 23.0


int main()
{
    int pilih;
    //float weight;
    float hasil_sapi, hasil_goat;

    printf("1. Sapi\n");
    printf("2. Kambing\n");
    printf("Pilih: ");
    scanf("%d", &pilih);

hasil_sapi = sapi_jantan_1 + sapi_jantan_2 + sapi_betina_1 + sapi_betina_2;
hasil_goat = goat_jantan_1 + goat_jantan_2 + goat_betina_1;

if (pilih == 1){
    printf("Hasil berat sapi: %.2f Kg\n", hasil_sapi);
}
else if (pilih == 2){
    printf("Hasil berat kambing: %.2f Kg\n", hasil_goat);
}

return 0;
}

