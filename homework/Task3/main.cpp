#include <bits/stdc++.h>
#include "Task3.h"

struct DataA { std::string value; };
struct DataB { int value; };

int main() {
    TypeMap<
        int,
        DataA,
        double,
        DataB
    > myTypeMap;

    myTypeMap.AddValue<int, int>(42);
    myTypeMap.AddValue<double, double>(3.14);
    myTypeMap.AddValue<DataA, DataA>({"Hello, TypeMap!"});
    myTypeMap.AddValue<DataB, DataB>({10});

    std::cout << "Value for int: " << myTypeMap.getValue<int>() << std::endl;
    std::cout << "Value for DataA: " << myTypeMap.getValue<DataA>().value << std::endl;
    std::cout << "Value for DataB: " << myTypeMap.getValue<DataB>().value << std::endl;

    std::cout << "Contains int? " << (myTypeMap.inTypeMap<int>() ? "Yes" : "No") << std::endl;

    myTypeMap.deleteValue<double>();
    try {
        std::cout << "Value for double: " << myTypeMap.getValue<double>() << std::endl;
    } catch (const char* e) {
        std::cout << "Error: " << e << std::endl;
    }

    return 0;
}