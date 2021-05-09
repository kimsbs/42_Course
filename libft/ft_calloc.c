#include "libft.h"

void *ft_calloc(size_t count, size_t size)
{
  void *tmp;

  tmp = (void *)malloc(size * count);
  if(!tmp)
    return (NULL);
  ft_bzero(tmp, size * count);
  return (tmp);
}
