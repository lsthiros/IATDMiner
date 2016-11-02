#include "usart.h"

int _write(int fd, char *buf, int nbytes)
{
    debugUsartWrite(buf, nbytes);
    return nbytes;
}
