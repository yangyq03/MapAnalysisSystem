#ifndef MAPANALYSISSYSTEM_BINARYFILEHANDLER_H
#define MAPANALYSISSYSTEM_BINARYFILEHANDLER_H

#include <string>
#include <fstream>
#include <vector>
#include "Road.h"

class BinaryFileHandler {

public:

    //���ļ�
    static bool readFile(const std::string &fileName);

    //д�ļ�
    static bool writeFile(const std::string &fileName);

    //ʹ���б�������ÿ����·����Ϣ
    static std::vector<Road> roads;

};


#endif //MAPANALYSISSYSTEM_BINARYFILEHANDLER_H
