#ifndef MAPANALYSISSYSTEM_SORTUTIL_H
#define MAPANALYSISSYSTEM_SORTUTIL_H

#include "Menu.h"

using namespace std;

class SortUtil {
public:
    // 定义函数指针类型
    typedef void (SortUtil::*SortingFunction)();

    //提示菜单
    void sortMenu();

    //冒泡排序
    void bubbleSort();

    //选择排序
    void quickSort();

    //插入排序
    void insertionSort();

    //排序性能测试
    void performanceTest();

    //计算某个排序算法函数所耗的时间
    long long int getRunTotalTime(SortingFunction function);

    const int size = (int) Menu::roads.size();
};

#endif
