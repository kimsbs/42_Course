#include "libft.h"

char  *ft_strchr(const char *s, int c)
{
  int   i;
  char  *src;
  char  tmp;

  tmp = (char)c;
  src = (char *)s;
  i = 0;
  while (src[i])
  {
    if (src[i] == tmp)
      return(src + i);
    i++;
  }
  if (tmp == '\0')
    return (src + i);
  return (0);
}
