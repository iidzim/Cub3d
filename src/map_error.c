/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 16:33:55 by iidzim            #+#    #+#             */
/*   Updated: 2021/01/08 19:05:40 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_empty_line(t_data *d)
{
	int i;
	int j;

	i = 0;
	while (i < d->nbr_line)
	{
		j = 0;
		while (d->map[i][j] == 32)
			j++;
		if (d->map[i][j] == '\0')
			ft_print_msg("empty line : invalid map", d);
		i++;
	}
	return (1);
}

int		ft_check_intrus(t_data *d)
{
	int i;
	int j;

	i = -1;
	while (++i < d->nbr_line)
	{
		j = 0;
		while (j < d->nbr_column)
		{
			if (d->map[i][j] == 32 || d->map[i][j] == '0' ||
				d->map[i][j] == '1')
				j++;
			else if (d->map[i][j] == '2' || ft_strcmp("NEWS", d->map[i][j]))
			{
				ft_check_ply_spr(d, i, j, d->map[i][j]);
				j++;
			}
			else
				ft_print_msg("wrong character", d);
		}
	}
	d->ply.nbr > 1 ? ft_print_msg("more than one player", d) : 0;
	d->ply.nbr == 0 ? ft_print_msg("add player!", d) : 0;
	return (1);
}

int		ft_check_colmn(t_data *d)
{
	int i;
	int j;

	i = 0;
	while (i < d->nbr_line)
	{
		if (d->map[i][0] != 32 && d->map[i][0] != '1')
			ft_print_msg("map not surronded by walls", d);
		i++;
	}
	i = 0;
	j = d->nbr_column - 1;
	while (i < d->nbr_line)
	{
		if (d->map[i][j] != 32 && d->map[i][j] != '1')
			ft_print_msg("map not surronded by walls", d);
		i++;
	}
	return (1);
}

int		ft_check_line(t_data *d)
{
	int i;
	int j;

	j = 0;
	while (j < d->nbr_column)
	{
		if (d->map[0][j] != 32 && d->map[0][j] != '1')
			ft_print_msg("map not surronded by walls", d);
		j++;
	}
	i = d->nbr_line - 1;
	while (j < d->nbr_column)
	{
		if (d->map[i][j] != 32 && d->map[i][j] != '1')
			ft_print_msg("map not surronded by walls", d);
		j++;
	}
	return (1);
}

int		ft_check_space(t_data *d)
{
	int i;
	int j;

	i = -1;
	while (++i < d->nbr_line)
	{
		j = -1;
		while (++j < d->nbr_column)
		{
			if (d->map[i][j] == '0' || d->map[i][j] == '2' ||
				ft_strcmp("NEWS", d->map[i][j]))
			{
				if (d->map[i][j - 1] == 32 || d->map[i - 1][j] == 32)
					ft_print_msg("map not surronded by walls", d);
				if (d->map[i][j + 1] == 32 || d->map[i + 1][j] == 32)
					ft_print_msg("map not surronded by walls", d);
			}
		}
	}
	return (1);
}
