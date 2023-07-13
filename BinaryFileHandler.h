#ifndef MAPANALYSISSYSTEM_BINARYFILEHANDLER_H
#define MAPANALYSISSYSTEM_BINARYFILEHANDLER_H

#include <string>
#include <fstream>
#include <vector>
#include "Road.h"

class BinaryFileHandler {

public:

    //读文件
    static bool readFile(const std::string &fileName);

    //写文件
    static bool writeFile(const std::string &fileName);

    //使用列表来储存每条道路的信息
    static std::vector<Road> roads;

};


#endif //MAPANALYSISSYSTEM_BINARYFILEHANDLER_H
