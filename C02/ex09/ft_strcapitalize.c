/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 19:10:22 by seungyki          #+#    #+#             */
/*   Updated: 2021/02/23 16:32:03 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		checkint(char str)
{
	int i;

	i = 2;
	if (str >= 'a' && str <= 'z')
		i = 2;
	else if (str >= 'A' && str <= 'Z')
		i = 2;
	else if (str >= '0' && str <= '9')
		i = 2;
	else
		i = 1;
	return (i);
}

void	is_first(char *str)
{
	if (*str >= 'a' && *str <= 'z')
	{
		*str += 'A' - 'a';
	}
}

char	*ft_strcapitalize(char *str)
{
	unsigned int checker;
	unsigned int i;

	checker = 1;
	i = -1;
	while (str[++i])
	{
		if (checker == 1)
		{
			is_first(&str[i]);
		}
		else
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] -= 'A' - 'a';
		}
		checker = checkint(str[i]);
	}
	return (str);
}
