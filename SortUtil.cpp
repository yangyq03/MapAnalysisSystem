#include <chrono>
#include "SortUtil.h"

SortUtil::SortUtil() {

    //用户选择的标记变量
    int i = sortMenu();

    switch (i) {
        case 1:
            bubbleSort();
            break;
        case 2:
            quickSort();
            break;
        case 3:
            insertionSort();
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

int SortUtil::sortMenu() {
    int flag;
    do {
        cout << "排序" << endl;
        cout << "---------------------------------" << endl;
        cout << "\t1.冒泡排序" << endl;
        cout << "\t2.快速排序" << endl;
        cout << "\t3.插入排序" << endl;
        cout << "\t4.性能测试\n" << endl;
        cout << "0.返回" << endl;
        cout << "---------------------------------" << endl;
        cout << "请选择：";
        cin >> flag;
        if (!(flag >= 0 && flag <= 4)) {
            cout << "请选择正确的选项!" << endl;
        }
    } while (!(flag >= 0 && flag <= 4));
    return flag;
}

void SortUtil::bubbleSort() {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - 1 - i; ++j) {
            if (BinaryFileHandler::roads[j].getForkNumber() > BinaryFileHandler::roads[j + 1].getForkNumber()) {
                swap(BinaryFileHandler::roads[j], BinaryFileHandler::roads[j + 1]);
            }
        }
    }
}

void SortUtil::quickSort() {

}

void SortUtil::insertionSort() {

}

void SortUtil::performanceTest() {
    //分别求出三个排序所用的时间
    long long int time_b = getRunTotalTime(&SortUtil::bubbleSort);
    long long int time_q = getRunTotalTime(&SortUtil::quickSort);
    long long int time_i = getRunTotalTime(&SortUtil::insertionSort);
    cout << "冒泡排序所用时间为：" << time_b << "快速排序所用时间为：" << time_q << "插入排序所用时间为：" << time_i
         << endl;
}

long long int SortUtil::getRunTotalTime(SortingFunction function) { //使用的函数指针，将算法函数通过参数的形式传递过来
    //获取执行之前的时间，精确到毫秒
    long long int beforeTime = chrono::duration_cast<chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
    //使用this指针调用成员函数
    (this->*function)();
    //执行之后的时间
    long long int afterTime = chrono::duration_cast<chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
    //返回排序算法执行的总时间
    return afterTime - beforeTime;
}
