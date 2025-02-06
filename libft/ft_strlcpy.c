/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allera-m <allera-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:50:45 by allera-m          #+#    #+#             */
/*   Updated: 2023/03/19 16:25:11 by allera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	ft_strlen(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 	{
// 		i++;
// 	}
// 	return (i);
// }

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	int				ln;

	i = 0;
	ln = ft_strlen(src);
	if (size == 0)
	{
		return (ln);
	}
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ln);
}
/*
int main(void)
{
  char src[]="hola que tal estas";
  char dest[13]="00000000000000";
  ft_strlcpy(dest, src, 7);
  
  return (0);
}*/
