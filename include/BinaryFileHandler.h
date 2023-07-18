#ifndef MAPANALYSISSYSTEM_BINARYFILEHANDLER_H
#define MAPANALYSISSYSTEM_BINARYFILEHANDLER_H

#include <string>

class BinaryFileHandler {

public:

    //读文件
    static bool readFile(const std::string &binaryFileName);

    //写文件
    static bool writeFile(const std::string &binaryFileName);

};


#endif
