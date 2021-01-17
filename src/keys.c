/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 16:33:27 by iidzim            #+#    #+#             */
/*   Updated: 2021/01/16 19:33:10 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_key(int keycode, t_data *d)
{
	d->oldplanex = d->plane.x;
	if (keycode == KEY_ESC)
		ft_exit(d, 0);
	key_ws(keycode, d);
	key_ad(keycode, d);
	key_rl(keycode, d);
	mlx_clear_window(d->mlx_ptr, d->win_ptr);
	cast(d);
	return (1);
}

int	key_ws(int keycode, t_data *d)
{
	if (keycode == KEY_W)
	{
		if ((int)(d->pos.x + d->dir.x * MOVESPD) < d->nbr_line &&
			(int)(d->pos.y) < d->nbr_column && d->map[(int)(d->pos.x +
				d->dir.x * MOVESPD)][(int)(d->pos.y)] != '1')
			d->pos.x += d->dir.x * MOVESPD;
		if ((int)(d->pos.x) < d->nbr_line && (int)(d->pos.y + d->dir.y *
			MOVESPD) < d->nbr_column && d->map[(int)(d->pos.x)]
				[(int)(d->pos.y + d->dir.y * MOVESPD)] != '1')
			d->pos.y += d->dir.y * MOVESPD;
	}
	if (keycode == KEY_S)
	{
		if ((int)(d->pos.x - d->dir.x * MOVESPD) < d->nbr_line &&
			(int)(d->pos.y) < d->nbr_column && d->map[(int)(d->pos.x -
				d->dir.x * MOVESPD)][(int)(d->pos.y)] != '1')
			d->pos.x -= d->dir.x * MOVESPD;
		if ((int)(d->pos.x) < d->nbr_line && (int)(d->pos.y - d->dir.y *
			MOVESPD) < d->nbr_column && d->map[(int)(d->pos.x)]
				[(int)(d->pos.y - d->dir.y * MOVESPD)] != '1')
			d->pos.y -= d->dir.y * MOVESPD;
	}
	return (1);
}

int	key_ad(int keycode, t_data *d)
{
	if (keycode == KEY_A)
	{
		if ((int)(d->pos.y - d->dir.x * MOVESPD) < d->nbr_column &&
			(int)(d->pos.x) < d->nbr_line && d->map[(int)(d->pos.x)]
				[(int)(d->pos.y - d->dir.x * MOVESPD)] != '1')
			d->pos.y -= d->dir.x * MOVESPD;
		if ((int)(d->pos.y) < d->nbr_column && (int)(d->pos.x + d->dir.y *
			MOVESPD) < d->nbr_line && d->map[(int)(d->pos.x + d->dir.y *
				MOVESPD)][(int)(d->pos.y)] != '1')
			d->pos.x += d->dir.y * MOVESPD;
	}
	if (keycode == KEY_D)
	{
		if ((int)(d->pos.y + d->dir.x * MOVESPD) < d->nbr_column &&
			(int)(d->pos.x) < d->nbr_line && d->map[(int)(d->pos.x)]
				[(int)(d->pos.y + d->dir.x * MOVESPD)] != '1')
			d->pos.y += d->dir.x * MOVESPD;
		if ((int)(d->pos.y) < d->nbr_column && (int)(d->pos.x - d->dir.y *
			MOVESPD) < d->nbr_line && d->map[(int)(d->pos.x - d->dir.y *
				MOVESPD)][(int)(d->pos.y)] != '1')
			d->pos.x -= d->dir.y * MOVESPD;
	}
	return (1);
}

int	key_rl(int keycode, t_data *d)
{
	if (keycode == KEY_RIGHT)
	{
		d->oldirx = d->dir.x;
		d->dir.x = d->dir.x * cos(-ROTSPD) - d->dir.y * sin(-ROTSPD);
		d->dir.y = d->oldirx * sin(-ROTSPD) + d->dir.y * cos(-ROTSPD);
		d->oldplanex = d->plane.x;
		d->plane.x = d->plane.x * cos(-ROTSPD) - d->plane.y * sin(-ROTSPD);
		d->plane.y = d->oldplanex * sin(-ROTSPD) + d->plane.y * cos(-ROTSPD);
	}
	if (keycode == KEY_LEFT)
	{
		d->oldirx = d->dir.x;
		d->dir.x = d->dir.x * cos(ROTSPD) - d->dir.y * sin(ROTSPD);
		d->dir.y = d->oldirx * sin(ROTSPD) + d->dir.y * cos(ROTSPD);
		d->oldplanex = d->plane.x;
		d->plane.x = d->plane.x * cos(ROTSPD) - d->plane.y * sin(ROTSPD);
		d->plane.y = d->oldplanex * sin(ROTSPD) + d->plane.y * cos(ROTSPD);
	}
	return (1);
}
