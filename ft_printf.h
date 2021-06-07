/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 13:37:20 by seungyki          #+#    #+#             */
/*   Updated: 2021/06/07 17:56:05 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef	struct		s_list
{
	int		minus;
	int		zero;
	int		star;
	int		dot;
	int		width;
	int		precision;
}					t_list;

void				input_data(long n, char *sol, int size, int start);
size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
void				uppder_string(char *s);
void				ft_putstr(char *s);
void				ft_printnstr(char *s, int *n);
void				*ft_memset(void *b, int c, size_t len);
void				print_integer(char *print, t_list *sub, int print_width);
void				print_string(char *print, t_list *sub, int print_width);
void				case_num(char *string, int *move, t_list *sub);
void				case_star(char *string, int *move, va_list op, t_list *sub);
void				case_dot(char *string, int *move, t_list *sub);
void				upper_string(char *s);
char				*ft_strdup1(char *s1);
char				*ft_strjoin1(char *s1, char *s2);
char				*ft_itoa(int n);
char				*ft_uitoa(long n);
char				*make_str(unsigned int c);
char				*go_to_hex(long dummy, int cnt, long tmp, int up);
int					ft_atoi(const char *str, int *cnt);
int					is_max(int a, int b);
int					is_min(int a, int b);
int					is_in(char *s, char c, int flag);
int					ft_printf(const char *string, ...);
int					ft_strcmp(char *s1, char *s2);
int					print_function_integer(char *print, int flag, t_list *sub);
int					print_function_string(char *print, int flag, t_list *sub);
int					print_function_char(char print, int flag, t_list *sub);
int					print_function_per(char print, int flag, t_list *sub);
int					print_function_ppp(char *print, int flag, t_list *sub);
int					write_something(char c, va_list op, int flag, t_list *sub);
int					write_something1(va_list op, int flag, t_list *sub);
int					write_something2(char c, va_list op, int flag, t_list *sub);

#endif
