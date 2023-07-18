#include <fstream>
#include <iostream>
#include "include/Road.h"
#include "include/BinaryFileHandler.h"
#include "include/MainActivity.h"

bool BinaryFileHandler::readFile(const std::string &binaryFileName) {

    //创建一个文件输入流对象，并以二进制的方式打开文件
    std::ifstream fileInStream(binaryFileName, std::ios::in | std::ios::binary);

    //判空
    if (!fileInStream.is_open()) {
        std::cout << "文件读取失败，请检查文件是否存在！" << std::endl;
        return false;
    }

    //是否保留roads列表中的原有数据
    std::cout << "文件读取成功，是否保留当前数据?(y/n)，取消请输入0" << std::endl;
    std::string flag;
    do {
        std::cin >> flag;
        if (flag != "y" && flag != "Y" && flag != "n" && flag != "N" && flag != "0") {
            std::cout << "请输入正确的指令！" << std::endl;
        }
    } while (flag != "y" && flag != "Y" && flag != "n" && flag != "N" && flag != "0");
    if (flag == "n" || flag == "N") {
        MainActivity::roads.clear();
    } else if (flag == "0") {
        return false;
    }

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
            MainActivity::roads.push_back(road);
        } else if (fileInStream.eof()) {
            //文件读取完毕
            break;
        } else {
            //文件读取错误
            std::cout << "文件读取错误，无效的文本内容" << std::endl;
            fileInStream.close();
        }
    }
    std::cout << "数据读取成功，共" << count << "条" << std::endl;

    //关闭输入流
    fileInStream.close();

    return true;
}

bool BinaryFileHandler::writeFile(const std::string &binaryFileName) {

    std::cout << "是否进行数据更新？是请输入y" << std::endl;
    std::string flag;
    std::cin >> flag;
    if (flag != "y") return false;

    //创建一个文件输出流对象，并以二进制的方式打开文件
    std::ofstream fileOutStream(binaryFileName, std::ios::out | std::ios::binary);

    //判空
    if (!fileOutStream.is_open()) {
        std::cout << "数据写入失败，请检查文件是否存在！" << std::endl;
        return false;
    }

    //数据的条数
    int count = 0;

    //进行文件数据的更新
    for (const auto &road: MainActivity::roads) {
        fileOutStream.write(reinterpret_cast<const char *>(&road), sizeof(Road));
        if (!fileOutStream) {
            //数据写入失败
            std::cout << "数据写入失败" << std::endl;
            fileOutStream.close();
            return false;
        }
        ++count;
    }

    std::cout << "数据写入成功，共" << count << "条" << std::endl;

    return true;
}
