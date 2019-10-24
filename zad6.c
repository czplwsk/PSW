#include <stdio.h>
#include <unistd.h>
#include <fcnt1.h>

int main(int argc, char* varg[])
{
    int fd1,fd2;
    fd1 = open(varg[1],O_RDWR);
    fd2 = open(varg[2],O_RDWR);



    return 0;
}