#include <fstream>
#include <iostream>
#include "Road.h"
#include "BinaryFileHandler.h"

bool BinaryFileHandler::readFile(const std::string &fileName) {
    //����һ���ļ�����������
    std::ifstream fileInStream(fileName, std::ios::in | std::ios::binary);
    //�п�
    if (!fileInStream.is_open()) {
        std::cout << "�ļ���ȡʧ�ܣ������ļ��Ƿ���ڣ�" << std::endl;
        return false;
    }
    //���roads�б���ԭ������
    roads.clear();
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
            roads.push_back(road);
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

bool BinaryFileHandler::writeFile(const std::string &fileName) {
    //����һ�����������
    std::ofstream fileOutStream(fileName, std::ios::out | std::ios::binary);
    //�п�
    if (!fileOutStream.is_open()) {
        std::cout << "����д��ʧ�ܣ������ļ��Ƿ���ڣ�" << std::endl;
        return false;
    }
    //��ʼ�����ļ����ݵ�д��
    for (const auto &road: roads) {
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
