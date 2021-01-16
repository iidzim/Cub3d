/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:34:38 by iidzim            #+#    #+#             */
/*   Updated: 2021/01/08 19:14:55 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		nbr_count(char *s, char c)
{
	int i;
	int w;

	i = 0;
	w = 0;
	while (s[i])
	{
		if (s[i] == c && s[i])
			i++;
		else if (s[i] != c && s[i])
		{
			w++;
			i++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (w);
}

int		w_size(char *s, char c)
{
	int i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

char	*ft_next_word(char *s, char c)
{
	while (*s && *s == c)
		s++;
	return (s);
}

void	ft_clean(char **s, int c)
{
	while (c >= 0)
	{
		free(s[c]);
		c--;
	}
	free(s);
}

char	**ft_split(char *str, char c)
{
	int		i;
	int		nbr;
	char	**s;

	i = 0;
	if (!str)
		return (NULL);
	nbr = nbr_count(str, c);
	if (!(s = (char **)malloc(sizeof(char*) * (nbr + 1))))
		return (NULL);
	while (i < nbr)
	{
		str = ft_next_word(str, c);
		s[i] = ft_substr(str, 0, w_size(str, c));
		if (s[i] == NULL)
		{
			ft_clean(s, i);
			return (NULL);
		}
		i++;
		str += w_size(str, c);
	}
	s[nbr] = NULL;
	return (s);
}
