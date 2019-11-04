#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc,char* argv[])
{
    int fd[2];
    pipe(fd);
    if(fork()==0)
    {
        int y;
        close(fd[0]);
        for(int j=0;j<=10;j++)
        {
            y=(2*j)-1;
            write(fd[1],&y,1);
        }
        close(fd[1]);
    }
    if(fork()==0)
    {
        int x;
        close(fd[0]);
        for(int i=0;i<=10;i++)
        {
            x=2*i;
            write(fd[1],&x,1);
        }
        close(fd[1]);
    }
    close(fd[1]);
    int buf[2];
    int sum;
    while(read(fd[0],buf,2)>0)
    {
        sum=buf[0]+buf[1];
        printf("%d\n",sum);
    }
    close(fd[0]);
    
}
    
