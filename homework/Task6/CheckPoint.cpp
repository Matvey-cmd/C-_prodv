#include "CheckPoint.h"

void CheckPoint::setName(const std::string& name_) { name = name_; }
void CheckPoint::setLatitude(double lat) { latitude = lat; }
void CheckPoint::setLongitude(double lon) { longitude = lon; }
void CheckPoint::setNumber(int num) { number = num; }

std::string CheckPoint::getName() const { return name; }
double CheckPoint::getLatitude() const { return latitude; }
double CheckPoint::getLongitude() const { return longitude; }
int CheckPoint::getNumber() const { return number; }

MandatoryCheckPoint::MandatoryCheckPoint(const std::string& name, double lat, double lon, int num) {
    setName(name);
    setLatitude(lat);
    setLongitude(lon);
    setNumber(num);
}

void MandatoryCheckPoint::info() const {
    std::cout << "CP #" << getNumber() << "\n"
              << "Name: " << getName() << "\n"
              << "Coordinates: " << getLatitude() << "°N, " << getLongitude() << "°E\n"
              << "Status: MANDATORY\n"
              << "----------------------------\n";
}

OptionalCheckPoint::OptionalCheckPoint(const std::string& name, double lat, double lon, int num, double pen) 
    : penalty(pen) {
    setName(name);
    setLatitude(lat);
    setLongitude(lon);
    setNumber(num);
}

void OptionalCheckPoint::info() const {
    std::cout << "CP #" << getNumber() << "\n"
              << "Name: " << getName() << "\n"
              << "Coordinates: " << getLatitude() << "°N, " << getLongitude() << "°E\n"
              << "Penalty hours: " << penalty << "\n"
              << "----------------------------\n";
}

double OptionalCheckPoint::getPenalty() const { return penalty; }