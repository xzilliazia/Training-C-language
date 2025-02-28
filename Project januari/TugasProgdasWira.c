#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

//untuk cursor dan dimensi
int curs1=0, curs2=0, dim1=5, dim2=5; 

//untuk perulangan for
int i,j,k; 

//untuk controll
int ch, enter=13, esc=27, S=115, W=119, D=100, A=97;

//unthk situasi tertentu
int abai=0,con=1; 

//untuk settings
int colorChoice = 0;
char color [4][15]={"\x1b[31m","\x1b[33m","\x1b[32m","\x1b[34m"};
int sizeX=3, sizeY=3;

//untuk play
void panel();
int ii=0, jj=0, kk=0;
char mode[9]= "random";
int soalX[30]; int soalY[30];

//fungsi general
char currentMenu[20] = "mainMenu";
void menu();
void tampilkanTeks(char *arr, char *isi, int kata, int huruf);
void controll();
int interaksi(int tombol, int posisi1, int posisi2, char *pindah);
void resetCursor(); void skip();

//untuk file handle
FILE *dataGame;
void load();
void save();
int point;
char character;
char nama[30];

//fungsi & variabel tambahan
int randomNum(int a, int b, int c);
void loading(int a, char *arr);
void keterangan();

//---------------------------------------------------------------------------------------------------------------------------------------------------------

int main(){	
	load();
	while(1){	
		menu();
		controll();
		system("cls");
	}
	return 0;
}

void menu(){
	if(strcmp(currentMenu, "mainMenu") == 0){
		printf("------------MAIN MENU!!------------\n");
		char isiMainMenu [5][15] = {"PLAY ","SETTINGS ","TUTORIAL", "HISTORY", "EXITS"};
		tampilkanTeks("kebawah", *isiMainMenu, 5, 15);keterangan();
		//----------------------------------------------------------------
		interaksi(enter, 0, 0, "play");
		interaksi(enter, 1, 0, "settings");
		interaksi(enter, 2, 0, "tutorial");
		interaksi(enter, 3, 0, "history");
		interaksi(enter, 4, 0, "exit");
	}
	
	else if(strcmp(currentMenu, "settings") == 0){ 
		printf("------------SETTINGS!!------------\n");
		char isiSettings[3][11] = {"COLOR ","SIZE ","RESET DATA"};
		tampilkanTeks("kebawah", *isiSettings, 3, 11); keterangan();
		//----------------------------------------------------------------
		interaksi(enter, 0, 0, "color");
		interaksi(enter, 1, 0, "size");
		if(interaksi(enter,2,0,"settings")==1){remove("dataGame.txt");remove("dataGame1.txt"); point=0;}
		interaksi(esc, curs1, curs2, "mainMenu");
	}
	
	else if(strcmp(currentMenu, "tutorial") == 0){ 
		printf("------------TUTORIAL!!------------\n");
		printf("Dalam permainan ini, anda disuruh untuk mengingat pola yang diberikan.\nJika pola pertama ada di koordinat (1,3)\nmaka di percobaan pertama anda harus mengarahkan kursor dan menekan enter di lokasi itu.\nBegitu pula di pola yang kedua dan seterusnya\nSelamat bermain!!");
		keterangan();
		//----------------------------------------------------------------
		interaksi(esc, curs1, curs2, "mainMenu");
	}
	
	else if(strcmp(currentMenu, "play") == 0){ 
		if(con==1){con=0; loading(3, "ARE YOU READY??"); printf(" GO!!"); Sleep(750); system("cls");}
		//----------------------------------------------------------------
		panel();
		//----------------------------------------------------------------
		if(interaksi(esc, curs1, curs2,"mainMenu")==1){ii=0; jj=0;}
	}
	
	else if(strcmp(currentMenu, "color") == 0){ 
		printf("------------PLIH WARNA!!------------\n"); 
		char isiColor[4][25] = {"[MERAH]  ","[KUNING]  ","[HIJAU]  ", "[DI LANGIT YANG BIRU]"};
		tampilkanTeks("kesamping", *isiColor, 4, 25); keterangan();
		//----------------------------------------------------------------
		if(interaksi(enter,0,0,"color")==1){colorChoice=0;}
		if(interaksi(enter,0,1,"color")==1){colorChoice=1;}
		if(interaksi(enter,0,2,"color")==1){colorChoice=2;}
		if(interaksi(enter,0,3,"color")==1){colorChoice=3;}
		interaksi(esc, curs1, curs2, "settings");
	}
	
	else if(strcmp(currentMenu, "exit") == 0){
		printf("apakah anda yakin ingin keluar??\n");
		char isiExit[2][10] = {"[Tidak]", "[Ya]"};
		tampilkanTeks("kesamping", *isiExit, 2, 10);
		//----------------------------------------------------------------
		interaksi(enter,0,0,"mainMenu");
		interaksi(esc, curs1, curs2, "mainMenu");
		if(interaksi(enter,0,1,"exit") == 1){printf("\nterimakasih telah bermain!"); exit(1);}
	}

	else if(strcmp(currentMenu, "gameOver")==0){
		printf("Silahkan masukan nama anda: %s\n", nama);
		printf("Apakah anda ingin bermain lagi??\n");
		char isiGameOver[3][15] = {"[MAIN MENU]", "[COBA LAGI]", "[EXIT PROGRAM]"};
		tampilkanTeks("kesamping", *isiGameOver, 3, 15);
		//----------------------------------------------------------------
		interaksi(enter,0,0,"mainMenu");
		interaksi(enter,0,1,"play");
		interaksi(enter,0,2, "exit");
	}
	else if(strcmp(currentMenu, "size")==0){
		if(con==1){
			con=0;
			printf("Masukan panjang (1-10): "); scanf("%d", &sizeX); sizeX--;
			printf("Masukan tinggi (1-5): "); scanf("%d", &sizeY); sizeY--; 
			if((sizeX>0 && sizeX<10 && sizeY>0 && sizeY<6) || (sizeX==0 && sizeY>0 && sizeY<6) || (sizeY==0 && sizeX>0 && sizeX<6)){
				printf("Size berhasil di ubah! Silahkan kembali ke menu pengaturan!");
			}else{
				printf("Masukan angka yang benar!! coba lagi!");
				con=1;	
			}	
		}
		//----------------------------------------------------------------
		interaksi(esc, curs1, curs2, "settings");
	}
	else if(strcmp(currentMenu, "history")==0){
		dataGame = fopen("dataGame1.txt", "r");
		if (dataGame == NULL){
			printf("Belum ada data, silahkan main dulu untuk menambahkan data!");
		}else{
			while ((character = fgetc(dataGame)) != EOF) {
		        printf("%c", character);
		    }
		}
	    fclose(dataGame);
	    //----------------------------------------------------------------
	    interaksi(esc, curs1, curs2, "mainMenu");
	}
}

