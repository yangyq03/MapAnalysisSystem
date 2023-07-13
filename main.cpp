#include <iostream>
#include "BinaryFileHandler.h"
#include "Menu.h"

std::string fileName;


int main() {

 /*   BinaryFileHandler fileHandler;

    Road roadTemp;

    roadTemp.setLinkId(1);
    roadTemp.setCategory(1);
    roadTemp.setRoadName((char *) "µÀÂ·1");
    roadTemp.setForkNumber(1);
    roadTemp.setIsHaveName(1);

    fileHandler.roads.push_back(roadTemp);

    fileHandler.writeFile(R"(E:\C++\MapAnalysisSystem\Data.dat)");

    fileHandler.readFile(R"(E:\C++\MapAnalysisSystem\Data.dat)");

    for (const auto &item: fileHandler.roads) {
        std::cout << item.getLinkId() << item.getCategory() << item.getForkNumber()
                  << item.getIsHaveName() << item.getRoadName() << std::endl;
    }*/

    Menu::print(fileName);

    system("pause");

    return 0;
}
