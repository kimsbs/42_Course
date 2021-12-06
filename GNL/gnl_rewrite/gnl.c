#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int	ft_strlen(char *s1)
{
	int	move = 0;
	while(s1[move])
	{
		move++;
	}
	return (move);
}

char *ft_strdup(char *from)
{
	int len;
	int	move = -1;
	char *out;

	len = ft_strlen(from);
	out = malloc((len + 1) * sizeof(char));
	while(++move < len)
		out[move] = from[move];
	out[len] = '\0';
	return(out);
}

char *ft_strjoin(char *s1, char *s2)
{
	int len1;
	int	len2;
	int	move = -1;
	char *out;

	if(!s1)
		return(ft_strdup(s2));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	out = malloc( (len1 + len2 + 1) * sizeof(char) );
	while(++move < len1)
		out[move] = s1[move];
	free(s1);
	move = -1;
	while(++move < len2)
		out[move + len1] = s2[move];
	out[move + len1] = '\0';
	return (out);
}

int	is_enter(char *source)
{
	int move = 0;

	while(source[move])
	{
		if(source[move] == '\n')
			return (move);
		move++;
	}
	return (-1);
}

char *cut(char **remain, int where)
{
	int len;
	char *out;
	char *tmp;
	char *string;

	string = *remain;

	len = ft_strlen(string);
	string[where] = '\0';
	tmp = ft_strdup(&string[where + 1]);	
	out = ft_strdup(string);
	free(*remain);
	*remain = tmp;
	return(out);
}


char *gnl(int fd)
{
	int	len;
	int	where;
	static char *remain;
	char buf[11];
	char *out;

	out = NULL;
	while((len = read(fd, buf, 10)) > 0)
	{
		buf[len] = '\0';
		remain = ft_strjoin(remain, buf);
	}
	if(!remain)
		return (NULL);
	where = is_enter(remain);
	if(where != -1)
		out = cut(&remain, where);
	else
	{
		out = ft_strdup(remain);
		free(remain);
		remain = NULL;
	}
	return(out);
}
