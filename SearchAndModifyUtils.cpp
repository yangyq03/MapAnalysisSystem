#include <iostream>
#include "include/PrintUtil.h"
#include "include/SearchAndModifyUtils.h"
#include "include/MainActivity.h"

using namespace std;

void SearchAndModifyUtils::searchMenu() {
    int flag;
    do {
        cout << "\n信息查询" << endl;
        cout << "-----------------------------------------------------------" << endl;
        cout << "\t\t1.LinkId查询" << endl;
        cout << "\t\t2.分类编号查询\n" << endl;
        cout << "\t\t0.返回" << endl;
        cout << "-----------------------------------------------------------" << endl;
        cout << "请选择：";
        cin >> flag;
        if (!(flag >= 0 && flag <= 2)) {
            cout << "请选择正确的选项!" << endl;
        }
    } while (!(flag >= 0 && flag <= 2));

    switch (flag) {
        case 1:
            cout << "请输入要查找的LinkId：" << endl;
            int targetLinkId;
            cin >> targetLinkId;
            searchByLinkId(targetLinkId);
            PrintUtil::print(tempResults);
            modifyMenu();
            break;
        case 2:
            cout << "请输入要查找的分类编号：" << endl;
            int targetCategory;
            cin >> targetCategory;
            searchByCategory(targetCategory);
            PrintUtil::print(tempResults);
            modifyMenu();
            break;
        case 0:
            return;
        default:
            break;
    }
}

void SearchAndModifyUtils::searchByLinkId(const int &target) {
    //先清空临时存储数组
    tempResults.clear();
    resultIndex.clear();
    for (int i = 0; i < MainActivity::roads.size(); ++i) {
        //有符合的就push进去
        if (MainActivity::roads[i].getLinkId() == target) {
            tempResults.push_back(MainActivity::roads[i]);
            resultIndex.push_back(i);
        }
    }
}

void SearchAndModifyUtils::searchByCategory(const int &target) {
    //先清空临时存储数组
    tempResults.clear();
    resultIndex.clear();
    for (int i = 0; i < MainActivity::roads.size(); ++i) {
        //有符合的就push进去
        if (MainActivity::roads[i].getCategory() == target) {
            tempResults.push_back(MainActivity::roads[i]);
            resultIndex.push_back(i);
        }
    }
}

int SearchAndModifyUtils::isVariousResult() {
    //查询的结果有多个
    if (tempResults.size() > 1) {
        cout << "查询的结果为多个，请问你要修改哪一个？(序号)" << endl;
        int index;
        do {
            cin >> index;
            if (!(index >= 1 && index <= tempResults.size())) {
                cout << "请选择正确的选项!" << endl;
            }
        } while (!(index >= 1 && index <= tempResults.size()));
        //通过用户输入的标号，在resultIndex找到原始数据的索引并返回
        return resultIndex[index - 1];
    }
    //查询结果只有一个
    return resultIndex[0];
}

void SearchAndModifyUtils::modifyMenu() {
    std::cout << "是否进行数据修改？(y/n)" << std::endl;
    std::string temp;
    std::cin >> temp;
    if (temp != "y") return;

    int flag;
    do {
        cout << "\n修改数据" << endl;
        cout << "-----------------------------------------------------------" << endl;
        cout << "\t\t1.修改LinkId" << endl;
        cout << "\t\t2.修改分类编号" << endl;
        cout << "\t\t3.修改岔路数" << endl;
        cout << "\t\t4.修改有无名称" << endl;
        cout << "\t\t5.修改名称\n" << endl;
        cout << "\t\t0.返回" << endl;
        cout << "-----------------------------------------------------------" << endl;
        cout << "请选择：";
        cin >> flag;
        if (!(flag >= 0 && flag <= 5)) {
            cout << "请选择正确的选项!" << endl;
        }
    } while (!(flag >= 0 && flag <= 5));

    switch (flag) {
        case 1:
            modifyLinkId(isVariousResult());
            break;
        case 2:
            modifyCategory(isVariousResult());
            break;
        case 3:
            modifyForkNumber(isVariousResult());
            break;
        case 4:
            modifyIsHaveName(isVariousResult());
            break;
        case 5:
            modifyRoadName(isVariousResult());
            break;
        case 0:
            return;
        default:
            break;
    }
}

void SearchAndModifyUtils::modifyLinkId(const int &roadIndex) {
    int targetValue;
    cout << "请输入修改后的LinkId：" << endl;
    cin >> targetValue;
    MainActivity::roads[roadIndex].setLinkId(targetValue);
    cout << "修改成功！" << endl;
}

void SearchAndModifyUtils::modifyCategory(const int &roadIndex) {
    int targetValue;
    cout << "请输入修改后的分类编号：" << endl;
    cin >> targetValue;
    MainActivity::roads[roadIndex].setCategory(targetValue);
    cout << "修改成功！" << endl;
}

void SearchAndModifyUtils::modifyForkNumber(const int &roadIndex) {
    int targetValue;
    cout << "请输入修改后的岔路数：" << endl;
    cin >> targetValue;
    MainActivity::roads[roadIndex].setForkNumber(targetValue);
    cout << "修改成功！" << endl;
}

void SearchAndModifyUtils::modifyIsHaveName(const int &roadIndex) {
    int targetValue;
    cout << "请输入修改后的有无名称：" << endl;
    cin >> targetValue;
    if (MainActivity::roads[roadIndex].getIsHaveName() == 0 && targetValue == 1) {
        cout << "请输入道路名称：" << endl;
        char roadName[maxLength];
        scanf("%s", roadName);
        MainActivity::roads[roadIndex].setRoadName(roadName);
    } else if (MainActivity::roads[roadIndex].getIsHaveName() == 1 && targetValue == 0) {
        MainActivity::roads[roadIndex].setRoadName((char *) "--\0");
    }
    MainActivity::roads[roadIndex].setIsHaveName(targetValue);
    cout << "修改成功！" << endl;
}

void SearchAndModifyUtils::modifyRoadName(const int &roadIndex) {
    if (MainActivity::roads[roadIndex].getIsHaveName() == 0) {
        //没有名称就先把isHaveName属性值改成 1，再进一步修改
        cout << "当前道路没有名称，是否将其设置成有名称？(y/n)" << endl;
        string flag;
        cin >> flag;
        if (flag != "y" && flag != "Y") return;
        MainActivity::roads[roadIndex].setIsHaveName(1);
    }
    char targetValue[maxLength];
    cout << "请输入修改后的名称：" << endl;
    cin >> targetValue;
    MainActivity::roads[roadIndex].setRoadName(targetValue);
    cout << "修改成功！" << endl;
}

std::vector<Road> SearchAndModifyUtils::tempResults;

std::vector<int> SearchAndModifyUtils::resultIndex;
