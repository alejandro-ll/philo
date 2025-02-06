/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allera-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 23:52:20 by allera-m          #+#    #+#             */
/*   Updated: 2023/03/31 16:11:33 by allera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && (i <= n - 1))
	{
		if (s1[i] != '\0' && s2[i] == '\0' || s1[i] == '\0' && s2[i] != '\0')
		{
			return (1);
		}
		if (s1[i] == s2[i])
		{
			i++;
		}
		else
		{
			return (1);
		}
	}
	return (0);
}
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*s1a;
	unsigned char	*s2a;

	s1a = (unsigned char *) s1;
	s2a = (unsigned char *) s2;
	i = 0;
	while ((s1a[i] != '\0' || s2a[i] != '\0') && i < n)
	{
		if (s1a[i] == '\0')
		{
			return (-s2a[i]);
		}
		else if (s2a[i] == '\0')
		{
			return (s1a[i]);
		}
		if (s1a[i] == s2a[i])
			i++;
		else
		{
			return (s1a[i] - s2a[i]);
		}		
	}
	return (0);
}
