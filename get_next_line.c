/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:51:46 by seungyki          #+#    #+#             */
/*   Updated: 2021/05/11 17:39:12 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		is_nextline(t_list *header)
{
	int move;
  int sol;
  if(!header)
    return (0);
	sol = 0;
  while(header)
  {
    move = 0;
	  while (header->content[move])
	  {
		  if (header->content[move] == '\n')
      {
		  	return (sol);
     }
	  	move++;
      sol++;
  	}
    header = header->next;
  }
	return (-1);
}

void free_list(t_list *header)
{
  if(!header)
    return ;
  free(header->content);
  free(header);
}

t_list	*save_buffer(t_list *header, size_t dummy, char **line)
{
	char	*tmp;
	int		move;
	int		tmp_move;
  t_list  *dump;

	tmp = (char *)malloc(sizeof(char) * (dummy + 1));
	tmp_move = 0;
	while (header)
	{
		move = -1;
		while (header->content[++move])
		{
      if(header->content[move] == '\n')
      {
        tmp[tmp_move] = '\0';
        *line = tmp;
        header->content = &(header->content[++move]);
        return (header);
      }
			tmp[tmp_move] = header->content[move];
			tmp_move++;
		}
    dump = header;
		header = header->next;
   // free_list(dump);
	}
  return (header);
}

void      print_list(t_list *list)
{
  char *srr;
  while(list)
  {
    srr = list->content;
    printf("%s", srr);
    list = list->next;
  }
}

int				get_next_line(int fd, char **line)
{
	int		rd_len;
	int		tmp;
	char	*buf;
	static  t_list	*header;

  buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while ((rd_len = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[rd_len] = '\0';
		ft_lstadd_back(&header, buf, rd_len);
		if ((tmp = is_nextline(header)) >= 0)
		{
			header = save_buffer(header, tmp, line);
			return (1);
		}
	}
	if (rd_len == 0)
  {
      if ((tmp = is_nextline(header)) >= 0)
		  {
			  header = save_buffer(header, tmp, line);
			  return (1);
		  }
		return (0);
  }
	else
		return (-1);
}
