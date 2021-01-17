/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 16:34:20 by iidzim            #+#    #+#             */
/*   Updated: 2021/01/17 16:00:19 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int		ft_isspace(char s)
{
	if (!s)
		return (-1);
	if (s == 32)
		return (1);
	return (0);
}

int		ft_count_args(char **a)
{
	int i;

	i = 0;
	while (a[i])
		i++;
	return (i);
}

char	*remove_space(char *str)
{
	int size;
	int i;

	i = 0;
	size = ft_strlen(str) - 1;
	while (ft_isspace(*str))
	{
		str++;
		i++;
	}
	while (ft_isspace(str[size - i]))
		size--;
	str = ft_substr((const char *)str, (unsigned int)0, (size_t)size - i + 1);
	return (str);
}

int		ft_start_map(char *line, int *part2, t_data *d)
{
	int i;

	i = 0;
	while (line[i] == 32)
		i++;
	if (line[i] == '\0' && *part2 == 1)
		ft_print_msg("invalid map", d);
	if (*part2 == 1)
		return (1);
	if (ft_isdigit(line[i]))
		return (1);
	return (0);
}
