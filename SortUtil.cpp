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
        cout << "\n注：排序规则按岔路数升序排序，性能测试不会排序当前数据" << endl;
        cout << "-----------------------------------------------------------" << endl;
        cout << "请选择：";
        cin >> flag;
        if (!(flag >= 0 && flag <= 4)) {
            cout << "请选择正确的选项!" << endl;
        }
    } while (!(flag >= 0 && flag <= 4));

    switch (flag) {
        case 1:
            bubbleSort(MainActivity::roads);
            cout << "排序成功！" << endl;
            break;
        case 2:
            quickSort(MainActivity::roads);
            cout << "排序成功！" << endl;
            break;
        case 3:
            insertionSort(MainActivity::roads);
            cout << "排序成功！" << endl;
            break;
        case 4:
            performanceTest();
            cout << "测试完毕！" << endl;
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
    //直接调用algorithm中的sort函数（快速排序）
    std::sort(arr.begin(), arr.end());
}

void SortUtil::insertionSort(std::vector<Road> &arr) {
    auto size = arr.size();
    for (int i = 0; i < size; ++i) {
        for (int j = i; j > 0; --j) {
            //寻找一个适合的位置存放（插入）
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
            } else {
                break;
            }
        }
    }
}

void SortUtil::performanceTest() {
    //分别求出三个排序所用的时间
    long long int time_b = getRunTotalTime(bubbleSort);
    long long int time_q = getRunTotalTime(quickSort);
    long long int time_i = getRunTotalTime(insertionSort);
    cout << "冒泡排序所用时间为：" << time_b << "微秒，快速排序所用时间为：" << time_q << "微秒，插入排序所用时间为："
         << time_i << "微秒" << endl;
}

long long int SortUtil::getRunTotalTime(SortingFunction function) { //使用的函数指针，将算法函数通过参数的形式传递过来
    //将数据临时存储到临时数组中
    if (tempData.size() < MainActivity::roads.size()) {
        //为临时数组分配空间，防止越界
        tempData.resize(MainActivity::roads.size());
    }
    std::copy(MainActivity::roads.begin(), MainActivity::roads.end(), tempData.begin());
    //获取执行之前的时间，精确到微秒
    long long int beforeTime = chrono::duration_cast<chrono::microseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
    //调用传递过来的函数
    function(tempData);
    //执行之后的时间
    long long int afterTime = chrono::duration_cast<chrono::microseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
    //清空临时数组
    tempData.clear();
    //返回排序算法执行的总时间
    return afterTime - beforeTime;
}

std::vector<Road> SortUtil::tempData;
