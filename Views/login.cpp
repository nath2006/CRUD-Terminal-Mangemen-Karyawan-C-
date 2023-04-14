//
// Created by Admin on 14/04/2023.
//
#include <iostream>
#include <conio.h>
#include <cstring>
#include <cstdlib>
#if _WIN32
    #include <Windows.h>
#elif _WIN64
    #include <Windows.h>
	    #else
		    #include <unistd.h>
#endif

#include "../helper/helper.h"
#include "views.h"

using namespace helper;
using namespace views;
using namespace std;

//function login
int views::login(){
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