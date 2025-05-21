#ifndef TYPEMAP_HPP
#define TYPEMAP_HPP

#include <optional>
#include <stdexcept>
#include <tuple>
#include "../Task2/Task2.h"

template <typename... Types>
class TypeMap {
    using StorageType = std::tuple<std::optional<Types>...>;
    StorageType storage;

public:
    template <typename T>
    void AddValue(T&& value) {
        static_assert(TL_space::is_in_typelist<T>(TL_space::typelist<Types...>{}),
                     "Type not allowed in this TypeMap");
        std::get<std::optional<T>>(storage) = std::forward<T>(value);
    }

    template <typename T>
    decltype(auto) GetValue() const {
        static_assert(TL_space::is_in_typelist<T>(TL_space::typelist<Types...>{}),
                     "Type not allowed in this TypeMap");
        const auto& opt = std::get<std::optional<T>>(storage);
        if (!opt) throw std::runtime_error("Value not found");
        return *opt;
    }

    template <typename T>
    bool Contains() const {
        return std::get<std::optional<T>>(storage).has_value();
    }

    template <typename T>
    void RemoveValue() {
        std::get<std::optional<T>>(storage).reset();
    }
};

#endif // TYPEMAP_HPP