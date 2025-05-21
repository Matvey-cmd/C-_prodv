#pragma once
#include "CheckpointBuilder.h"

class RaceDirector {
public:
    static void constructTrack(TrackBuilder& builder) {
        builder.addOptionalPoint("Koenigsberg", 21.0, 57.0, 1, 90.0);
        builder.addMandatoryPoint("Berlin", 12.9, 87.0, 2);
        builder.addOptionalPoint("Hamburgh", 65.0, 94.0, 5, 53.0);
        builder.addMandatoryPoint("SwitzBurg", 47.0, 52.0, 4);
        builder.addMandatoryPoint("FrankFurt", 3.14, 24.0, 3);
    }
};