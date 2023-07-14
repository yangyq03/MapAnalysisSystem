#ifndef MAPANALYSISSYSTEM_ROAD_H
#define MAPANALYSISSYSTEM_ROAD_H

//道路名称的最大长度
#define maxLength 20


#include <string>

class Road {

public:

    Road();

    int getLinkId() const;

    void setLinkId(int linkId);

    int getCategory() const;

    void setCategory(int category);

    int getForkNumber() const;

    void setForkNumber(int forkNumber);

    int getIsHaveName() const;

    void setIsHaveName(int isHaveName);

    const char *getRoadName() const;

    void setRoadName(char *roadName);

    //重载运算符 <
    bool operator<(const Road &other) const;

private:

    int linkId;
    int category;
    int forkNumber;
    int isHaveName;
    char roadName[maxLength];

};


#endif
