#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

#define N 1024

int main(int argc, char* argv[]) {
    char block[N];
    int in, out, nread;

    in = open(argv[1], O_RDONLY);
    out = open(argv[2], O_WRONLY | O_CREAT, S_IRUSR| S_IWUSR);

    nread = read(in, block, sizeof(block));
    while (nread > 0) {
        write(out, block, nread);
        nread = read(in, block, sizeof(block));
    }
    exit(0);
}
