#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>


int SIZE = 1024;


int main(){

    char  res[SIZE];
    int pid=0;
    char secondPar[SIZE/10];
    char debugInfo;

    int fileDesc = open("/proc/self/stat",O_RDONLY);
    if(fileDesc==-1){
        printf("cant open file\n");
        return 1;
    }else{
        read(fileDesc, res, SIZE);
        sscanf(res,"%d %s %c %d",&pid,secondPar,&debugInfo,&pid);
        printf("%d\n",pid);
        return 0;
    }
}


