#ifndef MAPANALYSISSYSTEM_MENU_H
#define MAPANALYSISSYSTEM_MENU_H

#include <string>
#include <vector>
#include "Road.h"

class Menu {

public:

    static void print(const std::string &binaryFileName, const std::string &dataFileName);

    static void printAll();

    //使用可变数组来储道路信息
    static std::vector<Road> roads;

};

#endif
