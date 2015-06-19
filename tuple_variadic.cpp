#include <iostream>

template <typename T, typename... Tail> struct DoIt;

template <typename T, typename... Tail>
struct DoIt<std::tuple<T, Tail...>> {
    void operator() (std::tuple<T, Tail...> & t) {
        std::cout << std::to_string(std::get<0>(t)) << std::endl;
    }
};


////////////////////////////////////////////////////////////////////////////////

template<std::size_t> struct len_tuple {};

template <typename Tuple, size_t Id>
std::string DoSomething(const Tuple & t, len_tuple<Id>) {
    std::cout << std::get<std::tuple_size<Tuple>::value - Id>(t) << std::endl;
    return std::get<std::tuple_size<Tuple>::value - Id>(t) + DoSomething(t, len_tuple<Id-1>());
}


template <typename Tuple>
std::string DoSomething(const Tuple& t, len_tuple<1> /*i am useless*/) {
    std::cout << std::get<std::tuple_size<Tuple>::value - 1>(t) << std::endl;
    return std::get<std::tuple_size<Tuple>::value - 1>(t);
}

template <typename... Args>
std::string AskForAction(const std::tuple<Args...> & t) {
    return DoSomething(t, len_tuple<sizeof...(Args)>());
}

////////////////////////////////////////////////////////////////////////////////

int main() {
    auto t = std::make_tuple(1, 2, 3);
    DoIt<std::tuple<int, int, int>> () (t);

    auto t1 = std::make_tuple( "this ", "is ", "awesomeness" );
    std::string s = AskForAction(t1);

    std::cout << s << std::endl; // this prints "this is awesomeness"
}
