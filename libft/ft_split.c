/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allera-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:09:18 by allera-m          #+#    #+#             */
/*   Updated: 2023/04/10 15:09:21 by allera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**array_creator(char const *sOri, char cCmp, int *nItems)
{
	char	**a_point;
	int		*p_point;
	int		ia;

	p_point = nItems;
	*p_point = 0;
	ia = 0;
	while (*(sOri + ia) != '\0')
	{
		if (*(sOri + ia) == cCmp && *(sOri + ia - 1) != cCmp)
			*p_point += 1;
		ia ++;
	}
	if (*sOri != '\0')
		*p_point += 1;
	a_point = (char **) malloc((*p_point + 1) * sizeof(char *));
	if (a_point != NULL)
		a_point[*p_point] = NULL;
	return (a_point);
}

static void	array_free(char **aPointers, size_t nDim)
{
	size_t	ia;

	ia = 0;
	while (ia <= nDim)
	{
		free(aPointers[ia]);
		aPointers[ia] = NULL;
		ia ++;
	}
	free(aPointers);
}

static void	substring_creator(char **aInitial, char *sOri, char cCmp, int nSub)
{
	int		ia;
	char	*p_start;
	char	*p_end;

	p_start = sOri;
	ia = 0;
	if ((nSub > 0) && *sOri != '\0')
	{
		while (ia < (nSub - 1))
		{
			p_end = ft_strchr(p_start, cCmp);
			aInitial[ia] = ft_substr(p_start, 0, (p_end - p_start));
			if (aInitial[ia] == NULL)
			{
				array_free(aInitial, ia);
				return ;
			}
			while (*p_end == cCmp)
				p_end ++;
			p_start = p_end;
			ia ++;
		}
		aInitial[ia] = ft_strdup(p_start);
	}
}

char	**ft_split(char const *sMain, char cCmp)
{
	char	**a_point;
	char	*p_new;
	char	s_set[2];
	int		n_subs;

	*s_set = cCmp;
	*(s_set + 1) = '\0';
	if (sMain != NULL)
	{
		p_new = ft_strtrim(sMain, s_set);
		if (p_new != NULL)
		{
			a_point = array_creator(p_new, cCmp, &n_subs);
			if (a_point != NULL)
			{
				substring_creator(a_point, p_new, cCmp, n_subs);
				free(p_new);
				p_new = NULL;
				return (a_point);
			}
		}
	}
	return (NULL);
}