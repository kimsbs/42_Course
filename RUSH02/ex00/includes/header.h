/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyolee <yong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 15:16:13 by seungyki          #+#    #+#             */
/*   Updated: 2021/03/14 22:19:56 by hyempark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

typedef struct	s_dict
{
	char		*nb;
	char		*name;
}				t_dict;

# define ERROR_MSG1 "Error!\n"
# define ERROR_MSG2 "Dict Error!\n"
# define E1_MSG 7
# define E2_MSG 12

t_dict			*g_dict;
int				g_len;

int				ft_is_space(char c);
int				ft_is_digit(char c);
int				trim_check(char *str);
char			*trim_null_free(char *nb);
char			*trim_unsigned_int(char *str);
void			print_dic_base(char *sol);
void			print_dic_value(char *sol);
char			*itoa(int nbr);
void			print_100_num(unsigned int nbr);
int				ft_atoi(char *str, int size);
void			shirink_base(char **base, int size);
void			get_upto_100_num(int size, char **str, int *len, char **base);
void			ft_putnbr(char *str);
int				input_str(char *tmp, int i);
void			write_num(char *tmp, int i, int *flag);
int				fill_dic(char *tmp, int is_input, int flag);
int				make_dic(char *name);
int				dict_len(char *name);
void			make_tmp(char *tmp, char *name);
void			put_str(char *str);
int				str_cmp(char *a, char *b);
void			free_dict(void);

#endif
