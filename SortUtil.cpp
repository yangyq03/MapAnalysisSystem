#include <chrono>
#include <iostream>
#include <algorithm>
#include "include/SortUtil.h"

void SortUtil::sortMenu() {
    int flag;
    do {
        cout << "\n����" << endl;
        cout << "-----------------------------------------------------------" << endl;
        cout << "\t\t1.ð������" << endl;
        cout << "\t\t2.��������" << endl;
        cout << "\t\t3.��������" << endl;
        cout << "\t\t4.���ܲ���\n" << endl;
        cout << "\t\t0.����" << endl;
        cout << "\nע��������򰴲�·����������" << endl;
        cout << "-----------------------------------------------------------" << endl;
        cout << "��ѡ��";
        cin >> flag;
        if (!(flag >= 0 && flag <= 4)) {
            cout << "��ѡ����ȷ��ѡ��!" << endl;
        }
    } while (!(flag >= 0 && flag <= 4));

    switch (flag) {
        case 1:
            bubbleSort();
            cout << "����ɹ���" << endl;
            break;
        case 2:
            quickSort();
            cout << "����ɹ���" << endl;
            break;
        case 3:
            insertionSort();
            cout << "����ɹ���" << endl;
            break;
        case 4:
            performanceTest();
            break;
        case 0:
            return;
        default:
            break;
    }
}

void SortUtil::bubbleSort() {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - 1 - i; ++j) {
            if (Menu::roads[j + 1] < Menu::roads[j]) {
                swap(Menu::roads[j], Menu::roads[j + 1]);
            }
        }
    }
}

void SortUtil::quickSort() {
    //ֱ�ӵ���algorithm�е�sort��������������
    std::sort(Menu::roads.begin(), Menu::roads.end());
}

void SortUtil::insertionSort() {
    for (int i = 0; i < Menu::roads.size(); ++i) {
        for (int j = i; j > 0; --j) {
            //Ѱ��һ���ʺϵ�λ�ô�ţ����룩
            if (Menu::roads[j] < Menu::roads[j - 1]) {
                swap(Menu::roads[j], Menu::roads[j - 1]);
            } else {
                break;
            }
        }
    }
}

void SortUtil::performanceTest() {
    //�ֱ���������������õ�ʱ��
    long long int time_b = getRunTotalTime(&SortUtil::bubbleSort);
    long long int time_q = getRunTotalTime(&SortUtil::quickSort);
    long long int time_i = getRunTotalTime(&SortUtil::insertionSort);
    cout << "ð����������ʱ��Ϊ��" << time_b << "΢�룬������������ʱ��Ϊ��" << time_q << "΢�룬������������ʱ��Ϊ��"
         << time_i << "΢��" << endl;
}

long long int SortUtil::getRunTotalTime(SortingFunction function) { //ʹ�õĺ���ָ�룬���㷨����ͨ����������ʽ���ݹ���
    //��ȡִ��֮ǰ��ʱ�䣬��ȷ��΢��
    long long int beforeTime = chrono::duration_cast<chrono::microseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
    //ʹ��thisָ����ó�Ա����
    (this->*function)();
    //ִ��֮���ʱ��
    long long int afterTime = chrono::duration_cast<chrono::microseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
    //���������㷨ִ�е���ʱ��
    return afterTime - beforeTime;
}
