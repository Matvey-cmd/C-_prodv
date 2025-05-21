#include "Set.h"
#include "VectorImpl.h"
#include "UnorderedImpl.h"

Set::Set() : impl(std::make_unique<VectorImpl>()) {}

void Set::add(int value) {
    checkImplementation();
    impl->add(value);
    checkImplementation();
}

void Set::remove(int value) {
    checkImplementation();
    impl->remove(value);
    checkImplementation();
}

bool Set::contains(const int& value) const {
    return impl->contains(value);
}

void Set::unite(Set& other) {
    impl->unite(other.impl.get());
}

void Set::intersect(Set& other) {
    impl->intersect(other.impl.get());
}

void Set::showType() const {
    impl->showType();
}

size_t Set::size() const {
    return impl->size();
}

void Set::checkImplementation() {
    if (size() > 20 && dynamic_cast<VectorImpl*>(impl.get())) {
        switchToUnordered();
    } else if (size() <= 20 && dynamic_cast<UnorderedImpl*>(impl.get())) {
        switchToVector();
    }
}

void Set::switchToVector() {
    auto temp = impl->getAll();
    impl = std::make_unique<VectorImpl>();
    impl->loadFrom(temp);
}

void Set::switchToUnordered() {
    auto temp = impl->getAll();
    impl = std::make_unique<UnorderedImpl>();
    impl->loadFrom(temp);
}
