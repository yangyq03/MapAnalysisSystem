#include <iostream>
#include "include/SortUtil.h"
#include "include/PrintUtil.h"
#include "include/SearchAndModifyUtils.h"
#include "include/MainActivity.h"
#include "include/DataFileHandler.h"
#include "include/BinaryFileHandler.h"

using namespace std;

void MainActivity::mainProcess(const std::string &binaryFileName, const std::string &dataFileName) {
    while (true) {
        int flag;
        do {
            system("cls");
            cout << "/*************************Welcome*************************/" << endl;
            cout << "/***                                                   ***/" << endl;
            cout << "/***                  电子地图管理系统                 ***/" << endl;
            cout << "/***                                                   ***/" << endl;
            cout << "/*********************************************************/" << endl;

            cout << "-----------------------------------------------------------" << endl;
            cout << "\t\t 1.读取文件(二进制文件)" << endl;
            cout << "\t\t 2.写入文件(二进制文件)" << endl;
            cout << "\t\t 3.输出当前所有数据" << endl;
            cout << "\t\t 4.排序" << endl;
            cout << "\t\t 5.信息查询与修改" << endl;
            cout << "\t\t 6.数据导入(文本文件)" << endl;
            cout << "\t\t 7.数据导出(文本文件)\n" << endl;
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
                BinaryFileHandler::writeFile(binaryFileName);
                break;
            case 3:
                PrintUtil::print(roads);
                break;
            case 4:
                if (roads.empty()) {
                    cout << "当前暂无数据，请导入数据再尝试!" << endl;
                    break;
                }
                SortUtil::sortMenu();
                break;
            case 5:
                if (roads.empty()) {
                    cout << "当前暂无数据，请导入数据再尝试!" << endl;
                    break;
                }
                SearchAndModifyUtils::searchMenu();
                break;
            case 6:
                DataFileHandler::readFile(dataFileName);
                break;
            case 7:
                if (roads.empty()) {
                    cout << "当前暂无数据，请导入数据再尝试!" << endl;
                    break;
                }
                DataFileHandler::writeFile();
                break;
            case 0:
                return;
            default:
                break;
        }
        system("pause");
    }
}

std::vector<Road> MainActivity::roads;
