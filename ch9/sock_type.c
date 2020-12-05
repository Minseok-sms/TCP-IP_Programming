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
    int tcp_sock,udp_sock;
    int sock_type;
    socklen_t optlen;
    int state;

    optlen = sizeof(sock_type);
    tcp_sock = socket(PF_INET,SOCK_STREAM,0);
    udp_sock = socket(PF_INET,SOCK_DGRAM,0);

    state = getsockopt(tcp_sock, SOL_SOCKET, SO_TYPE, (void *)&sock_type, &optlen);
    printf("Socket type one: %d\n",sock_type);

    state = getsockopt(udp_sock,SOL_SOCKET, SO_TYPE, (void *)&sock_type, &optlen);
    printf("Socket type two: %d\n", sock_type);

    return 0;

}