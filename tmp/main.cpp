#include<iostream>

int main(){

    int N = 256;
    int res = 0;

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            if(i+j>=N){
                ++res;
            }
        }
        
    }
    
    std::cout<< res<<"\n";
    return 0;
}