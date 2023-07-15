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
            cout << "/***                  ���ӵ�ͼ����ϵͳ                 ***/" << endl;
            cout << "/***                                                   ***/" << endl;
            cout << "/*********************************************************/" << endl;

            cout << "-----------------------------------------------------------" << endl;
            cout << "\t\t 1.��ȡ�ļ�(�������ļ�)" << endl;
            cout << "\t\t 2.д���ļ�(�������ļ�)" << endl;
            cout << "\t\t 3.�����ǰ��������" << endl;
            cout << "\t\t 4.����" << endl;
            cout << "\t\t 5.��Ϣ��ѯ���޸�" << endl;
            cout << "\t\t 6.���ݵ���(�ı��ļ�)" << endl;
            cout << "\t\t 7.���ݵ���(�ı��ļ�)\n" << endl;
            cout << "\t\t 0.�˳�" << endl;
            cout << "-----------------------------------------------------------" << endl;

            cout << "��ѡ��";
            cin >> flag;
            if (!(flag >= 0 && flag <= 7)) {
                cout << "��ѡ����ȷ��ѡ��!" << endl;
                system("pause");
            }
        } while (!(flag >= 0 && flag <= 7));

        //�����û�����ѡ����Ӧ���߼�
        switch (flag) {
            case 1:
                BinaryFileHandler::readFile(binaryFileName);
                break;
            case 2:
                if (roads.empty()) {
                    cout << "��ǰ�������ݣ��뵼�������ٳ���!" << endl;
                    break;
                }
                BinaryFileHandler::writeFile(binaryFileName);
                break;
            case 3:
                PrintUtil::print(roads);
                break;
            case 4:
                if (roads.empty()) {
                    cout << "��ǰ�������ݣ��뵼�������ٳ���!" << endl;
                    break;
                }
                SortUtil::sortMenu();
                break;
            case 5:
                if (roads.empty()) {
                    cout << "��ǰ�������ݣ��뵼�������ٳ���!" << endl;
                    break;
                }
                SearchAndModifyUtils::searchMenu();
                break;
            case 6:
                DataFileHandler::readFile(dataFileName);
                break;
            case 7:
                if (roads.empty()) {
                    cout << "��ǰ�������ݣ��뵼�������ٳ���!" << endl;
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
