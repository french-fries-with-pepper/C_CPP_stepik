#include <iostream>
#include <cstring>
using namespace std;

struct FirstStruct
{
    FirstStruct(int age,const char* name)
    : age_{age}{
        size_t s = strlen(name);
        char * res = new char[s+1];
        strcpy(res,name);
        this->name_=res;
    };
    void printName(){
        cout << name_ << '\n';
    }
    void printAge(){
        cout << age_ << '\n';
    }
    private:
        int age_;
        char *name_;
};

int main(){
    int myAge = 0;
    char myName[30];

    cout << "enter your name\n";
    cin >> myName;
    cout << "enter your age";
    cin >> myAge;


    FirstStruct first(myAge,myName);

    first.printAge();
    first.printName(); 

    return 0;
}