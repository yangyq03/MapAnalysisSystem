#include "Menu.h"

using namespace std;

void Menu::print(string &fileName) {
    int flag;
    do {
        system("cls");
        cout << "/*************************Welcome*************************/" << endl;
        cout << "/***                                                   ***/" << endl;
        cout << "/***                  电子地图管理系统                 ***/" << endl;
        cout << "/***                                                   ***/" << endl;
        cout << "/*********************************************************/" << endl;

        cout << "--------------------------------" << endl;
        cout << "\t1.读取文件" << endl;
        cout << "\t2.排序" << endl;
        cout << "\t3.信息查询" << endl;
        cout << "\t4.数据导入" << endl;
        cout << "\t5.数据导出" << endl;
        cout << "\t6.文件更新\n" << endl;
        cout << "\t0.退出" << endl;
        cout << "--------------------------------" << endl;

        cout << "请选择：";
        cin >> flag;
        if (!(flag >= 0 && flag <= 6)) {
            cout << "请选择正确的选项!" << endl;
        }
    } while (!(flag >= 0 && flag <= 6));

    //根据用户输入选择相应的逻辑
    switch (flag) {
        case 1:
            BinaryFileHandler::readFile(fileName);
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:
            BinaryFileHandler::writeFile(fileName);
            break;
        case 0:
            exit(0);
        default:
            break;
    }

}
