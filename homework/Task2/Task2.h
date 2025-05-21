#ifndef TYPELIST_HPP
#define TYPELIST_HPP

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

    template <typename T, typename... Ts>
    struct typelist_get<0, typelist<T, Ts...>> {
        using type = T;
    };

    template<int N, class P, class TL>
    struct type_list_index;

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

#endif // TYPELIST_HPP
