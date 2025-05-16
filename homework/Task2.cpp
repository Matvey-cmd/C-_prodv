#include <bits/stdc++.h>

namespace TL_space {
template <typename... Ts>
struct typelist {};

template<typename... Ts, typename... Us>
constexpr bool operator==(typelist<Ts...>, typelist<Us...>) { return false; }

template<typename... Ts>
constexpr bool operator==(typelist<Ts...>, typelist<Ts...>) { return true; }

template<typename... Ts, typename... Us>
constexpr bool operator!=(typelist<Ts...>, typelist<Us...>) { return true; }

template<typename... Ts>
constexpr bool operator!=(typelist<Ts...>, typelist<Ts...>) { return false; }

template <typename T, typename... Ts>
constexpr typelist<T, Ts...> push_front(typelist<Ts...>) { return {}; }

template <typename T, typename... Ts>
constexpr typelist<Ts..., T> push_back(typelist<Ts...>) { return {}; }

template <typename T, typename... Ts>
constexpr bool is_in_typelist(typelist<Ts...>) {
    return (std::is_same_v<T, Ts> || ...);
}

template <typename TL>
struct typelist_size;

template <typename... Ts>
struct typelist_size<typelist<Ts...>> {
    static constexpr std::size_t value = sizeof...(Ts);
};

template <size_t N, typename TL>
struct typelist_get;

template <size_t N, typename T, typename... Ts>
struct typelist_get<N, typelist<T, Ts...>> {
    using type = typename typelist_get<N-1, typelist<Ts...>>::type;
};

template<int N, class P, class TL>
struct type_list_index;

template <typename T, typename... Ts>
struct typelist_get<0, typelist<T, Ts...>> {
    using type = T;
};

template<int N, class P>
struct type_list_index<N, P, typelist<> > {
    static constexpr int value = -1;
};

template<int N, class P, typename T, typename... Ts>
struct type_list_index<N, P, typelist<T, Ts...>>
        : type_list_index<N + 1, P, typelist<Ts...>> {
};

template<int N, class P, typename... Ts>
struct type_list_index<N, P, typelist<P, Ts...>> {
    static constexpr int value = N;
};
}

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
}