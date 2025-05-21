#ifndef COUNTER_HPP
#define COUNTER_HPP

#include <bits/stdc++.h>

namespace Task4 {
    template<class T>
    unsigned int count_val_ = 0;
}

template<class D>
struct counter {
    counter() {
        ++Task4::count_val_<D>;
    }

    ~counter() {
        --Task4::count_val_<D>;
    }

    static unsigned int count() {
        return Task4::count_val_<D>;
    }
};

template<class D>
struct less_than_comparable {

    friend bool operator> (const D& lhs, const D& rhs) {
        return rhs < lhs;
    }

    friend bool operator!= (const D& lhs, const D& rhs) {
        return (lhs < rhs) || (rhs < lhs);
    }

    friend bool operator== (const D& lhs, const D& rhs) {
        return !(lhs < rhs) && !(rhs < lhs);
    }

    friend bool operator<= (const D& lhs, const D& rhs) {
        return !(rhs < lhs);
    }

    friend bool operator>= (const D& lhs, const D& rhs) {
        return !(lhs < rhs);
    }
};

class Number: public less_than_comparable<Number>, public counter<Number> {
public:
    Number(int value): m_value{value} {}

    int value() const { return m_value; }

    bool operator<(Number const& other) const {
        return m_value < other.m_value;
    }

private:
    int m_value;
};

#endif // COUNTER_HPP