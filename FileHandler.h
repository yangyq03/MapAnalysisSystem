#ifndef MAPANALYSISSYSTEM_FILEHANDLER_H
#define MAPANALYSISSYSTEM_FILEHANDLER_H

#include <list>
#include <string>
#include <fstream>
#include "Road.h"

class FileHandler {

public:

    //读文件
    bool readFile(const std::string &fileName);

    //写文件
    bool writeFile(const std::string &fileName);

    //道路列表
    std::list<Road> roads;

};


#endif //MAPANALYSISSYSTEM_FILEHANDLER_H
