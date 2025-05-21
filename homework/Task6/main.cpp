#include "Director.h"
#include "CheckpointBuilder.h"

int main() {
    ListBuilder list;
    PenaltyCalculator calc;

    RaceDirector::constructTrack(list);
    RaceDirector::constructTrack(calc);

    list.printTrack();
    std::cout << "Total penalty hours: " << calc.getTotalPenalty() << "\n";

    return 0;
}