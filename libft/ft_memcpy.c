/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:58:39 by allera-m          #+#    #+#             */
/*   Updated: 2024/11/28 09:57:19 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int		i;
	char				*ds;
	const char			*sr;

	i = 0;
	ds = dest;
	sr = src;
	if (ds == NULL && sr == NULL)
		return (0);
	while (i < n)
	{
		ds[i] = sr[i];
		i++;
	}
	return (dest);
}
