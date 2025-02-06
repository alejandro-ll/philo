/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allera-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 00:17:36 by allera-m          #+#    #+#             */
/*   Updated: 2023/03/11 01:01:35 by allera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char			*s1a;
	unsigned const char			*s2a;
	unsigned long				i;

	s1a = s1;
	s2a = s2;
	i = 0;
	while (i < n)
	{
		if (s1a[i] == s2a[i])
			i++;
		else
			return (s1a[i] - s2a[i]);
	}
	return (0);
}
