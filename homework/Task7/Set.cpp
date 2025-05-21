#include "Set.h"
#include "VectorImpl.h"
#include "UnorderedImpl.h"
#include <iostream>

Set::Set() : impl(std::make_unique<ArraySetImpl>()) {}

bool Set::add(int element) {
    bool result = impl->add(element);
    checkImplementation();
    return result;
}

bool Set::remove(int element) {
    bool result = impl->remove(element);
    checkImplementation();
    return result;
}

bool Set::contains(int element) const {
    return impl->contains(element);
}

Set Set::unite(const Set& other) const {
    Set result;
    result.impl = impl->unite(*other.impl);
    result.checkImplementation();
    return result;
}

Set Set::intersect(const Set& other) const {
    Set result;
    result.impl = impl->intersect(*other.impl);
    result.checkImplementation();
    return result;
}

size_t Set::size() const { return impl->size(); }

void Set::print() const {
    for (int elem : impl->getElements()) {
        std::cout << elem << " ";
    }
    std::cout << "\n";
}

void Set::checkImplementation() {
    if (impl->size() > SWITCH_THRESHOLD && dynamic_cast<ArraySetImpl*>(impl.get())) {
        auto temp = std::make_unique<HashSetImpl>();
        for (int elem : impl->getElements()) temp->add(elem);
        impl = std::move(temp);
    }
    else if (impl->size() <= SWITCH_THRESHOLD && dynamic_cast<HashSetImpl*>(impl.get())) {
        auto temp = std::make_unique<ArraySetImpl>();
        for (int elem : impl->getElements()) temp->add(elem);
        impl = std::move(temp);
    }
}