#ifndef MAPANALYSISSYSTEM_DATAFILEHANDLER_H
#define MAPANALYSISSYSTEM_DATAFILEHANDLER_H

#include "Menu.h"

class DataFileHandler {
public:

    static bool readFile(const std::string &dataFileName);

    static bool writeFile();

};


#endif
