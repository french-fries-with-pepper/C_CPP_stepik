#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
	char ch;
    char s[500];
    char str[600];

    scanf("%c",ch);
    scanf("%s",s);
    printf("\n");

    scanf("%[^\n]%*c", &str);
  	
    printf("%c",ch);
    printf("\n");
    printf("%s",s);
    printf("\n");
    printf("%s",str);
    return 0;
}
