#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc,char* argv[]){
  int fd[2];
  pipe (fd);
  if(fork()==0)
  {
    close(fd[0]);
    dup2(1,fd[1]);
    execlp("ls","ls",NULL);
  }
  else
  {
    close(fd[1]);
    dup2(0,fd[0]);
    execlp("wc","wc",NULL);
  }

  return 0;
}
