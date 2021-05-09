#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
  int   len;
  char  tmp;
  char  *src;

  src = (char *)s;
  tmp = (char)c;
  len = ft_strlen(s);
  while(len >= 0)
  {
    if(src[len] == tmp)
      return (src + len);
    len--;
  }
  return (0);
}
