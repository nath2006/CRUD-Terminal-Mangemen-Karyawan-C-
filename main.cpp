#include <iostream>
#include <conio.h>
#include <cstring>
#include <cstdlib>
#include <cstdio>
	#if _WIN32
		#include <Windows.h>
	#elif _WIN64
		#include <Windows.h>
	#else
		#include <unistd.h>
	#endif


using namespace std;
    //variabel untuk biodata lengkap karyawan
        char nama[30];
        char id[5];
        char jabatan[30];
        int umur;
        int pengalaman;
        int gaji;

//functiion clear agar fungsi clear bisa dipakai di berbagai OS yang tersedia
void clear(){ 
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}

//function untuk enter
void enter(void){
            cout<<"\n\n\n Tekan enter untuk kembali\n\n";
            cin.get();
            cin.get();
}

//function untuk menampilkan list karyawan
void listKaryawan(void) { //akan menampilkan data berupa nama, id, dan jabatan
    clear();
    FILE *file;
    file = fopen("dataBase.txt", "r");
    cout<<"\n-------------------------------------------------";
    cout<<"\n ID        |     NAMA     |      JABATAN     ";
    cout<<"\n-------------------------------------------------";
    while(fscanf(file, "%s %s %s %d %d %d", &nama[0], &id[0] , &jabatan[0], &umur, &gaji, &pengalaman)!= EOF)
                cout<<"\n "<< id<<"\t\t "<<nama<<"\t\t "<<jabatan;
            fclose(file);
            enter();
}

//function untuk menampilkan data lengkap karyawan
void tampilDetails(void) { 
    clear();
    FILE *file;
    char checkId[5];
    cout<<"\n\nMasukan ID Karayawan: ";
    cin>>checkId;
    file = fopen("dataBase.txt", "r");
    while(fscanf(file, "%s %s %s %d %d %d", &nama[0], &id[0] , &jabatan[0], &umur, &gaji, &pengalaman)!= EOF)
    if(strcmp(checkId,id)==0) { //function 'strcmp' berfungsi untuk membandingkan nilai dari dua buah string.
        	        cout<<"\n----------------------------------";
                    cout<<"\nNama: "<<nama;
                    cout<<"\n----------------------------------";
                    cout<<"\nId: "<<id;
                    cout<<"\n----------------------------------";
                    cout<<"\nJabatan: "<<jabatan;
                    cout<<"\n----------------------------------";
                    cout<<"\nUmur: "<<umur;
                    cout<<"\n----------------------------------";
                    cout<<"\nGaji: "<<gaji;
                    cout<<"\n----------------------------------";
                    cout<<"\nLama pengalaman: "<<pengalaman<<" Tahun";
                    cout<<"\n----------------------------------";
    }
    fclose(file);
    enter();
}

//function untuk mengedit data penglaman dan gaji
void editDataKaryawan(void) {
    clear();
    char checkId[5];
    cout<<"\nMasukan ID Karayawan yang ingin diubah: ";
    cin>>checkId;
    char newJabatan[30];
    cout<<"\n-----------------------------------------";
    cout<<"\nMasukan data jabatan terbaru: ";
    cin>>newJabatan;
    int newGaji;
    cout<<"\n---------------------------------------";
    cout<<"\nMasukan data gaji terbaru: ";
    cin>>newGaji;
    FILE *file, *tempfile;
    file = fopen("dataBase.txt", "r");
    tempfile = fopen("temp.txt", "w");
        while(fscanf(file, "%s %s %s %d %d %d", &nama[0], &id[0] , &jabatan[0], &umur, &gaji, &pengalaman)!=EOF){
                if(strcmp(checkId, id)==0)
                    fprintf(tempfile, "%s %s %s %d %d %d \n", nama, id, newJabatan, umur, newGaji, pengalaman );
                else
                    fprintf(tempfile, "%s %s %s %d %d %d \n", nama, id, jabatan, umur, gaji, pengalaman );
            }
            fclose(file);
            fclose(tempfile);
            int isRemoved= remove("dataBase.txt");
            int isRenamed= rename("temp.txt", "dataBase.txt");
            enter();
}

