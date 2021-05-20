/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 13:37:20 by seungyki          #+#    #+#             */
/*   Updated: 2021/05/20 11:44:58 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef	struct		s_list
{
	int		minus;
	int		zero;
	int		star;
	int		dot;
	int		width;
	int		precision;
}					t_list;

size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
void				uppder_string(char *s);
void				ft_putstr(char *s);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strdup(char *s1);
char				*ft_itoa(int n);
char				*ft_uitoa(long n);
char				*ft_strjoin(char *s1, char *s2);
char				*make_str(char c);
char				*go_to_hex(long dummy, int cnt, long tmp, int up);
int					ft_atoi(const char *str, int *cnt);
int					is_max(int a, int b);
int					is_in(char *s, char c);
int					ft_printf(const char *string, ...);

#endif
