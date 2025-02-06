/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:43:59 by allera-m          #+#    #+#             */
/*   Updated: 2024/12/03 19:46:59 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
    char	*dup;
    size_t	len;

    len = ft_strlen(s1) + 1;
    dup = (char *)malloc(len);
    if (!dup)
        return (NULL);
    ft_memcpy(dup, s1, len);
    return (dup);
}
