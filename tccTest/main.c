#include <syscall.h>

void main(){
    int BUFSIZ=1024;
    char buf[BUFSIZ];
    int n;
    while (n=read(0,buf,BUFSIZ)>0)
    {
        write(1,buf,n);
    }
    

    return;
}