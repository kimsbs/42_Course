/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:48:13 by seungyki          #+#    #+#             */
/*   Updated: 2021/03/07 22:06:59 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		str_cmp(char *str1, char *str2)
{
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 == *str2)
		{
			str1++;
			str2++;
		}
		else
			return (*str1 - *str2);
	}
	if (*str1 != *str2)
		return (*str1 - *str2);
	else
		return (0);
}

void	swap(char **str1, char **str2)
{
	char *tmp;

	tmp = *str1;
	*str1 = *str2;
	*str2 = tmp;
}

void	sort(char **argv, int cnt)
{
	int	i;
	int	j;
	int	sol;

	i = 0;
	while (++i < cnt)
	{
		j = i;
		while (++j < cnt)
		{
			sol = str_cmp(argv[i], argv[j]);
			if (sol > 0)
			{
				swap(&argv[i], &argv[j]);
			}
		}
	}
}

void	print(char **argv, int cnt)
{
	int i;

	i = 0;
	while (++i < cnt)
	{
		while (*argv[i])
		{
			write(1, argv[i], 1);
			argv[i]++;
		}
		write(1, "\n", 1);
	}
}

int		main(int argc, char **argv)
{
	sort(argv, argc);
	print(argv, argc);
}
