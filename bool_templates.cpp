#include <iostream>


template <bool, typename T> struct Foo;

template <typename T>
struct Foo<true, T>{
    auto operator() (T t){
        std::cout << "true" << sizeof(t) << std::endl;
    }
};

template <typename T>
struct Foo<false, T>{
    auto operator() (T t){
        std::cout << "false" << t.size() << std::endl;
    }
};


template <bool> struct Bar;

template <>
struct Bar<true>{
    auto operator() (){
        std::cout << "true" << std::endl;
    }
};

template <>
struct Bar<false>{
    auto operator() (){
        std::cout << "false" << std::endl;
    }
};

int main() {
    Foo<false, std::string>()("bla");
    Foo<true, int>()(5);
    Bar<true>()();
    Bar<false>()();
    std::cout << "hmm" << std::endl;

}

