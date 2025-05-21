#pragma once
#include "SetImpl.h"

class Set {
    std::unique_ptr<SetImpl> impl;
    static const size_t SWITCH_THRESHOLD = 20;

    void checkImplementation();

public:
    Set();
    bool add(int element);
    bool remove(int element);
    bool contains(int element) const;
    Set unite(const Set& other) const;
    Set intersect(const Set& other) const;
    size_t size() const;
    void print() const;
};