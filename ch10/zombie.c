#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    pid_t pid = fork();
    if(pid == 0)
        printf("Hi, I am a child process\n");
    else
    {
        printf("Child process ID : %d\n",pid);
        sleep(30);
    }

    if(pid == 0)
        printf("return chd process\n");
    else
    {
        printf("return par process\n");
    }
       
    return 0;
}