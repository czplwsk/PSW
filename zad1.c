#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc,char* argv[]){
    int fd1,fd2;
    fd1=open(argv[1],O_RDONLY);
    fd2=open(argv[2],O_WRONLY);

    char tab[250];
    int n;
    while((n=read(fd1,tab,250))>0)
    {
        write(fd2,tab,n);
    
    }
return 0;}
