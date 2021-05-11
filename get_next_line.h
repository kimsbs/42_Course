/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 09:51:58 by seungyki          #+#    #+#             */
/*   Updated: 2021/05/11 16:50:56 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

typedef	struct		s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

void				ft_lstadd_back(t_list **lst, char *content);
t_list				*ft_lstnew(char *content);

#endif
