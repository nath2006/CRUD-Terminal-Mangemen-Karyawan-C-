//
// Created by Admin on 14/04/2023.
//

#include <iostream>
#include <cstring>
#include "busniessLogic.h"
#include "../helper/helper.h"
#include "../model/managemenKaryawan.h"

using namespace std;
using namespace helper;

//function untuk mengedit data penglaman dan gaji
void busnieesLogic::editDataKaryawan(void) {
    Karyawan karyawan;
    clear();
    char checkId[5];
    cout<<"\nMasukan ID Karayawan yang ingin diubah: ";
    cin>>checkId;
    if(strcmp(checkId, karyawan.id)==1) {
        char newJabatan[30];
        cout<<"\n-----------------------------------------";
        cout<<"\nMasukan data jabatan terbaru: ";
        cin>>newJabatan;
        int newGaji;
        cout<<"\n---------------------------------------";
        cout<<"\nMasukan data gaji terbaru: ";
        cin>>newGaji;
        FILE *file, *tempfile;
        file = fopen("../dataBase/dataBase.txt", "r");
        tempfile = fopen("../dataBase/temp.txt", "w");
        while(fscanf(file, "%s %s %s %d %d %d", &karyawan.nama[0], &karyawan.id[0] , &karyawan.jabatan[0], &karyawan.umur, &karyawan.gaji, &karyawan.pengalaman)!=EOF){
            if(strcmp(checkId, karyawan.id)==0)
                fprintf(tempfile, "%s %s %s %d %d %d \n", karyawan.nama, karyawan.id, newJabatan, karyawan.umur, newGaji, karyawan.pengalaman );
            else
                fprintf(tempfile, "%s %s %s %d %d %d \n", karyawan.nama, karyawan.id, karyawan.jabatan, karyawan.umur, karyawan.gaji, karyawan.pengalaman );
        }
        fclose(file);
        fclose(tempfile);
        int isRemoved= remove("../dataBase/dataBase.txt");
        int isRenamed= rename("../dataBase/temp.txt", "../dataBase/dataBase.txt");
        enter();
    }else {
        cout<<"Mohon maaf data tidak valid";
        enter();
    }

}