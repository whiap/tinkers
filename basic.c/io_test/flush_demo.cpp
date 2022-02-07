#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <inttypes.h>

#include <string>
#include <new>

#define FILEPERM      0644
#define CHUNKSIZE   8*1024
#define CHUNKNUME 128*1024

#define ERR_SUC   0
#define ERR_SYS  -1

int32_t WriteBuff(int32_t fd, const char* content, int64_t content_len)
{
    if (NULL == content || 0 == content_len)
    {
        return ERR_SYS;
    }

    const char* ptr = content;
    int bytes_write = 0;
    int ret = ERR_SUC;
    while (bytes_write = write(fd, ptr, content_len))
    {
        if ((-1 == bytes_write) && (EINTR != errno))
        {
            ret = ERR_SYS;
        }
        else if (content_len == bytes_write)
        {
            break;
        }
        else if (0 < bytes_write)
        {
            ptr += bytes_write;
            content_len -= bytes_write;
        }
    }
    if (-1 == bytes_write)
    {
        ret = ERR_SYS;
    }
    return ret;
}

std::string IntToString(int64_t val)
{
    char buf[64];
    snprintf(buf, sizeof(buf), "%lld", val);
    return std::string(buf);
}

void Fini(char* ptr)
{
    if (NULL != ptr)
    {
        delete [] ptr;
    }
}

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        printf("usage: %s file_name NumInG SleepTime\n", argv[0]);
        return ERR_SYS;
    }
    int32_t out_fd = -1;
    int64_t out_num = atoi(argv[2]);
    int64_t out_slp = atoi(argv[3]);
    if ((0 == out_num) || (0 == out_slp))
    {
        perror("input args failure");
        return ERR_SYS;
    }
    char *buff = new char[CHUNKSIZE];
    if (NULL == buff)
    {
        perror("malloc failure");
        return ERR_SYS;
    }
    std::memset(buff, 'a', CHUNKSIZE);
    int64_t cnt = out_num * CHUNKNUME;
    for (int32_t i = 0; i < cnt; ++i)
    {
        if (0 == i % (10 * CHUNKNUME))
        {
            close(out_fd);
            std::string fname = std::string(argv[1]) + "_" + IntToString(i) + ".file";
            out_fd = open(fname.c_str(), O_WRONLY | O_CREAT, FILEPERM);
            if (-1 == out_fd)
            {
                perror("open failure");
                return ERR_SYS;
            }
        }
        if (ERR_SUC != WriteBuff(out_fd, buff, CHUNKSIZE))
        {
            Fini(buff);
            perror("write failure");
            return ERR_SYS;
        }
        // unit: MB
        int64_t sleep_interval = (1024 * 1024 / CHUNKSIZE) * out_slp;
        if (0 == i % sleep_interval)
        {
            usleep(1000);
        }
    }
    Fini(buff);
    close(out_fd);
    return ERR_SUC;
}

