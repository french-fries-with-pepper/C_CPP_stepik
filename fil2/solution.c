#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<unistd.h>
#include<string.h>
#include<stdbool.h>  // boolean things ... 
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>  // open file :-)


int SIZE = 1024;
char *PROCESSNAME = "genenv";
char *PATH = "/proc/";

bool checkFile(int fd, char *text){
    char res[SIZE];
    char name[SIZE];
    if(fd==-1){
        printf("cant open file\n");
        return false;
    }else{
        read(fd,res,SIZE);
        sscanf(res,"%s",name);
        if(strcmp(text,name)==0){
            return true;
        }else{
            return false;
        }
    }
}

int main(){

    struct dirent **namelist;
           int n;
            int count = 0;
           n = scandir(PATH, &namelist, NULL, alphasort);
           if (n == -1) {
               perror("scandir");
               exit(EXIT_FAILURE);
           }

           while (n--) {
               char checkPath[1024];
               if(isdigit(namelist[n]->d_name[0])){
               
               sprintf(checkPath,"%s%s/comm",PATH,namelist[n]->d_name);
               int fd = open(checkPath,O_RDONLY);

               if(checkFile(fd,PROCESSNAME)) ++count;
               } 
               free(namelist[n]);
           }
           free(namelist);
           printf("%d\n",count);

           exit(EXIT_SUCCESS);


    return 0;
}

