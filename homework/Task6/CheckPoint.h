#pragma once
#include <string>
#include <iostream>

class CheckPoint {
    std::string name;
    double latitude;
    double longitude;
    int number;

public:
    virtual ~CheckPoint() = default;
    virtual void info() const = 0;
    void setName(const std::string& name_);
    void setLatitude(double lat);
    void setLongitude(double lon);
    void setNumber(int num);

    std::string getName() const;
    double getLatitude() const;
    double getLongitude() const;
    int getNumber() const;
};

class MandatoryCheckPoint : public CheckPoint {
public:
    MandatoryCheckPoint(const std::string& name, double lat, double lon, int num);
    void info() const override;
};

class OptionalCheckPoint : public CheckPoint {
    double penalty;

public:
    OptionalCheckPoint(const std::string& name, double lat, double lon, int num, double pen);
    void info() const override;
    double getPenalty() const;
};