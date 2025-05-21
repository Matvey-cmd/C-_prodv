#ifndef SET_HPP
#define SET_HPP

#include <vector>
#include <memory>

class SetImpl;

class Set {
public:
    Set();

    void add(int value);
    void remove(int value);
    bool contains(const int& value) const;
    void unite(Set& other);
    void intersect(Set& other);
    void showType() const;

private:
    std::unique_ptr<SetImpl> impl;

    void checkImplementation();
    void switchToVector();
    void switchToUnordered();
    size_t size() const;
};

#endif // SET_HPP
