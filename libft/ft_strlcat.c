#include "libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
  size_t  dst_len;
  size_t  src_len;
  size_t  j;

  dst_len = ft_strlen(dst);
  src_len = ft_strlen(src);
  if(dstsize == 0)
    return (src_len);
  else if (dst_len >= dstsize)
    return (src_len + dstsize);
  j = 0;
  while (j + 1 + dst_len < dstsize && src[j])
  {
    dst[dst_len + j] = src[j];
    j++;
  }
  dst[dst_len + j] = '\0';
  return (dst_len + src_len);
}
