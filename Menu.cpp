#include <iostream>
#include "include/Menu.h"
#include "include/SortUtil.h"
#include "include/DataFileHandler.h"
#include "include/BinaryFileHandler.h"

using namespace std;

void Menu::print(const std::string &binaryFileName, const std::string &dataFileName) {
    while (true) {
        int flag = -1;
        SortUtil sortUtil;
        do {
            system("cls");
            cout << "/*************************Welcome*************************/" << endl;
            cout << "/***                                                   ***/" << endl;
            cout << "/***                  电子地图管理系统                 ***/" << endl;
            cout << "/***                                                   ***/" << endl;
            cout << "/*********************************************************/" << endl;

            cout << "-----------------------------------------------------------" << endl;
            cout << "\t\t 1.读取文件(二进制文件）" << endl;
            cout << "\t\t 2.排序" << endl;
            cout << "\t\t 3.信息查询" << endl;
            cout << "\t\t 4.数据导入(文本文件)" << endl;
            cout << "\t\t 5.数据导出(文本文件)" << endl;
            cout << "\t\t 6.文件更新(二进制文件)" << endl;
            cout << "\t\t 7.打印当前所有数据\n" << endl;
            cout << "\t\t 0.退出" << endl;
            cout << "-----------------------------------------------------------" << endl;

            cout << "请选择：";
            cin >> flag;
            if (!(flag >= 0 && flag <= 7)) {
                cout << "请选择正确的选项!" << endl;
                system("pause");
            }
        } while (!(flag >= 0 && flag <= 7));

        //根据用户输入选择相应的逻辑
        switch (flag) {
            case 1:
                BinaryFileHandler::readFile(binaryFileName);
                break;
            case 2:
                if (roads.empty()) {
                    cout << "当前暂无数据，请导入数据再尝试!" << endl;
                    break;
                }
                sortUtil.sortMenu();
                break;
            case 3:
                if (roads.empty()) {
                    cout << "当前暂无数据，请导入数据再尝试!" << endl;
                    break;
                }

                break;
            case 4:
                DataFileHandler::readFile(dataFileName);
                break;
            case 5:
                if (roads.empty()) {
                    cout << "当前暂无数据，请导入数据再尝试!" << endl;
                    break;
                }
                DataFileHandler::writeFile();
                break;
            case 6:
                if (roads.empty()) {
                    cout << "当前暂无数据，请导入数据再尝试!" << endl;
                    break;
                }
                BinaryFileHandler::writeFile(binaryFileName);
                break;
            case 7:
                printAll();
                break;
            case 0:
                return;
            default:
                break;
        }
        system("pause");
    }
}

void Menu::printAll() {
    cout << "--------------------------------------------------------------------" << endl;
    if (roads.empty()) cout << "\t\t\t    无" << endl;
    for (const auto &item: roads) {
        cout << "LinkID\t分类编号\t岔路数\t有无名称\t\t道路名称\n" << endl;
        cout << item.getLinkId() << "\t" << item.getCategory() << "\t\t" << item.getForkNumber()
             << "\t" << item.getIsHaveName() << "\t\t\t" << item.getRoadName() << endl;
    }
    cout << "--------------------------------------------------------------------" << endl;
    if (!roads.empty()) {
        cout << "\t\t\t总共" << roads.size() << "条数据！" << endl;
        cout << "--------------------------------------------------------------------" << endl;
    }
}

std::vector<Road> Menu::roads;
