#include <iostream>
#include "include/DataFileHandler.h"

bool DataFileHandler::readFile(const std::string &dataFileName) {

    /*
    //�õ��ļ�·��
    std::string fileNames;
    std::cout << "������.txt�ļ��ľ���·����" << std::endl;
    std::cin >> fileNames;
     */

    //���ļ�
    FILE *fp_open = fopen(dataFileName.c_str(), "r");

    //�п�
    if (fp_open == nullptr) {
        std::cout << "�ļ���ʧ�ܣ������ļ�·���Ƿ���ȷ��" << std::endl;
        return false;
    }

    //ͳ�����ݵ�����
    int count = 0;

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

    //��ʼ���ļ�
    while (!feof(fp_open)) {
        //��ʱ��road����
        int linkId;
        int category;
        int forkNumber;
        int isHaveName;
        char roadName[maxLength];

        //һֱ��ȡ���ļ���β
        if (fscanf(fp_open, "%d %d %d %d ", &linkId, &category, &forkNumber, &isHaveName) == EOF) {
            break;
        }

        //����һ����ʱ��road����
        Road road;
        road.setLinkId(linkId);
        road.setCategory(category);
        road.setForkNumber(forkNumber);
        road.setIsHaveName(isHaveName);

        //���û�����־�������ȡroadName
        if (!isHaveName) {
            road.setRoadName((char *) "--\0");
            Menu::roads.push_back(road);
            ++count;
            continue;
        }

        //�����־ͽ��Ŷ�ȡ����
        fscanf(fp_open, "%s", roadName);
        road.setRoadName(roadName);

        //����ʱ��road����push����̬������
        Menu::roads.push_back(road);
        ++count;
    }

    std::cout << count << "�����ݵ���ɹ���" << std::endl;

    fclose(fp_open);

    return true;
}

bool DataFileHandler::writeFile() {

    const char *fileName;

    std::string temp;
    std::cout << "�����뵼���ļ��ľ���·��������������չ��<.txt>���Ҹ�Ŀ¼�²�Ӧ�����������ļ�������ᱻ���ǣ�" << std::endl;
    std::cin >> temp;
    temp += ".txt";
    fileName = temp.c_str();

    //���ļ�
    FILE *fp_open = fopen(fileName, "w+");

    //�п�
    if (fp_open == nullptr) {
        std::cout << "�ļ�����ʧ�ܣ�" << std::endl;
        return false;
    }

    //����д�����ݵ��ļ�
    for (const auto &item: Menu::roads) {
        fprintf(fp_open, "%d %d %d %d %s\n", item.getLinkId(), item.getCategory(), item.getForkNumber(),
                item.getIsHaveName(), item.getRoadName());
    }

    std::cout << "����д��ɹ���" << std::endl;

    fclose(fp_open);

    return true;
}
