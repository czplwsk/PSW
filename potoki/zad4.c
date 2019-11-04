#include <stdio.h>
#include <unistd.h>

int main(int argc,char* argv[])
{
    int fd[2];
    int tab[4];
    tab[0]=1;
    tab[1]=2;
    tab[2]=3;
    tab[3]=4;
    pipe(fd);
    if(fork()==0)
    {
        int buf1[4];
        read(fd[0],buf1,4);
        close(fd[0]);
        for(int i=0;i<4;i++){buf1[i]++;}
        write(fd[1],buf1,4);
        close(fd[1]);
    }
    if(fork()==0)
    {
        int buf2[4];
        read(fd[0],buf2,4);
        close(fd[0]);
        for(int i=0;i<4;i++){buf2[i]++;}
        write(fd[1],buf2,4);
        close(fd[1]);
    }
    if(fork()==0)
    {
        close(fd[1]);
        int buf3[4];
        read(fd[0],buf3,4);
        close(fd[0]);
        for(int i=0;i<4;i++)
        {
            buf3[i]++;
            printf("%d\n",buf3[i]);
        }
    }
    close(fd[0]);
    write(fd[1],tab,4);
    close(fd[1]);
    return 0;
}
