#ifndef VECTOR_IMPL_HPP
#define VECTOR_IMPL_HPP

#include "SetImpl.hpp"
#include <vector>
#include <iostream>
#include <algorithm>

class VectorImpl : public SetImpl {
    std::vector<int> data;
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

#endif // VECTOR_IMPL_HPP
