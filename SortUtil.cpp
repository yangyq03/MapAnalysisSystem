#include <chrono>
#include <iostream>
#include <algorithm>
#include "include/SortUtil.h"

void SortUtil::sortMenu() {
    int flag;
    do {
        cout << "\n排序" << endl;
        cout << "-----------------------------------------------------------" << endl;
        cout << "\t\t1.冒泡排序" << endl;
        cout << "\t\t2.快速排序" << endl;
        cout << "\t\t3.插入排序" << endl;
        cout << "\t\t4.性能测试\n" << endl;
        cout << "\t\t0.返回" << endl;
        cout << "\n注：排序规则按岔路数升序排序" << endl;
        cout << "-----------------------------------------------------------" << endl;
        cout << "请选择：";
        cin >> flag;
        if (!(flag >= 0 && flag <= 4)) {
            cout << "请选择正确的选项!" << endl;
        }
    } while (!(flag >= 0 && flag <= 4));

    switch (flag) {
        case 1:
            bubbleSort();
            cout << "排序成功！" << endl;
            break;
        case 2:
            quickSort();
            cout << "排序成功！" << endl;
            break;
        case 3:
            insertionSort();
            cout << "排序成功！" << endl;
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
    //直接调用algorithm中的sort函数（快速排序）
    std::sort(Menu::roads.begin(), Menu::roads.end());
}

void SortUtil::insertionSort() {
    for (int i = 0; i < Menu::roads.size(); ++i) {
        for (int j = i; j > 0; --j) {
            //寻找一个适合的位置存放（插入）
            if (Menu::roads[j] < Menu::roads[j - 1]) {
                swap(Menu::roads[j], Menu::roads[j - 1]);
            } else {
                break;
            }
        }
    }
}

void SortUtil::performanceTest() {
    //分别求出三个排序所用的时间
    long long int time_b = getRunTotalTime(&SortUtil::bubbleSort);
    long long int time_q = getRunTotalTime(&SortUtil::quickSort);
    long long int time_i = getRunTotalTime(&SortUtil::insertionSort);
    cout << "冒泡排序所用时间为：" << time_b << "微秒，快速排序所用时间为：" << time_q << "微秒，插入排序所用时间为："
         << time_i << "微秒" << endl;
}

long long int SortUtil::getRunTotalTime(SortingFunction function) { //使用的函数指针，将算法函数通过参数的形式传递过来
    //获取执行之前的时间，精确到微秒
    long long int beforeTime = chrono::duration_cast<chrono::microseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
    //使用this指针调用成员函数
    (this->*function)();
    //执行之后的时间
    long long int afterTime = chrono::duration_cast<chrono::microseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
    //返回排序算法执行的总时间
    return afterTime - beforeTime;
}
