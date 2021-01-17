/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 16:32:56 by iidzim            #+#    #+#             */
/*   Updated: 2021/01/17 18:36:00 by iidzim           ###   ########.fr       */
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
		d->txt.color = (int*)d->txt.texture[1];
	else if (d->side == 1 && (d->mp_y > d->pos.y))
		d->txt.color = (int*)d->txt.texture[0];
	else if (d->side == 0 && (d->mp_x < d->pos.x))
		d->txt.color = (int*)d->txt.texture[3];
	else
		d->txt.color = (int*)d->txt.texture[2];
	d->s.color = (int*)d->txt.texture[4];
}

/*
**draw the pixels of the stripe as a vertical line
*/

int		verline(t_data *d, int x)
{
	int i;

	i = -1;
	while (++i < d->drawstart)
	{
		if ((x + d->width * i) > -1 && (x + d->width * i) < d->limit)
			d->data_addr[x + d->width * i] = rgb_to_int(d->c);
	}
	i = d->drawstart;
	while (d->drawend - 1 > i && d->height > i)
	{
		d->txt.tex_y = (int)d->txt.pos & (d->txt.h - 1);
		d->txt.pos += d->txt.step;
		if ((x + d->width * i) > -1 && (x + d->width * i) < d->limit)
			d->data_addr[x + d->width * i] = d->txt.color[d->txt.tex_x +
				d->txt.h * d->txt.tex_y];
		i++;
	}
	i = d->drawend - 1;
	while (++i < d->height)
	{
		if ((x + d->width * i) > -1 && (x + d->width * i) < d->limit)
			d->data_addr[x + d->width * i] = rgb_to_int(d->f);
	}
	return (1);
}

int		rgb_to_int(t_color c)
{
	return (c.r << 16 | c.g << 8 | c.b);
}
