//
// Created by Admin on 14/04/2023.
//
#include <iostream>
#include <cstring>
#include "views.h"
#include "../helper/helper.h"
#include "../model/managemenKaryawan.h"

using namespace helper;
using namespace std;

//function untuk menampilkan data lengkap karyawan
void views::tampilDetails(void) {
    Karyawan karyawan;
    clear();
    FILE *file;
    char checkId[5];
    cout<<"\n\nMasukan ID Karayawan: ";
    cin>>checkId;
    file = fopen("../dataBase/dataBase.txt", "r");
    while(fscanf(file, "%s %s %s %d %d %d", &karyawan.nama[0], &karyawan.id[0] , &karyawan.jabatan[0], &karyawan.umur, &karyawan.gaji, &karyawan.pengalaman)!= EOF)
        if(strcmp(checkId,karyawan.id)==0) { //function 'strcmp' berfungsi untuk membandingkan nilai dari dua buah string.
            cout<<"\n----------------------------------";
            cout<<"\nNama: "<<karyawan.nama;
            cout<<"\n----------------------------------";
            cout<<"\nId: "<<karyawan.id;
            cout<<"\n----------------------------------";
            cout<<"\nJabatan: "<<karyawan.jabatan;
            cout<<"\n----------------------------------";
            cout<<"\nUmur: "<<karyawan.umur;
            cout<<"\n----------------------------------";
            cout<<"\nGaji: "<<karyawan.gaji;
            cout<<"\n----------------------------------";
            cout<<"\nLama pengalaman: "<<karyawan.pengalaman<<" Tahun";
            cout<<"\n----------------------------------";
        }
    fclose(file);
    enter();
}
