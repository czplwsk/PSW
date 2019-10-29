#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc,char* argv[]){
    int fd1;
    fd1=open(argv[1],O_RDWR);
    int n = lseek(fd1,0,SEEK_END);
    printf("%d \n",n);
    return 0;}
