#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_IP_LEN 1024

int main(int argc, char *argv[])
{
    if (2 != argc)
    {
        fprintf(stderr, "usage: %s hostname\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    char ip[MAX_IP_LEN]= {0};
    struct hostent *info;
    struct in_addr **addr_list;
    if ((info = gethostbyname(argv[1])) == NULL)
    {
        herror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    addr_list = (struct in_addr**)info->h_addr_list;

    char *p = ip;
    int i = 0;
    for (i = 0; NULL != addr_list[i]; i++)
    {
        int off_set = 0;
        off_set = snprintf(p, MAX_IP_LEN - (p - ip), "%s ", inet_ntoa(*addr_list[i]));
        p += off_set;
    }
    fprintf(stdout, "%s resolve to %s\n", argv[1], ip);
    return 0;
}

