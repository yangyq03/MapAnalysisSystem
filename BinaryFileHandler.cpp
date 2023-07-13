#include <fstream>
#include <iostream>
#include "Road.h"
#include "BinaryFileHandler.h"

bool BinaryFileHandler::readFile(const std::string &fileName) {
    //创建一个文件输入流对象
    std::ifstream fileInStream(fileName, std::ios::in | std::ios::binary);
    //判空
    if (!fileInStream.is_open()) {
        std::cout << "文件读取失败，请检查文件是否存在！" << std::endl;
        return false;
    }
    //清空roads列表中原有数据
    roads.clear();
    //数据的条数
    int count = 0;
    //开始进行文件数据的读取
    while (true) {
        //创建一个临时的Road对象
        Road road;
        //读取数据
        fileInStream.read(reinterpret_cast<char *>(&road), sizeof(Road));
        //fileInStream.gcount()会返回上一次读取操作从流中成功读取的字节数
        if (fileInStream.gcount() == sizeof(Road)) {
            ++count;
            roads.push_back(road);
        } else if (fileInStream.eof()) {
            //文件读取完毕
            break;
        } else {
            //文件读取错误
            std::cout << "文件读取错误，无效的文本内容" << std::endl;
            fileInStream.close();
        }
    }
    std::cout << "数据读取成功，共" << count << "条数据" << std::endl;
    //关闭输入流
    fileInStream.close();
    return true;
}

bool BinaryFileHandler::writeFile(const std::string &fileName) {
    //创建一个输出流对象
    std::ofstream fileOutStream(fileName, std::ios::out | std::ios::binary);
    //判空
    if (!fileOutStream.is_open()) {
        std::cout << "数据写入失败，请检查文件是否存在！" << std::endl;
        return false;
    }
    //开始进行文件数据的写入
    for (const auto &road: roads) {
        fileOutStream.write(reinterpret_cast<const char *>(&road), sizeof(Road));
        if (!fileOutStream) {
            //数据写入失败
            std::cout << "数据写入失败" << std::endl;
            fileOutStream.close();
            return false;
        }
    }
    std::cout << "数据写入成功" << std::endl;
    return true;
}
