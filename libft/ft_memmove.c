/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 23:29:34 by allera-m          #+#    #+#             */
/*   Updated: 2024/11/28 09:56:42 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned long	i;
	char			cp[500];
	char			*ds;
	const char		*sr;

	i = 0;
	sr = src;
	ds = dst;
	if (ds == '\0' && sr == '\0')
		return (0);
	while (i < len)
	{
		cp[i] = sr[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		ds[i] = cp[i];
		i++;
	}
	return (dst);
}*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned long	i;
	char			*ds;
	const char		*sr;

	i = 0;
	sr = src;
	ds = dst;
	if (ds == NULL && sr == NULL)
		return (NULL);
	if (ds > sr)
	{
		while (len--)
		{
			ds[len] = sr[len];
		}
	}
	else
	{
		while (i < len)
		{
			*ds++ = *sr++;
			i++;
		}
	}
	return (dst);
}
