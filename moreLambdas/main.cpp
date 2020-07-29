#include<iostream>
#include<utility>

auto base = [](std::string s){
    std::cout<< s <<"\n";
    return;
};

auto base2 = [](std::string s,std::string b){
    std::cout<< s << b <<"\n";
    return;
};
template<typename F,typename... Args>
auto apply(F&& func,Args&& ... args)-> decltype(func(std::forward<Args>(args)...)){
    return func(std::forward<Args>(args)...);
};

int main(){

    apply(base,"more");
    apply(base2,"hello ","lambdas!");

    auto fun = [](std::string a, std::string const& b) { return a += b; };


// s передаётся по lvalue ссылке,
// а временный объект по rvalue ссылке 
auto s = apply(fun, "Hello, ", "piete");

std::cout <<s <<"\n";

    return 0;
}