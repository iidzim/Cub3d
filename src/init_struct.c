/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 17:21:27 by iidzim            #+#    #+#             */
/*   Updated: 2021/01/15 19:15:38 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init(t_data *d)
{
	d->mlx_ptr = mlx_init();
	d->win_ptr = NULL;
	d->img_ptr = NULL;
	d->mlx_img_txt[0] = NULL;
	d->mlx_img_txt[1] = NULL;
	d->mlx_img_txt[2] = NULL;
	d->mlx_img_txt[3] = NULL;
	d->mlx_img_txt[4] = NULL;
	d->img_win = 0;
	d->data_addr = 0;
	d->count = 0;
	d->endian = 0;
	d->bpp = 0;
	d->size_line = 0;
	d->width = -1;
	d->height = -1;
	d->info = NULL;
	d->m = NULL;
	d->data = NULL;
	d->old_map = NULL;
	d->map = NULL;
	d->w = 0;
	ft_init_txt_ply(&d->txt, &d->ply);
	ft_init2(d);
}

void	ft_init2(t_data *d)
{
	d->c.r = -1;
	d->c.g = -1;
	d->c.b = -1;
	d->f.r = -1;
	d->f.g = -1;
	d->f.b = -1;
	ft_init3(d);
	ft_init_pt(&d->pos);
	ft_init_pt(&d->dir);
	ft_init_pt(&d->raydir);
	ft_init_pt(&d->plane);
	ft_init_pt(&d->camera);
	ft_init_pt(&d->sidedist);
	ft_init_pt(&d->deltadist);
	ft_init_pt(&d->step);
	d->s.drawstart_x = 0;
	d->s.drawstart_y = 0;
	d->s.drawend_x = 0;
	d->s.drawend_y = 0;
	d->s.stripe = 0;
	d->s.tex_x = 0;
	d->s.tex_y = 0;
	d->s.color = 0;
}

void	ft_init3(t_data *d)
{
	d->file_size = 0;
	d->limit = 0;
	d->element_cpt = 0;
	d->nbr_line = 0;
	d->nbr_column = 0;
	d->mp_x = 0;
	d->mp_y = 0;
	d->oldirx = 0;
	d->oldplanex = 0;
	d->hit = 0;
	d->side = 0;
	d->drawstart = 0;
	d->drawend = 0;
	d->lineheight = 0;
	d->perpwalldis = 0;
	ft_init_pt(&d->s.spr);
	ft_init_pt(&d->s.transform);
	d->s.nbr = 0;
	d->buff = 0;
	d->s.nbr = 0;
	d->s.w = 0;
	d->s.h = 0;
	d->s.sprite = NULL;
	d->s.inverse_deter = 0;
	d->s.screen_x = 0;
}

void	ft_init_txt_ply(t_txt *txt, t_player *ply)
{
	txt->texture[0] = NULL;
	txt->texture[1] = NULL;
	txt->texture[2] = NULL;
	txt->texture[3] = NULL;
	txt->texture[4] = NULL;
	txt->color = 0;
	txt->step = 0;
	txt->pos = 0;
	txt->tex_x = 0;
	txt->tex_y = 0;
	txt->w = 0;
	txt->h = 0;
	ply->nbr = 0;
	ply->pos = 0;
}

void	ft_init_pt(t_point *p)
{
	p->x = 0;
	p->y = 0;
}
