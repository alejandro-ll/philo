/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allera-m <allera-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:27:45 by allera-m          #+#    #+#             */
/*   Updated: 2023/04/04 19:45:08 by allera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	int	words;

	words = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != '\0')
			words++;
		while (*s != '\0' && *s != c)
			s++;
	}
	return (words);
}

static int	ft_count_chars(const char *s, char c)
{
	int	chars;

	chars = 0;
	while (*s != '\0' && *s != c)
	{
		chars++;
		s++;
	}
	return (chars);
}

static void	ft_free(char **arr, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		words;
	int		i;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	arr = (char **)malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*s == c)
			s++;
		arr[i] = ft_substr(s, 0, ft_count_chars(s, c));
		if (!arr[i])
			return (ft_free(arr, i), NULL);
		s += ft_count_chars(s, c);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
