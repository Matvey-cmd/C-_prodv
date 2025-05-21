#ifndef SET_IMPL_HPP
#define SET_IMPL_HPP

#include <vector>

class SetImpl {
public:
    virtual ~SetImpl() = default;
    virtual void add(int value) = 0;
    virtual void remove(int value) = 0;
    virtual bool contains(const int& value) const = 0;
    virtual void unite(SetImpl* other) const = 0;
    virtual void intersect(SetImpl* other) const = 0;
    virtual size_t size() const = 0;
    virtual std::vector<int> getAll() const = 0;
    virtual void loadFrom(const std::vector<int>& data) = 0;
    virtual void showType() const = 0;
};

#endif // SET_IMPL_HPP
