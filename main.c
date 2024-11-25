#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
int get_rand(){
    int r = -1;
    int file = open("/dev/urandom",O_RDONLY,0);
    int r_file = read(file,&r,4);
    if (r < 0){r*=-1;}
    r%=5+1;
    return r;
}
int main()
{
    pid_t p1;
    pid_t p2;
    p1 = fork();
    int r = -1;
    pid_t p2 = fork();

    
}