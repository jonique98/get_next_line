#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *backup;
    char buff[BUFF_SIZE];
    int read_size;
    int index;

    while ((read_size = read(fd, buff, BUFF_SIZE)) > 0)
    {
        
    }
}