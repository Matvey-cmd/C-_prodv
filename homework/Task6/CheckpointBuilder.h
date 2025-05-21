#pragma once
#include "CheckPoint.h"
#include <vector>

class TrackBuilder {
protected:
    std::vector<MandatoryCheckPoint> mandatoryPoints;
    std::vector<OptionalCheckPoint> optionalPoints;

public:
    virtual ~TrackBuilder() = default;
    virtual void addMandatoryPoint(const std::string& name, double lat, double lon, int num) = 0;
    virtual void addOptionalPoint(const std::string& name, double lat, double lon, int num, double pen) = 0;
};

class ListBuilder : public TrackBuilder {
public:
    void addMandatoryPoint(const std::string& name, double lat, double lon, int num) override;
    void addOptionalPoint(const std::string& name, double lat, double lon, int num, double pen) override;
    void printTrack() const;
};

class PenaltyCalculator : public TrackBuilder {
    double totalPenalty = 0;

public:
    void addMandatoryPoint(const std::string&, double, double, int) override {}
    void addOptionalPoint(const std::string&, double, double, int, double pen) override;
    double getTotalPenalty() const;
};