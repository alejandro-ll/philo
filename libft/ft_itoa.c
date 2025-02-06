/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allera-m <allera-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 21:33:59 by allera-m          #+#    #+#             */
/*   Updated: 2023/03/27 13:43:47 by allera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_digit(int n)
{
	int	n_dig;

	n_dig = 0;
	if (n == 0)
	{
		n_dig = 1;
	}	
	if (n < 0)
	{
		n = n * -1;
		n_dig++;
	}
	if (n > 0)
	{
		while (n > 0)
		{
			n /= 10;
			n_dig++;
		}
	}
	return (n_dig);
}

void	fill_array(char *str, int nb, int i)
{
	while (nb > 0)
	{
		str[i--] = nb % 10 + '0';
		nb /= 10;
	}
}

char	*ft_itoa(int n)
{
	int		i;
	int		nb;
	char	*str;

	nb = n;
	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	i = ft_count_digit(n);
	str = (char *)malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (nb == 0)
	{
		str[0] = '0';
	}
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	if (nb > 0)
		fill_array(str, nb, i);
	return (str);
}
