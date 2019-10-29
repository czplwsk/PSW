#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int fd;
    fd=open(argv[1],O_RDWR);
    int l=0,c=0;
    char x;
    while(read(fd,&x,1)>0)
    {
        if(x != '\n')c++;
        else
        {
            if(c>l)l=c;
            c=0;
        }
    }
    printf("%d",&l);
    return 0;
}
