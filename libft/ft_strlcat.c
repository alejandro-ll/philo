/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allera-m <allera-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:27:50 by allera-m          #+#    #+#             */
/*   Updated: 2023/04/13 14:20:11 by allera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	dest_size;

	if (size <= ft_strlen(dest))
		return (size + ft_strlen(src));
	i = ft_strlen(dest);
	dest_size = 0;
	while (src[dest_size] != '\0' && i + 1 < size)  // i++ < size   ++i
	{
		dest[i] = src[dest_size];
		i++;
		dest_size++;
	}
	dest[i] = '\0';
	return (ft_strlen(dest) + ft_strlen(&src[dest_size]));
}
/*
int    main(void)
{
    char dest[15]="hola mundo";
    char src[]="olaaa";
    ft_strlcat(dest, src, 3);
    return(0);
}*/
