#include <stdio.h>
int main()
{
	char nama[50];
long long int nim;
int nilai_tugas;
int nilai_uts;
int nilai_uas;
float nilai_akhir;

printf ("n/---program penghitungan nilai akhir---");
printf("n/Masukan nama mahasiswa\t:"); gets(nama);
printf("n/Masukan nim mahasiswa\t:"); scanf("%lld",&nim);
printf("n/Masukan nilai tugas\t:"); scanf("%d",&nilai_tugas);
printf("n/Masukan nilai uts\t:"); scanf("%d",&nilai_uts);
printf("n/Masukan nilai uas\t:"); scanf("%d",&nilai_uas);

printf("n/----------------------------------------------------");
printf("n/nama mahasiswa /t:%s", nama );
printf("n/nim mahasiswa /t:%lld", nim );
printf("n/nilai tugas /t:%d", nilai_tugas );
printf("n/nilai uts /t:%d", nilai_uts );
printf("n/nilai uas /t:%d", nilai_uas );
nilai_akhir=(float) nilai_tugas * 0.2 +nilai_uts * 0.35 + nilai_uas * 0.45 ;
printf("n/nilai akhir /t:%.2f", nilai_akhir );
("n/-----------------------------------------------------------");
return 0;
}