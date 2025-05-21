#pragma once
#include "SetImpl.h"
#include <unordered_set>

class HashSetImpl : public SetImpl {
    std::unordered_set<int> elements;

public:
    bool add(int element) override;
    bool remove(int element) override;
    bool contains(int element) const override;
    std::unique_ptr<SetImpl> unite(const SetImpl& other) const override;
    std::unique_ptr<SetImpl> intersect(const SetImpl& other) const override;
    size_t size() const override;
    std::vector<int> getElements() const override;
};