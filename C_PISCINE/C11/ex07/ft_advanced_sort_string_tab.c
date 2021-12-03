/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 01:33:36 by seungyki          #+#    #+#             */
/*   Updated: 2021/03/18 00:33:41 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		t_len(char **tab)
{
	int cnt;

	cnt = 0;
	while (tab[cnt])
		cnt++;
	return (cnt);
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		len;
	int		i;
	int		j;
	char	*tmp;

	len = t_len(tab);
	i = -1;
	while (++i < len)
	{
		j = 0;
		while (++j < len)
		{
			if (cmp(tab[j - 1], tab[j]) > 0)
			{
				tmp = tab[j - 1];
				tab[j - 1] = tab[j];
				tab[j] = tmp;
			}
		}
	}
}
