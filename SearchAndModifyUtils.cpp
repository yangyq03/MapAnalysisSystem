#include <iostream>
#include "include/PrintUtil.h"
#include "include/SearchAndModifyUtils.h"
#include "include/MainActivity.h"

using namespace std;

void SearchAndModifyUtils::searchMenu() {
    int flag;
    do {
        cout << "\n��Ϣ��ѯ" << endl;
        cout << "-----------------------------------------------------------" << endl;
        cout << "\t\t1.LinkId��ѯ" << endl;
        cout << "\t\t2.�����Ų�ѯ\n" << endl;
        cout << "\t\t0.����" << endl;
        cout << "-----------------------------------------------------------" << endl;
        cout << "��ѡ��";
        cin >> flag;
        if (!(flag >= 0 && flag <= 2)) {
            cout << "��ѡ����ȷ��ѡ��!" << endl;
        }
    } while (!(flag >= 0 && flag <= 2));

    switch (flag) {
        case 1:
            cout << "������Ҫ���ҵ�LinkId��" << endl;
            int targetLinkId;
            cin >> targetLinkId;
            searchByLinkId(targetLinkId);
            PrintUtil::print(tempResults);
            modifyMenu();
            break;
        case 2:
            cout << "������Ҫ���ҵķ����ţ�" << endl;
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
    //�������ʱ�洢����
    tempResults.clear();
    resultIndex.clear();
    for (int i = 0; i < MainActivity::roads.size(); ++i) {
        //�з��ϵľ�push��ȥ
        if (MainActivity::roads[i].getLinkId() == target) {
            tempResults.push_back(MainActivity::roads[i]);
            resultIndex.push_back(i);
        }
    }
}

void SearchAndModifyUtils::searchByCategory(const int &target) {
    //�������ʱ�洢����
    tempResults.clear();
    resultIndex.clear();
    for (int i = 0; i < MainActivity::roads.size(); ++i) {
        //�з��ϵľ�push��ȥ
        if (MainActivity::roads[i].getCategory() == target) {
            tempResults.push_back(MainActivity::roads[i]);
            resultIndex.push_back(i);
        }
    }
}

int SearchAndModifyUtils::isVariousResult() {
    //��ѯ�Ľ���ж��
    if (tempResults.size() > 1) {
        cout << "��ѯ�Ľ��Ϊ�����������Ҫ�޸���һ����(���)" << endl;
        int index;
        do {
            cin >> index;
            if (!(index >= 1 && index <= tempResults.size())) {
                cout << "��ѡ����ȷ��ѡ��!" << endl;
            }
        } while (!(index >= 1 && index <= tempResults.size()));
        //ͨ���û�����ı�ţ���resultIndex�ҵ�ԭʼ���ݵ�����������
        return resultIndex[index - 1];
    }
    //��ѯ���ֻ��һ��
    return resultIndex[0];
}

void SearchAndModifyUtils::modifyMenu() {
    std::cout << "�Ƿ���������޸ģ�(y/n)" << std::endl;
    std::string temp;
    std::cin >> temp;
    if (temp != "y") return;

    int flag;
    do {
        cout << "\n�޸�����" << endl;
        cout << "-----------------------------------------------------------" << endl;
        cout << "\t\t1.�޸�LinkId" << endl;
        cout << "\t\t2.�޸ķ�����" << endl;
        cout << "\t\t3.�޸Ĳ�·��" << endl;
        cout << "\t\t4.�޸���������" << endl;
        cout << "\t\t5.�޸�����\n" << endl;
        cout << "\t\t0.����" << endl;
        cout << "-----------------------------------------------------------" << endl;
        cout << "��ѡ��";
        cin >> flag;
        if (!(flag >= 0 && flag <= 5)) {
            cout << "��ѡ����ȷ��ѡ��!" << endl;
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
    cout << "�������޸ĺ��LinkId��" << endl;
    cin >> targetValue;
    MainActivity::roads[roadIndex].setLinkId(targetValue);
    cout << "�޸ĳɹ���" << endl;
}

void SearchAndModifyUtils::modifyCategory(const int &roadIndex) {
    int targetValue;
    cout << "�������޸ĺ�ķ����ţ�" << endl;
    cin >> targetValue;
    MainActivity::roads[roadIndex].setCategory(targetValue);
    cout << "�޸ĳɹ���" << endl;
}

void SearchAndModifyUtils::modifyForkNumber(const int &roadIndex) {
    int targetValue;
    cout << "�������޸ĺ�Ĳ�·����" << endl;
    cin >> targetValue;
    MainActivity::roads[roadIndex].setForkNumber(targetValue);
    cout << "�޸ĳɹ���" << endl;
}

void SearchAndModifyUtils::modifyIsHaveName(const int &roadIndex) {
    int targetValue;
    cout << "�������޸ĺ���������ƣ�" << endl;
    cin >> targetValue;
    if (MainActivity::roads[roadIndex].getIsHaveName() == 0 && targetValue == 1) {
        cout << "�������·���ƣ�" << endl;
        char roadName[maxLength];
        scanf("%s", roadName);
        MainActivity::roads[roadIndex].setRoadName(roadName);
    } else if (MainActivity::roads[roadIndex].getIsHaveName() == 1 && targetValue == 0) {
        MainActivity::roads[roadIndex].setRoadName((char *) "--\0");
    }
    MainActivity::roads[roadIndex].setIsHaveName(targetValue);
    cout << "�޸ĳɹ���" << endl;
}

void SearchAndModifyUtils::modifyRoadName(const int &roadIndex) {
    if (MainActivity::roads[roadIndex].getIsHaveName() == 0) {
        //û�����ƾ��Ȱ�isHaveName����ֵ�ĳ� 1���ٽ�һ���޸�
        cout << "��ǰ��·û�����ƣ��Ƿ������ó������ƣ�(y/n)" << endl;
        string flag;
        cin >> flag;
        if (flag != "y" && flag != "Y") return;
        MainActivity::roads[roadIndex].setIsHaveName(1);
    }
    char targetValue[maxLength];
    cout << "�������޸ĺ�����ƣ�" << endl;
    cin >> targetValue;
    MainActivity::roads[roadIndex].setRoadName(targetValue);
    cout << "�޸ĳɹ���" << endl;
}

std::vector<Road> SearchAndModifyUtils::tempResults;

std::vector<int> SearchAndModifyUtils::resultIndex;