void tampilkanTeks(char *arr, char *isi1, int kata, int huruf){
    char nl[2];
	if(strcmp(arr, "kesamping") == 0){dim1=0;dim2=kata-1; strcpy(nl,"  ");}
	else if(strcmp(arr, "kebawah") == 0){dim2=0; dim1=kata-1;strcpy(nl,"\n");}
	int arahC=curs1+curs2;
	for(i=0;i<kata;i++){
		char *isi2 = (isi1 + i * huruf);
		if(i == arahC){
			printf("%s", color[colorChoice]);
		}printf("%s%s\x1b[0m", isi2, nl);
	}
}

void controll(){
	if(abai == 0){	
		ch = getch();
		if(ch == S && curs1 < dim1){ //S BUTTON
			curs1++;
		}else if(ch == W && curs1 > 0){ //W BUTTON
			curs1--;
		}else if(ch == D && curs2 < dim2){ //D BUTTON
			curs2++;
		}else if(ch == A && curs2 > 0){ //A BUTTON)
			curs2--;
		}
	}abai=0;
}

int interaksi(int tombol, int posisi1, int posisi2, char *pindah){
	if(ch == tombol){
		if(curs1 == posisi1 && curs2 == posisi2 && strcmp(currentMenu, pindah) != 0){ //cursor benar + pindah menu + aksi
			strcpy(currentMenu, pindah); skip(); resetCursor(); con=1;  return 1;
		}else if(curs1 == posisi1 && curs2 == posisi2 && strcmp(currentMenu, pindah) == 0){ //cursor benar + aksi
			skip(); return 1;
		}else if((curs1 != posisi1 || curs2 != posisi2) && strcmp(currentMenu, pindah) == 0){ //cursor salah + aksi
			return 2;
		}
	}return 0;
}

