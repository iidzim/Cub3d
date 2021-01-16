/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 19:18:47 by iidzim            #+#    #+#             */
/*   Updated: 2021/01/16 18:20:13 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_max_l(t_data *d)
{
	int i;
	int j;
	int max;

	if (!(d->w = malloc(sizeof(int) * d->nbr_line)))
		ft_exit(d, 1);
	i = -1;
	while (d->old_map[++i])
	{
		j = 0;
		while (d->old_map[i][j])
			j++;
		d->w[i] = j;
	}
	i = 0;
	max = d->w[0];
	while (++i < d->nbr_line)
	{
		if (d->w[i] > max)
			max = d->w[i];
	}
	return (max);
}

int		fill_new_map(t_data *d)
{
	int i;
	int j;

	i = -1;
	while (++i < d->nbr_line)
	{
		j = -1;
		while (++j < d->nbr_column)
		{
			if (d->w[i] == j)
			{
				while (d->nbr_column > j)
				{
					d->map[i][j] = ' ';
					j++;
				}
				d->map[i][j] = '\0';
			}
			else
				d->map[i][j] = d->old_map[i][j];
		}
	}
	d->map[i][0] = '\0';
	free(d->w);
	return (1);
}

int		resize_map(t_data *d)
{
	int i;

	i = 0;
	while (d->old_map[d->nbr_line])
		d->nbr_line++;
	if (!(d->map = malloc(sizeof(char*) * (d->nbr_line + 1))))
		ft_exit(d, 1);
	d->nbr_column = get_max_l(d);
	while (d->nbr_line >= i)
	{
		if (!(d->map[i] = malloc(sizeof(char) * (d->nbr_column + 1))))
			ft_exit(d, 1);
		i++;
	}
	fill_new_map(d);
	ft_clear(d->old_map);
	return (1);
}
