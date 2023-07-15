#include <iostream>
#include "include/DataFileHandler.h"

bool DataFileHandler::readFile(const std::string &dataFileName) {

    //打开文件
    FILE *fp_open = fopen(dataFileName.c_str(), "r");

    //判空
    if (fp_open == nullptr) {
        std::cout << "文件打开失败，请检查文件路径是否正确！" << std::endl;
        return false;
    }

    //统计数据的条数
    int count = 0;

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

    //开始读文件
    while (!feof(fp_open)) {
        //临时的road属性
        int linkId;
        int category;
        int forkNumber;
        int isHaveName;
        char roadName[maxLength];

        //一直读取到文件结尾
        if (fscanf(fp_open, "%d %d %d %d", &linkId, &category, &forkNumber, &isHaveName) == EOF) {
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
            MainActivity::roads.push_back(road);
            ++count;
            continue;
        }

        //有名字就接着读取名字
        fscanf(fp_open, "%s", roadName);
        road.setRoadName(roadName);

        //把临时的road对象push到动态数组中
        MainActivity::roads.push_back(road);
        ++count;
    }

    std::cout << count << "条数据导入成功！" << std::endl;

    fclose(fp_open);

    return true;
}

bool DataFileHandler::writeFile() {

    std::cout << "是否进行数据导出？是请输入y" << std::endl;
    std::string flag;
    std::cin >> flag;
    if (flag != "y") return false;

    std::cout << "请输入导出文件的绝对路径：（不包含扩展名<.txt>，且该目录下不应含有重名的文件，否则会被覆盖）" << std::endl;
    std::string fileName;
    std::cin >> fileName;
    fileName += ".txt";

    //打开文件
    FILE *fp_open = fopen(fileName.c_str(), "w+");

    //判空
    if (fp_open == nullptr) {
        std::cout << "文件创建失败！" << std::endl;
        return false;
    }

    //统计数据的条数
    int count = 0;

    //依次写入数据到文件
    for (const auto &item: MainActivity::roads) {
        if (!item.getIsHaveName()) {
            fprintf(fp_open, "%d %d %d %d\n", item.getLinkId(), item.getCategory(), item.getForkNumber(),
                    item.getIsHaveName());
            ++count;
            continue;
        }
        fprintf(fp_open, "%d %d %d %d %s\n", item.getLinkId(), item.getCategory(), item.getForkNumber(),
                item.getIsHaveName(), item.getRoadName());
        ++count;
    }

    std::cout << count << "条数据导出成功！" << std::endl;

    fclose(fp_open);

    return true;
}
