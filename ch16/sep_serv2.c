#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/select.h>

#define BUF_SIZE 1024
void error_handling(char *message){
    fputs(message, stderr);
    fputc('\n', stderr);
}
int main(int argc, char *argv[]){
    int serv_sock, clnt_sock;
    struct sockaddr_in serv_addr, clnt_addr;
    FILE *readfp;
    FILE *writefp;
    socklen_t clnt_adr_sz;
    char buf[BUF_SIZE] = {0,};

    serv_sock = socket(PF_INET,SOCK_STREAM,0);
    memset(&serv_addr,0,sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));
    bind(serv_sock,(struct sockaddr*)&serv_addr, sizeof(serv_addr));
    listen(serv_sock, 5);
    clnt_adr_sz = sizeof(clnt_addr);

    clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_adr_sz);
    readfp = fdopen(clnt_sock,"r");
    writefp = fdopen(dup(clnt_sock), "w");

    fputs("From Server : Hi client\n", writefp);
    fputs("i love you\n",writefp);
    fputs("awesome\n",writefp);
    fflush(writefp);

    shutdown(fileno(writefp), SHUT_WR);
    fclose(writefp);

    fgets(buf,sizeof(buf),readfp);
    fputs(buf,stdout);
    fclose(readfp);

    return 0;

}