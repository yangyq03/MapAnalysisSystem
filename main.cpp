#include "include/MainActivity.h"
#include "include/BinaryFileHandler.h"

//�������ļ��ľ���·��
const std::string BINARY_FILE_NAME = R"(E:\C++\MapAnalysisSystem\TextFile\BinaryFile.bin)";
//�ı��ļ��ľ���·��(���ݵ���ʱʹ��)
const std::string DATA_FILE_NAME = R"(E:\C++\MapAnalysisSystem\TextFile\DataFile.txt)";

int main() {
    MainActivity::mainProcess(BINARY_FILE_NAME, DATA_FILE_NAME);
    return 0;
}
