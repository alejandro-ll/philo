/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:10:34 by allera-m          #+#    #+#             */
/*   Updated: 2024/12/03 19:46:41 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
    char	*substr;

    if (s == NULL)
        return (NULL);
    if (ft_strlen(s) < start)
        return (ft_strdup(""));
    if (len > ft_strlen(s) - start)
        len = ft_strlen(s) - start;
    substr = (char *)malloc(sizeof(char) * (len + 1));
    if (!substr)
        return (NULL);
    ft_strlcpy(substr, (s + start), (len + 1));
    return (substr);
}
/*
int	main(void)
{
    char src[] = "substr";
    int m = 2;
    int n = 6;
    char* dest = ft_substr(src, m, n);
    printf("%s\n", dest);
    return 0;
}*/
