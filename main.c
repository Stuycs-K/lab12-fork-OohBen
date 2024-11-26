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
    close(file);
    if (r < 0){r*=-1;}
    r%=5+1;
    return r;
}
int main()
{
    pid_t p1;
    pid_t p2;
    // int t1,t2;
    // t1 = get_rand();
    // t2 = get_rand();
    ((p1=fork())&&(p2=fork()));
    if(p1<0||p2<0){
        perror("fork fail ):");//output to stderr instead of stdout
        exit(1);
    }
    else if(p1==0||p2==0){
        int t1 = get_rand();
        printf("%d %dsec",getpid(),t1);
        waitpid(getpid(),&t1,0);
    }
    else{
        printf("%d about to create 2 child process",getpid());

    }

    
}