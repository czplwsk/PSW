#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* varg[])
{
  int fd1,fd2;
  char x,y;
  fd1=open(varg[1],O_RDONLY);
  fd2=open(varg[2],O_RDONLY);
  while(read(fd1,&x,1)>0)
  {
    read(fd2,&y,1);
    if (x=!y)
    {
      printf("Pliki sie roznia");
      return 0;
    }
  }
  if (read(fd2,&y,1)>0)
  {
    printf("Pliki sie roznia");
    return 0;
  }
  else printf("Pliki sa takie same");
  return 0;
}
