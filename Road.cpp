#include "Road.h"

int Road::getLinkId() const {
    return linkId;
}

void Road::setLinkId(int m_linkId) {
    Road::linkId = m_linkId;
}

int Road::getCategory() const {
    return category;
}

void Road::setCategory(int m_category) {
    Road::category = m_category;
}

int Road::getForkNumber() const {
    return forkNumber;
}

void Road::setForkNumber(int m_forkNumber) {
    Road::forkNumber = m_forkNumber;
}

int Road::getIsHaveName() const {
    return isHaveName;
}

void Road::setIsHaveName(int m_isHaveName) {
    Road::isHaveName = m_isHaveName;
}

const std::string &Road::getRoadName() const {
    return roadName;
}

void Road::setRoadName(const std::string &m_roadName) {
    Road::roadName = m_roadName;
}
