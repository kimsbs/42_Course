#include "../includes/so_long.h"

int		ft_strlen(const char *s)
{
	int move;

	move = 0;
	while (s[move])
		move++;
	return (move);
}

char		*ft_strdup(const char *s1)
{
	int		len;
	int		move;
	char	*dup;

	len = ft_strlen(s1);
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup)
		exit_handler("Malloc error\n");
	move = 0;
	while (s1[move])
	{
		dup[move] = s1[move];
		move++;
	}
	dup[move] = '\0';
	return (dup);
}

int		ft_strlcpy(char *dst, const char *src, int dstsize)
{
	int	src_len;
	int	i;

	if (!dst || !src)
		return (0);
	src_len = ft_strlen(src);
	if (dstsize > 0)
	{
		i = 0;
		while (src[i] && i + 1 < dstsize)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	char	*join;

	if (!s1 && !s2)
        return (0);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
    join = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!join)
        exit_handler("Malloc error\n");
	ft_strlcpy(join, s1, s1_len + 1);
    ft_strlcpy(&join[s1_len], s2, s2_len + 1);
	free((char *)s1);
	s1 = NULL;
	return (join);
}