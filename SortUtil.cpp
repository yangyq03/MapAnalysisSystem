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
        cout << "\nע��������򰴲�·�������������ܲ��Բ�������ǰ����" << endl;
        cout << "-----------------------------------------------------------" << endl;
        cout << "��ѡ��";
        cin >> flag;
        if (!(flag >= 0 && flag <= 4)) {
            cout << "��ѡ����ȷ��ѡ��!" << endl;
        }
    } while (!(flag >= 0 && flag <= 4));

    switch (flag) {
        case 1:
            bubbleSort(MainActivity::roads);
            cout << "����ɹ���" << endl;
            break;
        case 2:
            quickSort(MainActivity::roads);
            cout << "����ɹ���" << endl;
            break;
        case 3:
            insertionSort(MainActivity::roads);
            cout << "����ɹ���" << endl;
            break;
        case 4:
            performanceTest();
            cout << "������ϣ�" << endl;
            break;
        case 0:
            return;
        default:
            break;
    }
}

void SortUtil::bubbleSort(std::vector<Road> &arr) {
    auto size = arr.size();
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - 1 - i; ++j) {
            if (arr[j + 1] < arr[j]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void SortUtil::quickSort(std::vector<Road> &arr) {
    //ֱ�ӵ���algorithm�е�sort��������������
    std::sort(arr.begin(), arr.end());
}

void SortUtil::insertionSort(std::vector<Road> &arr) {
    auto size = arr.size();
    for (int i = 0; i < size; ++i) {
        for (int j = i; j > 0; --j) {
            //Ѱ��һ���ʺϵ�λ�ô�ţ����룩
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
            } else {
                break;
            }
        }
    }
}

void SortUtil::performanceTest() {
    //�ֱ���������������õ�ʱ��
    long long int time_b = getRunTotalTime(bubbleSort);
    long long int time_q = getRunTotalTime(quickSort);
    long long int time_i = getRunTotalTime(insertionSort);
    cout << "ð����������ʱ��Ϊ��" << time_b << "΢�룬������������ʱ��Ϊ��" << time_q << "΢�룬������������ʱ��Ϊ��"
         << time_i << "΢��" << endl;
}

long long int SortUtil::getRunTotalTime(SortingFunction function) { //ʹ�õĺ���ָ�룬���㷨����ͨ����������ʽ���ݹ���
    //��������ʱ�洢����ʱ������
    if (tempData.size() < MainActivity::roads.size()) {
        //Ϊ��ʱ�������ռ䣬��ֹԽ��
        tempData.resize(MainActivity::roads.size());
    }
    std::copy(MainActivity::roads.begin(), MainActivity::roads.end(), tempData.begin());
    //��ȡִ��֮ǰ��ʱ�䣬��ȷ��΢��
    long long int beforeTime = chrono::duration_cast<chrono::microseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
    //���ô��ݹ����ĺ���
    function(tempData);
    //ִ��֮���ʱ��
    long long int afterTime = chrono::duration_cast<chrono::microseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
    //�����ʱ����
    tempData.clear();
    //���������㷨ִ�е���ʱ��
    return afterTime - beforeTime;
}

std::vector<Road> SortUtil::tempData;
