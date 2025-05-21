#include "Set.h"

int main() {
    Set s;

    for (int i = 0; i < 25; ++i) {
        s.add(i);
    }

    Set s2;
    s2.add(20);
    s2.add(21);
    s2.add(22);

    Set united = s.unite(s2);
    united.print();

    Set intersection = s.intersect(s2);
    intersection.print();

    return 0;
}