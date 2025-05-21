#include "UnorderedImpl.hpp"

void UnorderedImpl::add(int value) {
    data.insert(value);
}

void UnorderedImpl::remove(int value) {
    data.erase(value);
}

bool UnorderedImpl::contains(const int& value) const {
    return data.find(value) != data.end();
}

void UnorderedImpl::unite(SetImpl* other) const {
    std::unordered_set<int> result = data;
    for (int val : other->getAll()) result.insert(val);
    std::cout << "Unite:\n";
    for (int v : result) std::cout << v << " ";
    std::cout << "\n";
}

void UnorderedImpl::intersect(SetImpl* other) const {
    std::vector<int> result;
    for (int val : data) {
        if (other->contains(val)) result.push_back(val);
    }
    std::cout << "Intersect:\n";
    for (int v : result) std::cout << v << " ";
    std::cout << "\n";
}

size_t UnorderedImpl::size() const {
    return data.size();
}

std::vector<int> UnorderedImpl::getAll() const {
    return {data.begin(), data.end()};
}

void UnorderedImpl::loadFrom(const std::vector<int>& values) {
    data.clear();
    for (int val : values) data.insert(val);
}

void UnorderedImpl::showType() const {
    std::cout << "This is UnorderedSet\n";
}
