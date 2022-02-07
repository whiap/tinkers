#include <unistd.h>
#include <stdlib.h>

#define N 1024

int main() {
    char buff[N];
    int nread;
    nread = read(0, buff, N);
    if (nread == -1) {
        write(2, "a read error has occurred\n", 26);
    }

    if ((write(1, buff, nread)) != nread) {
        write(2, "a write error has occurred\n", 27);
    }
    exit(0);
}
