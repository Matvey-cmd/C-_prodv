#include "VectorImpl.h"

void VectorImpl::add(int value) {
    if (!contains(value)) data.push_back(value);
}

void VectorImpl::remove(int value) {
    data.erase(std::remove(data.begin(), data.end(), value), data.end());
}

bool VectorImpl::contains(const int& value) const {
    return std::find(data.begin(), data.end(), value) != data.end();
}

void VectorImpl::unite(SetImpl* other) const {
    std::vector<int> result = data;
    for (int val : other->getAll()) {
        if (std::find(result.begin(), result.end(), val) == result.end()) {
            result.push_back(val);
        }
    }
    std::cout << "Unite:\n";
    for (int v : result) std::cout << v << " ";
    std::cout << "\n";
}

void VectorImpl::intersect(SetImpl* other) const {
    std::vector<int> result;
    for (int val : data) {
        if (other->contains(val)) result.push_back(val);
    }
    std::cout << "Intersect:\n";
    for (int v : result) std::cout << v << " ";
    std::cout << "\n";
}

size_t VectorImpl::size() const {
    return data.size();
}

std::vector<int> VectorImpl::getAll() const {
    return data;
}

void VectorImpl::loadFrom(const std::vector<int>& values) {
    data = values;
}

void VectorImpl::showType() const {
    std::cout << "This is VectorSet\n";
}