//function menambahkan data karyawan
void addDataKaryawan(void) {
    clear();
            cout<<"\t\t\tSISTEM MANAJEMEM KARYAWAN\n";
            cout<<"\n--------------------------------------------------------------";
            cout<<"\n Masukan first name karyawan: ";
            cin>>nama;
            cout<<"\n--------------------------------------------------------------";
            cout<<"\n Masukan ID karyawan [max 4 digits]: ";
            cin>>id;
            cout<<"\n--------------------------------------------------------------";
            cout<<"\n Masukan jabatan [underscore sebagai spasi]: ";
            cin>>jabatan;
            cout<<"\n--------------------------------------------------------------";
            cout<<"\n Masukan umur karyawan: ";
            cin>>umur;
            cout<<"\n--------------------------------------------------------------";
            cout<<"\n Masukan gaji karyawan: ";
            cin>>gaji;
            cout<<"\n--------------------------------------------------------------";
            cout<<"\n Masukan lama pengalaman karyawan [dalam angka]: ";
            cin>>pengalaman;
            cout<<"\n--------------------------------------------------------------";

    char ch;
            cout<<"\nTekan 'y' untuk menyimpan data\n";
            cin>>ch;
            if(ch=='y'){
                FILE  *file;
                file= fopen("dataBase.txt","a");
                fprintf(file, "%s %s %s %d %d %d \n", nama, id, jabatan, umur, gaji, pengalaman );
                fclose(file);
                cout<<"\nData Berhasil Disimpan!!!\n";
            }
            else
                addDataKaryawan();
            enter();
}

//function untuk mendelete data karyawan
void deletDataKaryawan(void) {
    clear();
    char checkId[5];
    cout<<"\n\nMasukan ID Karayawan: ";
    cin>>checkId;
    char ch;
    cout<<"\n\n\n\n\nKONFIRMASI\nTekan 'y' untuk menghapus data\n";
        cin>>ch;
        if(ch=='y') {
             FILE *file, *tempfile;
                file= fopen("dataBase.txt", "r");
                tempfile= fopen("temp.txt", "w");
                while(fscanf(file, "%s %s %s %d %d %d", &nama[0], &id[0] , &jabatan[0], &umur, &gaji, &pengalaman)!=EOF)
                    if(strcmp(checkId, id)!=0)
                        fprintf(tempfile, "%s %s %s %d %d %d \n", nama, id, jabatan, umur, gaji, pengalaman );
                fclose(file);
                fclose(tempfile);
                int isRemoved= remove("dataBase.txt");
                int isRenamed= rename("temp.txt", "dataBase.txt");
                cout<<"\nMenghapus Data Sukses!!!\n";
                enter();
        }
}

//function untuk menu program
void options(void){ //menu
                // Options to choose an action
            while(true) {
            clear();
                cout<<"\n\t\t\t>>>>>>>>>  SISTEM MANAJEMEN KARYAWAN  <<<<<<<<<";
                cout<<"\n";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tTEKAN   1:  Untuk Menambahkan Data Karyawan Baru";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tTEKAN   2:  Untuk Melihat Data Singkat Karyawan" ;
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tTEKAN   3:  Untuk Melihat Data Lengkap Karyawan" ;
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tTEKAN   4:  Untuk Menghapus Data Karyawan"       ;
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tTEKAN   5:  Untuk Merubah Data Karyawan"         ;
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tTEKAN   0:  Untuk Keluar    ";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\n\t\t\t   Masukan Pilihan Anda: ";

                // Mengambil data inputam
                int pilihan;
                cin>>pilihan;
                // Memanggil function yang bersangkutan, sesuai inputan user 
                switch (pilihan) {
                    case 0:
                    	clear();
                        cout<<"\n\nSISTEM MANAJEMEN KARYAWAN \n\n @Cword.tech\n\n ";
                        Sleep(10);
                        return;
                    case 1:
                        addDataKaryawan();
                        break;
                    case 2:
                        listKaryawan();
                        break;
                    case 3:
                        tampilDetails();
                        break;
                    case 4:
                        deletDataKaryawan();
                        break;
                    case 5:
                        editDataKaryawan();
                        break;
                    default:
                        cout<<"\n Silakan Masukan Menu Yang Sesuai! \n";
                        break;
                }
            }

            }

int main () {
	int login(); //memanggil function login yang telah kita buat
	login();
    options();
    return 0;
}

int login(){ //function login
   string pass ="";
   string user ="";
   char ch;
   cout <<"\n\n\n\n\t\t\t\t\tSISTEM MANAJEMEN KARYAWAN";
   cout <<"\n\n\n\n\n\t\t\t\t\tMasukan Username Anda :";
   cin>>user;
   cout<<"\n\t\t\t\t\tMasukan Password Anda :";
   ch = _getch();
   while(ch != 13){//karakter ke-13 adalah enter
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   if(pass == "pass" && user =="admin"){
   	cout<<"\n\n\n\t\t\t\t\tLOADING \n\t\t\t\t\t";
   	for(int a=1;a<8;a++) // Kalian bisa ganti 'a<?' sebanyak * yang kamu mau
	{
		Sleep(500);
		cout << "...";
	}
      cout << "\n\n\n\t\t\t\t\tAkses Login Sukses!! \n\n\n";
      system("PAUSE");
    clear();
   }else{
      cout << "\n\n\n\t\t\t\t\tAkses Login Ditolak...\n\n\n";
      login();
   }
}

