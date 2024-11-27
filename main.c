#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <strings.h>
#include <errno.h>
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
    pid_t p2 = 0;
    // int t1,t2;
    // t1 = get_rand();
    // t2 = get_rand();
    // perror("hello\n");
    // ((p1=fork())&&(p2=fork()));
    p1=fork();
    if(p1){
        p2=fork();
    }
    if(p1<0){
        perror("fork fail ):\n");//output to stderr instead of stdout
        exit(1);
    }
    else if(p2<0){
        perror("child2 is sad\n");
        perror(strerror(errno));
        exit(1);
    }
    else if(p1==0||p2==0){
        // int t1 = get_rand();
        int sleep_time = get_rand();
        printf("%d %dsec\n",getpid(),sleep_time);
        sleep(sleep_time);
        printf("%d finished after %dsec\n", getpid(), sleep_time);
        exit(sleep_time);  
    }
    else{
        printf("%d about to create 2 child process\n",getpid());
        int status;
        pid_t done_pid = wait(&status);
        int sleep_time = WEXITSTATUS(status);
        printf("Main Process %d is done. Child %d slept for %dsec\n", getpid(), done_pid, sleep_time);
    }
    return 0;
}