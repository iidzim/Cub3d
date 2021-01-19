/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 19:00:40 by iidzim            #+#    #+#             */
/*   Updated: 2021/01/19 09:16:46 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**translate sprite position to relative to camera
**required for correct matrix multiplication
**transform sprite with the inverse camera matrix
**this is actually the depth inside the screen, that what Z is in 3D
*/

void	ft_sprite_position(t_data *d, int i)
{
	d->s.spr.x = d->s.sprite[i][0] - d->pos.x;
	d->s.spr.y = d->s.sprite[i][1] - d->pos.y;
	d->s.inverse_deter = 1.0 / (d->plane.x * d->dir.y -
		d->plane.y * d->dir.x);
	d->s.transform.x = d->s.inverse_deter * (d->s.spr.x * d->dir.y -
		d->s.spr.y * d->dir.x);
	d->s.transform.y = d->s.inverse_deter * (-d->plane.y * d->s.spr.x +
		d->s.spr.y * d->plane.x);
	d->s.screen_x = (int)((d->width / 2) * (1 + d->s.transform.x /
		d->s.transform.y));
}

/*
**calculate height of the sprite on screen
**using 'transformY' instead of the real distance prevents fisheye
*/

void	ft_draw_start_end(t_data *d)
{
	d->s.h = abs((int)(d->height / d->s.transform.y));
	d->s.drawstart_y = d->height / 2 - d->s.h / 2;
	if (d->s.drawstart_y < 0)
		d->s.drawstart_y = 0;
	d->s.drawend_y = d->height / 2 + d->s.h / 2;
	if (d->s.drawend_y >= d->height)
		d->s.drawend_y = d->height;
	d->s.w = abs((int)(d->height / d->s.transform.y));
	d->s.drawstart_x = d->s.screen_x - d->s.w / 2;
	if (d->s.drawstart_x < 0)
		d->s.drawstart_x = 0;
	d->s.drawend_x = d->s.screen_x + d->s.w / 2;
	if (d->s.drawend_x >= d->width)
		d->s.drawend_x = d->width - 1;
}

/*
** the conditions in the if are:
** 1) it's in front of camera plane so you don't see things behind you
** 2) it's on the screen (left)
** 3) it's on the screen (right)
** 4) ZBuffer, with perpendicular distance
*/

void	ft_draw_sprite(t_data *d, int i)
{
	int x;
	int color;

	if (d->s.transform.y > 0 && d->s.stripe >= 0 &&
		d->s.stripe < d->width && d->s.tex_x < 64 &&
		d->s.transform.y < d->buff[d->s.stripe])
	{
		x = 0;
		i = d->s.drawstart_y - 1;
		while (d->s.drawend_y > ++i)
		{
			x = i * 256 - d->height * 128 + d->s.h * 128;
			d->s.tex_y = ((x * 64) / d->s.h) / 256;
			color = d->s.color[64 * d->s.tex_y + d->s.tex_x];
			if ((color & 0x00FFFFFF) != 0)
				d->data_addr[i * d->width + d->s.stripe] = color;
		}
	}
}

/*
** transform sprite with the inverse camera matrix
**  [ planeX   dirX ] -1                                    [ dirY      -dirX ]
**  [               ]    =  1/(planeX*dirY-dirX*planeY) *   [                 ]
**  [ planeY   dirY ]                                       [ -planeY  planeX ]
*/

void	sprite(t_data *d)
{
	int i;

	i = -1;
	while (d->s.nbr > ++i)
	{
		d->s.sprite[i][2] = ((d->pos.x - d->s.sprite[i][0]) * (d->pos.x -
			d->s.sprite[i][0]) + (d->pos.y - d->s.sprite[i][1]) * (d->pos.y -
				d->s.sprite[i][1]));
	}
	sort_sprite(d);
	i = -1;
	while (d->s.nbr > ++i)
	{
		ft_sprite_position(d, i);
		ft_draw_start_end(d);
		d->s.stripe = d->s.drawstart_x;
		while (d->s.drawend_x > d->s.stripe)
		{
			d->s.tex_x = (int)(256 * (d->s.stripe - (d->s.screen_x -
				d->s.w / 2)) * 64 / d->s.w) / 256;
			ft_draw_sprite(d, i);
			d->s.stripe++;
		}
	}
}
