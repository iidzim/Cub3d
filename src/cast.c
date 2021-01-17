/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 16:33:24 by iidzim            #+#    #+#             */
/*   Updated: 2021/01/17 18:12:41 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**calculate ray position and direction
*/

int		calcul_pos_dir(t_data *d, int x)
{
	d->camera.x = 2 * x / (double)d->width - 1;
	d->raydir.x = d->dir.x + d->plane.x * d->camera.x;
	d->raydir.y = d->dir.y + d->plane.y * d->camera.x;
	d->mp_x = (int)d->pos.x;
	d->mp_y = (int)d->pos.y;
	d->deltadist.x = fabs(1 / d->raydir.x);
	d->deltadist.y = fabs(1 / d->raydir.y);
	return (1);
}

/*
**calculate step and initial sideDist
*/

int		calcul_step_sidedist(t_data *d)
{
	if (d->raydir.x < 0)
	{
		d->step.x = -1;
		d->sidedist.x = (d->pos.x - d->mp_x) * d->deltadist.x;
	}
	else
	{
		d->step.x = 1;
		d->sidedist.x = (d->mp_x + 1.0 - d->pos.x) * d->deltadist.x;
	}
	if (d->raydir.y < 0)
	{
		d->step.y = -1;
		d->sidedist.y = (d->pos.y - d->mp_y) * d->deltadist.y;
	}
	else
	{
		d->step.y = 1;
		d->sidedist.y = (d->mp_y + 1.0 - d->pos.y) * d->deltadist.y;
	}
	return (1);
}

/*
**jump to next map square, OR in x-direction, OR in y-direction
*/

int		perform_dda(t_data *d)
{
	while (d->hit == 0)
	{
		if (d->sidedist.x < d->sidedist.y)
		{
			d->sidedist.x += d->deltadist.x;
			d->mp_x += d->step.x;
			d->side = 0;
		}
		else
		{
			d->sidedist.y += d->deltadist.y;
			d->mp_y += d->step.y;
			d->side = 1;
		}
		if ((int)d->mp_x < d->nbr_line && (int)d->mp_y < d->nbr_column &&
			(int)d->mp_y >= 0 && (int)d->mp_x >= 0 &&
				d->map[d->mp_x][d->mp_y] == '1')
			d->hit = 1;
	}
	return (1);
}

/*
** Calculate distance projected on camera direction
** (Euclidean distance will give fisheye effect!)
** Calculate height of line to draw on screen
*/

int		calcul_deltadist(t_data *d)
{
	if ((int)d->raydir.y == 0)
		d->deltadist.x = 0;
	else
	{
		if ((int)d->raydir.x == 0)
			d->deltadist.x = 1;
		else
			d->deltadist.x = fabs(1 / d->raydir.x);
	}
	if ((int)d->raydir.x == 0)
		d->deltadist.y = 0;
	else
	{
		if ((int)d->raydir.y == 0)
			d->deltadist.y = 1;
		else
			d->deltadist.y = fabs(1 / d->raydir.y);
	}
	return (1);
}

/*
**Calculate distance projected on camera direction --fisheye effect
*/

int		project_line(t_data *d)
{
	if (d->side == 0)
		d->perpwalldis = (d->mp_x - d->pos.x + (1 - d->step.x) / 2)
			/ d->raydir.x;
	else
		d->perpwalldis = (d->mp_y - d->pos.y + (1 - d->step.y) / 2)
			/ d->raydir.y;
	d->lineheight = (int)(d->height / d->perpwalldis);
	if (d->perpwalldis == 0)
		d->lineheight = d->height;
	d->drawstart = d->height / 2 - d->lineheight / 2;
	d->drawend = d->height / 2 + d->lineheight / 2;
	if (d->drawend > d->height)
		d->drawend = d->height - 1;
	return (1);
}
