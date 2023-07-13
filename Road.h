#ifndef MAPANALYSISSYSTEM_ROAD_H
#define MAPANALYSISSYSTEM_ROAD_H


#include <string>

class Road {

public:

    int getLinkId() const;

    void setLinkId(int linkId);

    int getCategory() const;

    void setCategory(int category);

    int getForkNumber() const;

    void setForkNumber(int forkNumber);

    int getIsHaveName() const;

    void setIsHaveName(int isHaveName);

    const std::string &getRoadName() const;

    void setRoadName(const std::string &roadName);

private:

    int linkId;
    int category;
    int forkNumber;
    int isHaveName;
    std::string roadName;

};


#endif //MAPANALYSISSYSTEM_ROAD_H
