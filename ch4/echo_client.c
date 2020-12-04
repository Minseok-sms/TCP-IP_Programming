#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024
void error_handling(char *message){
    printf("%s\n",message);
    exit(1);
}

int main(int argc, char *argv[]){
    int serv_sock;
    struct sockaddr_in serv_addr;
    char message[BUF_SIZE];
    int str_len, recv_cnt;
    int recv_len;


    if(argc != 3){
        printf("Usage : %s IP , Port\n", argv[0]);
        exit(1);
    }

    serv_sock = socket(PF_INET,SOCK_STREAM,0);
    if(serv_sock == -1) error_handling("socket() error\n");
    
    memset(&serv_addr, 0 , sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if(connect(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) error_handling("connect() error");
    else printf("Connected ...........\n");

    while(1){
        fputs("Input message(Q to quit) : ",stdout);
        fgets(message,BUF_SIZE,stdin);
        
        if(!strcmp(message, "q\n") || !strcmp(message, "Q\n"))
            break;
        
        write(serv_sock,message,strlen(message));
        str_len = read(serv_sock,message,BUF_SIZE - 1);
        recv_len = 0;
        
        while(recv_len < str_len){
            recv_cnt = read(serv_sock, &message[recv_len], BUF_SIZE - 1);
            recv_len += recv_cnt;
        }

        message[recv_len] = 0; // erase null;
        printf("Message from Server : %s", message);
    }
    close(serv_sock);
    return 0;
} 