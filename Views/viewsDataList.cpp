//
// Created by Admin on 14/04/2023.
//
#include <iostream>
#include <cstring>
#include "views.h"
#include "../model/managemenKaryawan.h"
#include "../helper/helper.h"

using namespace helper;
using namespace std;

//function untuk menampilkan list karyawan
void views::listKaryawan(void) { //akan menampilkan data berupa nama, id, dan jabatan
    Karyawan karyawan;
    clear();
    FILE *file;
    file = fopen("../dataBase/dataBase.txt", "r");
    cout<<"\n-------------------------------------------------";
    cout<<"\n ID        |     NAMA     |      JABATAN     ";
    cout<<"\n-------------------------------------------------";
    while(fscanf(file, "%s %s %s %d %d %d", &karyawan.nama[0], &karyawan.id[0] , &karyawan.jabatan[0], &karyawan.umur, &karyawan.gaji, &karyawan.pengalaman)!= EOF)
        cout<<"\n "<<karyawan.id<<"\t\t "<<karyawan.nama<<"\t\t "<<karyawan.jabatan;
    fclose(file);
    enter();
}