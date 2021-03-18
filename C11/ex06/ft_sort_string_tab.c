/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 01:33:36 by seungyki          #+#    #+#             */
/*   Updated: 2021/03/18 01:02:25 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		str_cmp(char *a, char *b)
{
	while (*a && *b)
	{
		if (*a != *b)
			return (*a - *b);
		a++;
		b++;
	}
	return (*a - *b);
}

int		t_len(char **tab)
{
	int cnt;

	cnt = 0;
	while (tab[cnt])
		cnt++;
	return (cnt);
}

void	ft_sort_string_tab(char **tab)
{
	int		len;
	int		i;
	int		j;
	char	*tmp;

	len = t_len(tab);
	i = -1;
	while (++i < len - 1)
	{
		j = i;
		while (++j < len)
		{
			if (str_cmp(tab[i], tab[j]) > 0)
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
		}
	}
}
