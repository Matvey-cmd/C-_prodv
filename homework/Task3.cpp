#include <bits/stdc++.h>
#include "Task2.cpp"

template <typename... Ts>
class TypeMap {
    TL_space::typelist<Ts...> types;
    std::array<std::variant<Ts...>, sizeof...(Ts)> values;
    std::array<bool, sizeof...(Ts)> isValue;
public:

    TL_space::typelist<Ts...> getTypes () { return types; }

    template <typename T, typename R>
    void AddValue (R value);

    template <typename T>
    T getValue ();

    template <typename T>
    bool inTypeMap ();

    template <typename T>
    void deleteValue ();
};

template <typename... Ts>
template <typename T, typename R>
void TypeMap<Ts...>::AddValue (R value) {
    static_assert((std::is_same_v<T, R>) == true);
    size_t index = TL_space::type_list_index<T>(TypeMap::getTypes());
    values[index] = value;
    isValue[index] = true;
}

template <typename... Ts>
template <typename T>
T TypeMap<Ts...>::getValue () {
    size_t index = TL_space::type_list_index<T>(TypeMap::getTypes());
    if (!isValue[index])
        throw ("No value on this type!");
    return std::get<T>(values.at(index));
}

template <typename... Ts>
template <typename T>
bool TypeMap<Ts...>::inTypeMap() {
    size_t index = TL_space::type_list_index<T>(TypeMap::getTypes());
    return isValue[index];
}

template <typename... Ts>
template <typename T>
void TypeMap<Ts...>::deleteValue () {
    size_t index = TL_space::type_list_index<T>(TypeMap::getTypes());
    isValue[index] = false;
}
