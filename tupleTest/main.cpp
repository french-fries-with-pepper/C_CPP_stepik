#include <iostream>
#include <tuple>

std::tuple<int,int,int> gen(int id){
    if (id>0){
        return std::make_tuple(12,13,7);
    }else
    {
        return std::make_tuple(0,0,0);
    }
    
}
template<typename... Args>
int firstTest(std::tuple<Args...> a){
    if(std::get<0>(a)>0){
        return 1;
    }else
    {
        return 0;
    }
    
}

template<const int L,const int R,typename... A>
auto to_pair(std::tuple<A...> a) -> decltype(std::make_pair(std::get<L>(a),std::get<R>(a))) {
    auto pairFirst = std::get<L>(a);
    auto pairSecond = std::get<R>(a);
    return std::make_pair(pairFirst,pairSecond); 
}


int main(){

    auto a = gen(5);
    auto b = gen(-2);
    auto c = std::make_tuple(-3,17);

    auto res = to_pair<1,2>(a);

    std::cout << res.first << std::endl;



    return 0;
}