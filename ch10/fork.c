#include <stdio.h>
#include <unistd.h>

int gval = 10;
int main(int argc, char *argv[]){
    pid_t pid;
    int lval = 20;
    gval++, lval+= 5; // gval = 11, lval = 25

    pid = fork();
    if(pid == 0)
        gval+=2, lval += 2; // child process gval = 13, lval = 27
    else
        gval -= 2, lval -= 2; // parent process gval = 9 lval = 23

    if(pid == 0)
        printf("Child process: %d, %d\n",gval, lval);
    else
    {
        printf("Parent process: %d, %d\n", gval, lval);
    }
    
    return 0;
}