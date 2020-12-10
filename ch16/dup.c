#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    int cfd1, cfd2;
    char str1[] = "Hi~ \n";
    char str2[] = "It's nice day ~ \n";

    cfd1 = dup(1); // stdoutput = 1,  cfd = 3;
    cfd2 = dup2(cfd1, 7); //cfd2 = 7

    printf("cfd1 : %d , cfd2 : %d\n",cfd1, cfd2);
    write(cfd1,str1,sizeof(str1));
    write(cfd2,str2,sizeof(str2));

    close(cfd1);
    close(cfd2);
    write(1,str1, sizeof(str1));
    close(1);
    write(1,str1, sizeof(str1));
    return 0;


}