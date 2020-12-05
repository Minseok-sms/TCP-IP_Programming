#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
void error_handling(char *message){
       fputs(message, stderr);
       fputc('\n', stderr);
}

int main(int argc, char *argv[]){
    int snd_buf,rcv_buf;
    int sock;
    socklen_t len;
    int state;
    sock = socket(PF_INET,SOCK_STREAM,0);
    len = sizeof(snd_buf);
    
    state = getsockopt(sock,SOL_SOCKET, SO_SNDBUF, (void *)&snd_buf, &len);
    len = sizeof(rcv_buf);
    state = getsockopt(sock,SOL_SOCKET, SO_RCVBUF, (void *)&rcv_buf, &len);

    printf("Input buffer size: %d\n",rcv_buf);
    printf("Output buffer size: %d \n",snd_buf);

    return 0;

}