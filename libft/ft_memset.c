/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allera-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:32:46 by allera-m          #+#    #+#             */
/*   Updated: 2023/03/31 16:15:01 by allera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char				*s2;
	unsigned int		i;

	i = 0;
	s2 = s;
	while (i < n)
	{
		s2[i] = c;
		i++;
	}
	return (s);
}
/*
int	main(void)
{
	char *m = (char *) malloc (5);
	// ft_memset(m, 90, 5);
	// printf("%s\n", m);
	char hola[] = "hola";
	ft_memset(hola, 90, 2);
	printf("%s\n", hola);
	return (0);
}*/
