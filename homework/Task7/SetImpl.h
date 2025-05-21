#pragma once
#include <memory>
#include <vector>

class SetImpl {
public:
    virtual ~SetImpl() = default;
    virtual bool add(int element) = 0;
    virtual bool remove(int element) = 0;
    virtual bool contains(int element) const = 0;
    virtual std::unique_ptr<SetImpl> unite(const SetImpl& other) const = 0;
    virtual std::unique_ptr<SetImpl> intersect(const SetImpl& other) const = 0;
    virtual size_t size() const = 0;
    virtual std::vector<int> getElements() const = 0;
};