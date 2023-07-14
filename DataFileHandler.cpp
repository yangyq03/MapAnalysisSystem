#include <iostream>
#include "include/DataFileHandler.h"

bool DataFileHandler::readFile(const std::string &dataFileName) {

    /*
    //得到文件路径
    std::string fileNames;
    std::cout << "请输入.txt文件的绝对路径：" << std::endl;
    std::cin >> fileNames;
     */

    //打开文件
    FILE *fp_open = fopen(dataFileName.c_str(), "r");

    //判空
    if (fp_open == nullptr) {
        std::cout << "文件打开失败，请检查文件路径是否正确！" << std::endl;
        return false;
    }

    //统计数据的条数
    int count = 0;

    //是否清空roads列表中的原有数据
    std::cout << "是否清空roads列表中的原有数据?(y/n)" << std::endl;
    std::string flag;
    do {
        std::cin >> flag;
        if (flag != "y" && flag != "Y" && flag != "n" && flag != "N") {
            std::cout << "请输入正确的指令！" << std::endl;
        }
    } while (flag != "y" && flag != "Y" && flag != "n" && flag != "N");
    if (flag == "y" || flag == "Y") {
        Menu::roads.clear();
    }

    //开始读文件
    while (!feof(fp_open)) {
        //临时的road属性
        int linkId;
        int category;
        int forkNumber;
        int isHaveName;
        char roadName[maxLength];

        //一直读取到文件结尾
        if (fscanf(fp_open, "%d %d %d %d ", &linkId, &category, &forkNumber, &isHaveName) == EOF) {
            break;
        }

        //创建一个临时的road对象
        Road road;
        road.setLinkId(linkId);
        road.setCategory(category);
        road.setForkNumber(forkNumber);
        road.setIsHaveName(isHaveName);

        //如果没有名字就跳过读取roadName
        if (!isHaveName) {
            road.setRoadName((char *) "--\0");
            Menu::roads.push_back(road);
            ++count;
            continue;
        }

        //有名字就接着读取名字
        fscanf(fp_open, "%s", roadName);
        road.setRoadName(roadName);

        //把临时的road对象push到动态数组中
        Menu::roads.push_back(road);
        ++count;
    }

    std::cout << count << "条数据导入成功！" << std::endl;

    fclose(fp_open);

    return true;
}

bool DataFileHandler::writeFile() {

    const char *fileName;

    std::string temp;
    std::cout << "请输入导出文件的绝对路径：（不包含扩展名<.txt>，且该目录下不应含有重名的文件，否则会被覆盖）" << std::endl;
    std::cin >> temp;
    temp += ".txt";
    fileName = temp.c_str();

    //打开文件
    FILE *fp_open = fopen(fileName, "w+");

    //判空
    if (fp_open == nullptr) {
        std::cout << "文件创建失败！" << std::endl;
        return false;
    }

    //依次写入数据到文件
    for (const auto &item: Menu::roads) {
        fprintf(fp_open, "%d %d %d %d %s\n", item.getLinkId(), item.getCategory(), item.getForkNumber(),
                item.getIsHaveName(), item.getRoadName());
    }

    std::cout << "数据写入成功！" << std::endl;

    fclose(fp_open);

    return true;
}
