#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>

#include "get_next_line.h"

int main()
{
  int fd;
  int dump = 0;
  char *sol;

  fd = open("test", O_RDONLY);
  while(get_next_line(fd, &sol))  
  {
    dump++;
    printf("%s\n", sol); 
  }
}

