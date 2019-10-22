#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int fd1,fd2;
    fd1=open(argv[1],O_RDWR);
    fd2=open(argv[2],O_WRONLY);
    
