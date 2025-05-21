#include "Task2.h"
#include <bits/stdc++.h>

int main() {
    using namespace TL_space;

    // Проверка push_front
    static_assert(std::is_same_v<decltype(push_front<int>(typelist<>{})), typelist<int>>);
    static_assert(std::is_same_v<decltype(push_front<float>(typelist<int, double>{})), typelist<float, int, double>>);

    // Проверка push_back
    static_assert(std::is_same_v<decltype(push_back<void>(typelist<>{})), typelist<void>>);
    static_assert(std::is_same_v<decltype(push_back<char>(typelist<int, double>{})), typelist<int, double, char>>);

    // Проверка is_in_typelist
    static_assert(is_in_typelist<int>(typelist<int, double>{}));
    static_assert(!is_in_typelist<float>(typelist<int, double>{}));

    // Проверка typelist_size
    static_assert(typelist_size<typelist<>>::value == 0);
    static_assert(typelist_size<typelist<int>>::value == 1);
    static_assert(typelist_size<typelist<int, int>>::value == 2);

    // Проверка typelist_get
    static_assert(std::is_same_v<typelist_get<0, typelist<int>>::type, int>);
    static_assert(std::is_same_v<typelist_get<1, typelist<char, int>>::type, int>);
    static_assert(std::is_same_v<typelist_get<2, typelist<bool, char, int>>::type, int>);

    // Проверка type_list_index
    static_assert(type_list_index<0, int, typelist<int, double, char>>::value == 0, "OK");
    static_assert(type_list_index<0, char, typelist<int, double, char>>::value == 2, "OK");
    static_assert(type_list_index<0, float, typelist<int, double, char>>::value == -1, "OK");

    // Проверка операторов сравнения
    static_assert(typelist<int>{} == typelist<int>{});
    static_assert(typelist<int, double>{} != typelist<double, int>{});

    return 0;
}
