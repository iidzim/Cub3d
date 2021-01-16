/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 19:01:47 by iidzim            #+#    #+#             */
/*   Updated: 2021/01/14 17:01:37 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_check_ply_spr(t_data *d, int i, int j, int c)
{
	if (c == '2')
		d->s.nbr += 1;
	else if (ft_strcmp("NEWS", c))
	{
		d->ply.pos = c;
		d->ply.nbr += 1;
		d->pos.x = i + 0.05;
		d->pos.y = j + 0.05;
	}
	return (1);
}

void	ft_init_player(t_data *d)
{
	if (d->ply.pos == 'N')
	{
		d->plane.x = 0.66;
		d->plane.y = 0;
		d->dir.x = 0;
		d->dir.y = -1;
	}
	if (d->ply.pos == 'S')
	{
		d->plane.x = -0.66;
		d->plane.y = 0;
		d->dir.x = 0;
		d->dir.y = 1;
	}
	ft_init_player2(d);
}

void	ft_init_player2(t_data *d)
{
	if (d->ply.pos == 'W')
	{
		d->plane.x = 0;
		d->plane.y = -0.66;
		d->dir.x = -1;
		d->dir.y = 0;
	}
	if (d->ply.pos == 'E')
	{
		d->plane.x = 0;
		d->plane.y = 0.66;
		d->dir.x = 1;
		d->dir.y = 0;
	}
}

void	ft_sprite(t_data *d)
{
	int i;
	int j;
	int k;

	k = 0;
	i = -1;
	while (d->nbr_line > ++i)
	{
		j = -1;
		while (d->nbr_column > ++j && d->s.nbr > k)
		{
			if (d->map[i][j] == '2')
			{
				d->s.sprite[k][0] = (double)i + 0.4;
				d->s.sprite[k][1] = (double)j + 0.4;
				k++;
			}
		}
	}
}

void	sort_sprite(t_data *d)
{
	int		i;
	int		j;
	double	temp;

	i = -1;
	while (d->s.nbr - 1 > ++i)
	{
		j = i;
		while (d->s.nbr > ++j)
		{
			if (d->s.sprite[i][2] < d->s.sprite[j][2])
			{
				temp = d->s.sprite[i][0];
				d->s.sprite[i][0] = d->s.sprite[j][0];
				d->s.sprite[j][0] = temp;
				temp = d->s.sprite[i][1];
				d->s.sprite[i][1] = d->s.sprite[j][1];
				d->s.sprite[j][1] = temp;
				temp = d->s.sprite[i][2];
				d->s.sprite[i][2] = d->s.sprite[j][2];
				d->s.sprite[j][2] = temp;
			}
		}
	}
}