void save(){
	time_t mytime;
    mytime = time(NULL);
    dataGame = fopen("dataGame.txt", "w");
    fprintf(dataGame, "%d", point);
    fclose(dataGame);
    dataGame = fopen("dataGame1.txt", "a");
    fprintf(dataGame, "************************\n%s\nNama: %s\nSkor: %d\nSize: %dx%d\n", ctime(&mytime), nama, ii-1, sizeX+1, sizeY+1);
    fclose(dataGame);
}
void load(){
    dataGame = fopen("dataGame.txt", "r");
    fscanf(dataGame, "%d", &point);
    fclose(dataGame);
}

void resetCursor(){
	curs1=0; curs2=0;
}
void skip(){
	abai=1; ch=0;
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------

int randomNum(int a, int b, int c){
	srand(time(NULL) + c);
	return (rand()% b) + a;
}

void keterangan(){
	printf("\n\n\nTekan WASD untuk mengontrol cursor\nTekan ESC untuk kembali ke menu sebelumnya\nTekan Enter untuk mengkonfirmasi pilihan\nPOINT ANDA: %d", point);
	//printf("\n\n\n\nNama: Wira Yudha\nNIM: 2023103370311010\nINFORMATIKA UMM\nIni adalah program yang saya buat menggunakan bahasa C\nuntuk membuat suatu tampilan interaktif menu, dimana user\nbisa mengubah source code nya dan membuat tampilan main menu\napa saja sesuai keinginanya, namun dalam source code ini\nsaya membuat main menu untuk game sederhana!");
}

void loading(int a, char *arr){
	system("cls"); printf("%s", arr);
	for(i=0;i<a;i++){
		printf(" %d",i+1); Sleep(500);
	}
}

void panel(){
	if(strcmp(mode, "random")==0 && jj<=ii){ // nampilin soal sesuai level
		soalX[ii]=randomNum(0,sizeX+1,0); soalY[ii]=randomNum(0,sizeY+1,1);
		curs1=soalY[jj]; curs2=soalX[jj]; 
	}
	
	printf("------------PLIH DENGAN URUTAN YANG BENAR!!------------\n");
	char b[20]="oooooooooo    "; dim1=sizeY; 
	char bb[20]="o        o    "; dim2=sizeX;
	for(i=0; i<=sizeY; i++){ 
		for(j=0;j<=sizeX;j++){
			if(j == curs2 && i == curs1){
				printf("%s", color[colorChoice]);
			}printf("%s\x1b[0m", b);				
		}printf("\n");
		for(j=0; j<3; j++){
			for(k=0;k<=sizeX;k++){
				if(k == curs2 && i == curs1){
				   	printf("%s", color[colorChoice]);
				}printf("%s\x1b[0m", bb);	
			}printf("\n");
		}
		for(j=0;j<=sizeX;j++){
			if(j == curs2 && i == curs1){
				printf("%s", color[colorChoice]);
			}printf("%s\x1b[0m", b);				
		}printf("\n\n"); 
	}printf("LEVEL %d\n", ii);
	
	if(strcmp(mode, "random")==0){ //kasih sound fx
		Beep(900,250); Sleep(500); skip(); jj++; 
		if(jj>ii){strcpy(mode, "pilih"); jj=0; ii++; resetCursor();} //masuk ke mode pilih jika soal sudah ditampilkan sesuai level
	}
	else if(strcmp(mode, "pilih")==0){ //main
		if(jj<ii){ //pilih sebanyak berapa kali sesuai level
			if(interaksi(enter, soalY[jj], soalX[jj], "play")==1){ //kalau benar
				Beep(900,250); jj++; skip();
			}
			else if(interaksi(enter, soalY[jj], soalX[jj], "play")==2){ //kalau salah
				printf("SALAH!!"); Sleep(1000);
				Beep(500,400); skip(); resetCursor(); system("cls");
				printf("Silahkan masukan nama anda: "); scanf(" %[^\n]s", nama);
				point+=ii-1; 
				save(); ii=0; jj=0;
				//strcpy(mode, "random");
				interaksi(ch,curs1,curs1,"gameOver");
			}
		}
		else{
			printf("BENAR!!"); Sleep(1000);
			strcpy(mode, "random"); jj=0; skip();
		}
	}
}