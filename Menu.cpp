#include "Menu.h"

using namespace std;

void Menu::print(string &fileName) {
    int flag;
    do {
        system("cls");
        cout << "/*************************Welcome*************************/" << endl;
        cout << "/***                                                   ***/" << endl;
        cout << "/***                  ���ӵ�ͼ����ϵͳ                 ***/" << endl;
        cout << "/***                                                   ***/" << endl;
        cout << "/*********************************************************/" << endl;

        cout << "--------------------------------" << endl;
        cout << "\t1.��ȡ�ļ�" << endl;
        cout << "\t2.����" << endl;
        cout << "\t3.��Ϣ��ѯ" << endl;
        cout << "\t4.���ݵ���" << endl;
        cout << "\t5.���ݵ���" << endl;
        cout << "\t6.�ļ�����\n" << endl;
        cout << "\t0.�˳�" << endl;
        cout << "--------------------------------" << endl;

        cout << "��ѡ��";
        cin >> flag;
        if (!(flag >= 0 && flag <= 6)) {
            cout << "��ѡ����ȷ��ѡ��!" << endl;
        }
    } while (!(flag >= 0 && flag <= 6));

    //�����û�����ѡ����Ӧ���߼�
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
