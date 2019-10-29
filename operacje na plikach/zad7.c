#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>

int main(int argc, char* varg[])
{
    int fd1;
    bool tekst = true;
    char x;
    fd1 = open(varg[1],O_RDWR);
    while (read(fd1,&x,1)>0)
    {
        if (isascii(x)!=true)
        {tekst = false;}
    }
    if (tekst) printf("Jest to plik tekstowy");
    else printf("Nie jest to plik tekstowy");



    return 0;
}