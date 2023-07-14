#ifndef MAPANALYSISSYSTEM_BINARYFILEHANDLER_H
#define MAPANALYSISSYSTEM_BINARYFILEHANDLER_H

#include <string>

class BinaryFileHandler {

public:

    //���ļ�
    static bool readFile(const std::string &binaryFileName);

    //д�ļ�
    static bool writeFile(const std::string &binaryFileName);

};


#endif
