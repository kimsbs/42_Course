#include "libft.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
  size_t n_move;
  size_t h_move;

  h_move = 0;
  if (!*needle)
    return ((char *)haystack);
  while (haystack[h_move] && h_move < len)
  {
    if (haystack[h_move] == needle[0])
    {
      n_move = 0;
      while(needle[n_move] && haystack[h_move + n_move]
          && n_move + h_move < len)
        if (needle[n_move] == haystack[h_move + n_move])
          n_move++;
        else
          break ;
      if (needle[n_move] == '\0')
        return ((char *)&haystack[h_move]);
    }
    h_move++;
  }
  return (0);
}
