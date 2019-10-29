#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* varg[])
{
    int fd1,fd2;
    char nazwa[10];
    int x;
    if (argc==1)
    {

        printf("Podaj nazwe: ");
        fflush(stdout);
        scanf("%s",nazwa);
        fd1 = open(nazwa,O_RDWR);
        fd2 = open(nazwa,O_RDWR);
    }
    else
    {
        fd1 = open(varg[1],O_RDWR);
        fd2 = open(varg[1],O_RDWR);
    }
    while(read(fd1,&x,1)>0)
    {
        if((x>=65) && (x<=90))
        {
            x+=32;
            write(fd2,&x,1);
        }
        else if ((x>=97) && (x<=122))
        {
            x-=32;
            write(fd2,&x,1);
        }
    }



    return 0;
}