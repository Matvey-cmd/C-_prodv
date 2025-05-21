#include "Set.hpp"

int main() {
    Set s1;
    s1.add(5);
    s1.showType();
    for (int i = 0; i < 20; ++i) s1.add(i);
    s1.showType();
    s1.remove(5);
    s1.showType();

    Set s2;
    s2.add(3);
    s2.add(4);
    s2.add(100);
    s2.add(11);

    s1.intersect(s2);
    s1.unite(s2);

    return 0;
}
