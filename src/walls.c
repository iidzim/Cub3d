/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 16:32:56 by iidzim            #+#    #+#             */
/*   Updated: 2021/01/16 17:54:41 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**wallX represents the exact value where the wall was hit
**tex_x coordinate on the texture
**How much to increase the texture coordinate per screen pixel
**Starting texture coordinate
*/

void	ft_texture(t_data *d)
{
	double wallx;

	if (d->side == 0)
		wallx = d->pos.y + d->perpwalldis * d->raydir.y;
	else
		wallx = d->pos.x + d->perpwalldis * d->raydir.x;
	wallx -= floor(wallx);
	d->txt.tex_x = (int)(wallx * d->txt.w);
	if ((d->side == 0 && d->raydir.x > 0) || (d->side == 1 && d->raydir.y < 0))
		d->txt.tex_x = d->txt.w - d->txt.tex_x - 1;
	d->txt.step = 1.0 * d->txt.h / d->lineheight;
	d->txt.pos = (d->drawstart - d->height / 2 + d->lineheight / 2)
		* d->txt.step;
}

void	ft_color(t_data *d)
{
	if (d->side == 1 && (d->mp_y < d->pos.y))
		d->txt.color = (int*)d->txt.texture[0];
	else if (d->side == 1 && (d->mp_y > d->pos.y))
		d->txt.color = (int*)d->txt.texture[1];
	else if (d->side == 0 && (d->mp_x < d->pos.x))
		d->txt.color = (int*)d->txt.texture[2];
	else
		d->txt.color = (int*)d->txt.texture[3];
	d->s.color = (int*)d->txt.texture[4];
}

void	cast(t_data *d)
{
	int x;

	x = 0;
	d->buff = malloc(sizeof(double) * d->width);
	while (x < d->width)
	{
		d->hit = 0;
		calcul_pos_dir(d, x);
		calcul_step_sidedist(d);
		perform_dda(d);
		project_line(d);
		calcul_deltadist(d);
		ft_texture(d);
		ft_color(d);
		verline(d, x);
		d->buff[x] = (double)d->perpwalldis;
		x++;
	}
	sprite(d);
	free(d->buff);
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img_ptr, 0, 0);
}

int		rgb_to_int(t_color c)
{
	return (c.r << 16 | c.g << 8 | c.b);
}
