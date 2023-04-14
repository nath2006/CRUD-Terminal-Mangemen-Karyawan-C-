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

//function untuk mendelete data karyawan
void busnieesLogic::deleteDataKaryawan(void) {
    Karyawan karyawan;
    clear();
    char checkId[5];
    cout<<"\n\nMasukan ID Karayawan: ";
    cin>>checkId;
    char ch;
    cout<<"\n\n\n\n\nKONFIRMASI\nTekan 'y' untuk menghapus data\n";
    cin>>ch;
    if(ch=='y') {
        FILE *file, *tempfile;
        file= fopen("../dataBase/dataBase.txt", "r");
        tempfile= fopen("../dataBase/temp.txt", "w");
        while(fscanf(file, "%s %s %s %d %d %d", &karyawan.nama[0], &karyawan.id[0] , &karyawan.jabatan[0], &karyawan.umur, &karyawan.gaji, &karyawan.pengalaman)!=EOF)
            if(strcmp(checkId, karyawan.id)!=0)
                fprintf(tempfile, "%s %s %s %d %d %d \n", karyawan.nama, karyawan.id, karyawan.jabatan, karyawan.umur, karyawan.gaji, karyawan.pengalaman );
        fclose(file);
        fclose(tempfile);
        int isRemoved= remove("../dataBase/dataBase.txt");
        int isRenamed= rename("../dataBase/temp.txt", "../dataBase/dataBase.txt");
        cout<<"\nMenghapus Data Sukses!!!\n";
        enter();
    }
}