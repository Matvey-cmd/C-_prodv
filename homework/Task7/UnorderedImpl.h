#ifndef UNORDERED_IMPL_HPP
#define UNORDERED_IMPL_HPP

#include "SetImpl.h"
#include <unordered_set>
#include <iostream>

class UnorderedImpl : public SetImpl {
    std::unordered_set<int> data;
public:
    void add(int value) override;
    void remove(int value) override;
    bool contains(const int& value) const override;
    void unite(SetImpl* other) const override;
    void intersect(SetImpl* other) const override;
    size_t size() const override;
    std::vector<int> getAll() const override;
    void loadFrom(const std::vector<int>& values) override;
    void showType() const override;
};

#endif // UNORDERED_IMPL_HPP
