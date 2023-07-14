#include <fstream>
#include <iostream>
#include "include/Road.h"
#include "include/BinaryFileHandler.h"
#include "include/Menu.h"

bool BinaryFileHandler::readFile(const std::string &binaryFileName) {

    //����һ���ļ����������󣬲��Զ����Ƶķ�ʽ���ļ�
    std::ifstream fileInStream(binaryFileName, std::ios::in | std::ios::binary);

    //�п�
    if (!fileInStream.is_open()) {
        std::cout << "�ļ���ȡʧ�ܣ������ļ��Ƿ���ڣ�" << std::endl;
        return false;
    }

    //�Ƿ����roads�б��е�ԭ������
    std::cout << "�Ƿ����roads�б��е�ԭ������?(y/n)" << std::endl;
    std::string flag;
    do {
        std::cin >> flag;
        if (flag != "y" && flag != "Y" && flag != "n" && flag != "N") {
            std::cout << "��������ȷ��ָ�" << std::endl;
        }
    } while (flag != "y" && flag != "Y" && flag != "n" && flag != "N");
    if (flag == "y" || flag == "Y") {
        Menu::roads.clear();
    }

    //���ݵ�����
    int count = 0;

    //��ʼ�����ļ����ݵĶ�ȡ
    while (true) {
        //����һ����ʱ��Road����
        Road road;
        //��ȡ����
        fileInStream.read(reinterpret_cast<char *>(&road), sizeof(Road));
        //fileInStream.gcount()�᷵����һ�ζ�ȡ���������гɹ���ȡ���ֽ���
        if (fileInStream.gcount() == sizeof(Road)) {
            ++count;
            Menu::roads.push_back(road);
        } else if (fileInStream.eof()) {
            //�ļ���ȡ���
            break;
        } else {
            //�ļ���ȡ����
            std::cout << "�ļ���ȡ������Ч���ı�����" << std::endl;
            fileInStream.close();
        }
    }
    std::cout << "���ݶ�ȡ�ɹ�����" << count << "������" << std::endl;

    //�ر�������
    fileInStream.close();

    return true;
}

bool BinaryFileHandler::writeFile(const std::string &binaryFileName) {

    //����һ���ļ���������󣬲��Զ����Ƶķ�ʽ���ļ�
    std::ofstream fileOutStream(binaryFileName, std::ios::out | std::ios::binary);

    //�п�
    if (!fileOutStream.is_open()) {
        std::cout << "����д��ʧ�ܣ������ļ��Ƿ���ڣ�" << std::endl;
        return false;
    }

    //�����ļ����ݵĸ���
    for (const auto &road: Menu::roads) {
        fileOutStream.write(reinterpret_cast<const char *>(&road), sizeof(Road));
        if (!fileOutStream) {
            //����д��ʧ��
            std::cout << "����д��ʧ��" << std::endl;
            fileOutStream.close();
            return false;
        }
    }

    std::cout << "����д��ɹ�" << std::endl;

    return true;
}
