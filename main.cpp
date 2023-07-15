#include "include/MainActivity.h"
#include "include/BinaryFileHandler.h"

//二进制文件的绝对路径
const std::string BINARY_FILE_NAME = R"(E:\C++\MapAnalysisSystem\TextFile\BinaryFile.bin)";
//文本文件的绝对路径(数据导入时使用)
const std::string DATA_FILE_NAME = R"(E:\C++\MapAnalysisSystem\TextFile\DataFile.txt)";

int main() {
    MainActivity::mainProcess(BINARY_FILE_NAME, DATA_FILE_NAME);
    return 0;
}
