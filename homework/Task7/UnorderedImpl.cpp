#include "UnorderedImpl.h"

bool HashSetImpl::add(int element) {
    return elements.insert(element).second;
}

bool HashSetImpl::remove(int element) {
    return elements.erase(element) > 0;
}

bool HashSetImpl::contains(int element) const {
    return elements.count(element) > 0;
}

std::unique_ptr<SetImpl> HashSetImpl::unite(const SetImpl& other) const {
    auto result = std::make_unique<HashSetImpl>();
    for (int elem : getElements()) result->add(elem);
    for (int elem : other.getElements()) result->add(elem);
    return result;
}

std::unique_ptr<SetImpl> HashSetImpl::intersect(const SetImpl& other) const {
    auto result = std::make_unique<HashSetImpl>();
    for (int elem : getElements()) {
        if (other.contains(elem)) result->add(elem);
    }
    return result;
}

size_t HashSetImpl::size() const { return elements.size(); }
std::vector<int> HashSetImpl::getElements() const {
    return std::vector<int>(elements.begin(), elements.end());
}