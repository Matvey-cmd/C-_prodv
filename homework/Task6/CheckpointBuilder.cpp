#include "CheckpointBuilder.h"
#include <algorithm>

void ListBuilder::addMandatoryPoint(const std::string& name, double lat, double lon, int num) {
    mandatoryPoints.emplace_back(name, lat, lon, num);
}

void ListBuilder::addOptionalPoint(const std::string& name, double lat, double lon, int num, double pen) {
    optionalPoints.emplace_back(name, lat, lon, num, pen);
}

void ListBuilder::printTrack() const {
    auto combined = mandatoryPoints;
    std::vector<OptionalCheckPoint> opts = optionalPoints;

    std::sort(combined.begin(), combined.end(), 
        [](const auto& a, const auto& b) { return a.getNumber() < b.getNumber(); });
    std::sort(opts.begin(), opts.end(),
        [](const auto& a, const auto& b) { return a.getNumber() < b.getNumber(); });

    size_t i = 0, j = 0;
    while (i < combined.size() && j < opts.size()) {
        if (combined[i].getNumber() < opts[j].getNumber()) {
            combined[i].info();
            ++i;
        } else {
            opts[j].info();
            ++j;
        }
    }

    while (i < combined.size()) combined[i++].info();
    while (j < opts.size()) opts[j++].info();
}

void PenaltyCalculator::addOptionalPoint(const std::string&, double, double, int, double pen) {
    totalPenalty += pen;
}

double PenaltyCalculator::getTotalPenalty() const {
    return totalPenalty;
}