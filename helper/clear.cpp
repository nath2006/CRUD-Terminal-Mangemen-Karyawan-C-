#include <cstdlib>
#include "helper.h"

//functiion clear agar fungsi clear bisa dipakai di berbagai OS yang tersedia
void helper::clear( ){
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}
