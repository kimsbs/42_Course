#include "libft.h"

int   ft_strncmp(const char *s1, const char *s2, size_t n)
{
  size_t  move;

  move = 0;
  while (move < n && s1[move] && s2[move])
    if (s1[move] == s2[move])
      move++;
    else
      break ;
  if (n == 0)
    return (0);
  else if (move < n)
    return ((unsigned char)s1[move] - (unsigned char)s2[move]);
  else
    return (0);
}
