#include "include/PrintUtil.h"

void PrintUtil::print(const std::vector<Road> &arr) {
    int i = 1;
    cout << "-----------------------------------------------------------" << endl;
    if (arr.empty()) cout << "\t\t\t  无数据" << endl;
    for (const auto &item: arr) {
        cout << "序号\tLinkID\t分类编号\t岔路数\t有无名称\t道路名称" << endl;
        cout << i++ << "\t" << item.getLinkId() << "\t" << item.getCategory() << "\t\t" << item.getForkNumber()
             << "\t" << item.getIsHaveName() << "\t\t" << item.getRoadName() << "\n" << endl;
    }
    cout << "-----------------------------------------------------------" << endl;
    if (!arr.empty()) {
        cout << "\t\t\t共" << arr.size() << "条数据" << endl;
        cout << "-----------------------------------------------------------" << endl;
    }
}
