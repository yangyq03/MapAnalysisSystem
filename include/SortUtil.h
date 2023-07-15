#ifndef MAPANALYSISSYSTEM_SORTUTIL_H
#define MAPANALYSISSYSTEM_SORTUTIL_H

#include "Road.h"
#include "MainActivity.h"

using namespace std;

class SortUtil {
public:
    // 定义函数指针类型
    typedef void (*SortingFunction)(std::vector<Road> &arr);

    //排序主菜单
    static void sortMenu();

    //冒泡排序
    static void bubbleSort(std::vector<Road> &arr);

    //选择排序
    static void quickSort(std::vector<Road> &arr);

    //插入排序
    static void insertionSort(std::vector<Road> &arr);

    //排序性能测试
    static void performanceTest();

    //计算某个排序算法函数所耗的时间
    static long long int getRunTotalTime(SortingFunction function);

private:
    //用于性能测试时的临时存储
    static std::vector<Road> tempData;
};

#endif
