#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>


int main(int argc, char *argv[])
{
    if (3 != argc)
    {
        fprintf(stderr, "usage: %s old_file new_link\n", argv[0]);
        return -1;
    }
    int ret = link(argv[1], argv[2]);
    if (0 != ret)
    {
        fprintf(stderr, "[%s:%d] %s\n", __FILE__, __LINE__, strerror(errno));
        perror("defined error");
        return -1;
    }
    else
    {
        fprintf(stderr, "done success.\n");
    }
    return 0;
}

