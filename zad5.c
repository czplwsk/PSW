<<<<<<< HEAD
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc,char* argv[])
{
    int fd1,fd2,i;
    char x;
    fd1=open(argv[1],O_RDWR);
    fd2=open(argv[2],O_RDWR);
    int n = lseek(fd1,0,SEEK_END);
    for(i=1;i<=n;i++)
    {
        lseek(fd1,-i,SEEK_END);
        read(fd1,&x,1);
        write(fd2,&x,1);
    }
    return 0;

}
=======
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int fd1,fd2;
    fd1=open(argv[1],O_RDWR);
    fd2=open(argv[2],O_WRONLY);
    
>>>>>>> bb8fb86e3efad7bb385604deb958b05b806ad0c9
