 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXLINE 80
#define SERV_PORT 8000

int main(void)
{
    char buf[MAXLINE];

    int listenfd = 0;
    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in servaddr = {0};
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);

    bind(listenfd, (sockaddr *)&servaddr, sizeof(servaddr));
    listen(listenfd, 20);

    printf("Accepting connections ...\n");
    while (1) 
    {
        sockaddr_in cliaddr = {0};
        socklen_t cliaddr_len = sizeof(cliaddr);
        int connfd = accept(listenfd, (sockaddr *)&cliaddr, &cliaddr_len);
 
        char str[INET_ADDRSTRLEN];
        printf("connected from %s at PORT %d\n",
                inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)),
                ntohs(cliaddr.sin_port));

        while(true)
        {
            int count = read(connfd, buf, MAXLINE);
            if (count == 0)
                break;

            write(connfd, buf, count);
        }

        close(connfd);
        printf("closed from %s at PORT %d\n",
                inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)),
                ntohs(cliaddr.sin_port));
    }
}