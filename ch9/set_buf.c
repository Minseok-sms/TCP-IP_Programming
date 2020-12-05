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
    int sock;
    int snd_buf = 1024 * 99999, rcv_buf = 1024 * 99999;
    int state;
    socklen_t len;
    sock = socket(PF_INET,SOCK_STREAM, 0);

    state = setsockopt(sock,SOL_SOCKET, SO_SNDBUF, (void *)&snd_buf, sizeof(snd_buf));
    state = setsockopt(sock,SOL_SOCKET, SO_RCVBUF, (void *)&rcv_buf, sizeof(rcv_buf));
    
    len = sizeof(snd_buf);
    state = getsockopt(sock,SOL_SOCKET, SO_SNDBUF, (void *)&snd_buf, &len);
    len = sizeof(rcv_buf);
    state = getsockopt(sock,SOL_SOCKET, SO_RCVBUF, (void *)&rcv_buf, &len);

    printf("Input buffer size: %d\n",rcv_buf);
    printf("Output buffer size: %d \n",snd_buf);

    return 0;

}