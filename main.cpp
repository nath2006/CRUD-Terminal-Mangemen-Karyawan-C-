//
// Created by Admin on 14/04/2023.
//
#include <iostream>
#if _WIN32
    #include <Windows.h>
#include <unordered_map>
#include <unordered_set>

#elif _WIN64
    #include <Windows.h>
	    #else
		    #include <unistd.h>
#endif

#include "model/managemenKaryawan.h"
#include "helper/helper.h"
#include "BusniessLogic//busniessLogic.h"
#include "views/views.h"


using namespace busnieesLogic;
using namespace views;
using namespace std;

//function untuk menu program
void options(void){ //menu
    // Options untuk memiliki action
    while(true) {
        helper::clear();
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
                helper::clear();
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
                deleteDataKaryawan();
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
    login();
    options();
    return 0;
}
