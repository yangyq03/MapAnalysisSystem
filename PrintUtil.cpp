#include "include/PrintUtil.h"

void PrintUtil::print(const std::vector<Road> &arr) {
    int i = 1;
    cout << "-----------------------------------------------------------" << endl;
    if (arr.empty()) cout << "\t\t\t  ������" << endl;
    for (const auto &item: arr) {
        cout << "���\tLinkID\t������\t��·��\t��������\t��·����" << endl;
        cout << i++ << "\t" << item.getLinkId() << "\t" << item.getCategory() << "\t\t" << item.getForkNumber()
             << "\t" << item.getIsHaveName() << "\t\t" << item.getRoadName() << "\n" << endl;
    }
    cout << "-----------------------------------------------------------" << endl;
    if (!arr.empty()) {
        cout << "\t\t\t��" << arr.size() << "������" << endl;
        cout << "-----------------------------------------------------------" << endl;
    }
}
