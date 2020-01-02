#include <iostream>
using namespace std;

unsigned strlen(const char *str)
{
    unsigned size = 0;
    for (;;)
    {
        if (*str == '\0')
        {
            return size;
        }
        ++str;
        ++size;
    }
}

int strstr(const char *text, const char *pattern)
{
    unsigned textSize = strlen(text);
    unsigned patternSize = strlen(pattern);

    if(*pattern=='\0'){
        return 0;
    }

    if((*text=='\0')||(textSize<patternSize)){
        return -1;
    }

    
    

    for (int i = 0; i < textSize; i++)
    {
        bool found_it = true;
        for (int j = 0; j < patternSize; j++)
        {
            if (text[i+j]!=pattern[j])
            {
                found_it = false;
                break;
            }
            
        }
        if(found_it){
            return i;
        }
    }
    return -1;
}

int main(){

    char text1[] = "helllo dude";
    char pattern1[] = "mmm";

    char text2[] = "";
    char pattern2[] = "";

    cout << strstr(text1,pattern1) << endl;
    cout << strstr(text2,pattern2) << endl;

    return 0;
}