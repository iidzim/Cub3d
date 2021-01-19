/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 16:34:15 by iidzim            #+#    #+#             */
/*   Updated: 2021/01/19 18:17:49 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_strlen(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
		i++;
	return (i);
}

int			ft_strcmp(char *str, int c)
{
	int i;

	if (!c)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int			ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;
	int		diff;

	i = 0;
	diff = 0;
	// while (*s1 == 32)
	// 	s1++;
	while (n - 1 > i && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	diff = s1[i] - s2[i];
	return (diff);
}

long long	ft_atoi(t_data *d, char *str)
{
	unsigned long int n;

	n = 0;
	if (*str == '-')
		ft_print_msg("negative value", d);
	while (*str != '\0' && ft_isdigit(*str))
	{
		n = n * 10 + (*str - 48);
		str++;
	}
	if (*str == '\0')
		return (n);
	if (!ft_isdigit(*str))
		ft_print_msg("wrong argument", d);
	return (n);
}

int			ft_rtsrts(char *s, char *to_find)
{
	int l1;
	int l2;

	if (!s || !to_find)
		return (0);
	if ((l1 = ft_strlen(s)) <= 4)
		return (0);
	l2 = 4;
	while (l2 >= 1)
	{
		if (s[l1 - 1] != to_find[l2 - 1])
			return (0);
		l1--;
		l2--;
	}
	return (1);
}
