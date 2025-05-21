#include "VectorImpl.h"
#include <algorithm>

bool ArraySetImpl::add(int element) {
    if (contains(element)) return false;
    elements.push_back(element);
    return true;
}

bool ArraySetImpl::remove(int element) {
    auto it = std::find(elements.begin(), elements.end(), element);
    if (it == elements.end()) return false;
    elements.erase(it);
    return true;
}

bool ArraySetImpl::contains(int element) const {
    return std::find(elements.begin(), elements.end(), element) != elements.end();
}

std::unique_ptr<SetImpl> ArraySetImpl::unite(const SetImpl& other) const {
    auto result = std::make_unique<ArraySetImpl>();
    for (int elem : getElements()) result->add(elem);
    for (int elem : other.getElements()) result->add(elem);
    return result;
}

std::unique_ptr<SetImpl> ArraySetImpl::intersect(const SetImpl& other) const {
    auto result = std::make_unique<ArraySetImpl>();
    for (int elem : getElements()) {
        if (other.contains(elem)) result->add(elem);
    }
    return result;
}

size_t ArraySetImpl::size() const { return elements.size(); }
std::vector<int> ArraySetImpl::getElements() const { return elements; }