//
// Created by Admin on 14/04/2023.
//

//function menambahkan data karyawan
#include <iostream>
#include "busniessLogic.h"
#include "../helper/helper.h"
#include "../model/managemenKaryawan.h"

using namespace std;
using namespace helper;

void busnieesLogic::addDataKaryawan(void) {
    Karyawan karyawan;
    clear();
    cout<<"\t\t\tSISTEM MANAJEMEM KARYAWAN\n";
    cout<<"\n--------------------------------------------------------------";
    cout<<"\n Masukan first name karyawan: ";
    cin>>karyawan.nama;
    cout<<"\n--------------------------------------------------------------";
    cout<<"\n Masukan ID karyawan [max 4 digits]: ";
    cin>>karyawan.id;
    cout<<"\n--------------------------------------------------------------";
    cout<<"\n Masukan jabatan [underscore sebagai spasi]: ";
    cin>>karyawan.jabatan;
    cout<<"\n--------------------------------------------------------------";
    cout<<"\n Masukan umur karyawan: ";
    cin>>karyawan.umur;
    cout<<"\n--------------------------------------------------------------";
    cout<<"\n Masukan gaji karyawan: ";
    cin>>karyawan.gaji;
    cout<<"\n--------------------------------------------------------------";
    cout<<"\n Masukan lama pengalaman karyawan [dalam angka]: ";
    cin>>karyawan.pengalaman;
    cout<<"\n--------------------------------------------------------------";

    char ch;
    cout<<"\nTekan 'y' untuk menyimpan data\n";
    cin>>ch;
    if(ch=='y'){
        FILE  *file;
        file= fopen("../dataBase/dataBase.txt","a");
        fprintf(file, "%s %s %s %d %d %d \n", karyawan.nama, karyawan.id, karyawan.jabatan, karyawan.umur, karyawan.gaji, karyawan.pengalaman );
        fclose(file);
        cout<<"\nData Berhasil Disimpan!!!\n";
    }
    else
        addDataKaryawan();
    enter();
}