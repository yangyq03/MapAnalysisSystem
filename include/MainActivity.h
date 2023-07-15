#ifndef MAPANALYSISSYSTEM_MAINACTIVITY_H
#define MAPANALYSISSYSTEM_MAINACTIVITY_H

#include <string>
#include <vector>
#include "Road.h"

class MainActivity {

public:

    //主程序
    static void mainProcess(const std::string &binaryFileName, const std::string &dataFileName);

    //使用可变数组来储道路信息
    static std::vector<Road> roads;

};

#endif
