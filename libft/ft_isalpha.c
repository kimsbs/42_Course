#include "libft.h"

int   ft_isalpha(int c)
{
  unsigned char tmp;
  
  if(c < 0)
    return (0);
  tmp = (unsigned char)c;

  if(tmp >= 'a' && tmp <= 'z')
    return (1);
  else if(tmp >= 'A' && tmp <= 'Z')
    return (2);
  else
    return (0);
}
