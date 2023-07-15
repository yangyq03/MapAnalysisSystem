#ifndef MAPANALYSISSYSTEM_SEARCHANDMODIFYUTILS_H
#define MAPANALYSISSYSTEM_SEARCHANDMODIFYUTILS_H

#include <vector>
#include "Road.h"

class SearchAndModifyUtils {
public:

    //查找菜单
    static void searchMenu();

    //通过LinkId查找
    static void searchByLinkId(const int &target);

    //通过分类编号查找
    static void searchByCategory(const int &target);

    //判断查询结果是否有多个
    static int isVariousResult();

    //修改主菜单
    static void modifyMenu();

    //修改LinkId
    static void modifyLinkId(const int &roadIndex);

    //修改分类编号
    static void modifyCategory(const int &roadIndex);

    //修改岔路数
    static void modifyForkNumber(const int &roadIndex);

    //修改有无名称
    static void modifyIsHaveName(const int &roadIndex);

    //修改名称
    static void modifyRoadName(const int &roadIndex);

private:

    //用于查询时的临时存储
    static std::vector<Road> tempResults;

    //临时数据在原始数据中的位置，在进行数据修改的时候用
    static std::vector<int> resultIndex;

};


#endif
