#include <fstream>
#include <iostream>
#include "Road.h"
#include "FileHandler.h"

bool FileHandler::readFile(const std::string &fileName) {

    //打开文件
    auto fileInStream = std::ifstream(fileName, std::ios::in | std::ios::binary);

    //判空
    if (!fileInStream.is_open()) {
        std::cout << "文件读取失败，请检查文件是否存在！" << std::endl;
        return false;
    }

    //开始进行文件数据的读取
    while(fileInStream.read())


    std::cout << "数据写入成功，共" << fileInStream.gcount() << "字节" << std::endl;

    return true;
}

bool FileHandler::writeFile(const std::string &fileName) {

    //打开文件
    auto fileOutStream = std::ofstream(fileName, std::ios::out | std::ios::binary);

    //判空
    if (!fileOutStream.is_open()) {
        std::cout << "文件写入失败，请检查文件是否存在！" << std::endl;
        return false;
    }

    //开始进行文件数据的写入

    std::cout << "数据写入成功" << std::endl;

    return true;
}
