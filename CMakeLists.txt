cmake_minimum_required(VERSION 3.25)
project(CRUD_Project_Version2_0)

set(CMAKE_CXX_STANDARD 14)

include_directories(helper)

add_executable(CRUD_Project_Version2_0
        helper/clear.cpp
        helper/enter.cpp
        helper/helper.h
        model/managemenKaryawan.h BusniessLogic/addDataKaryawan.cpp BusniessLogic/busniessLogic.h BusniessLogic/editDataKaryawan.cpp BusniessLogic/deleteDataKaryawan.cpp Views/login.cpp Views/views.h Views/viewsDataDetail.cpp Views/viewsDataList.cpp main.cpp)
