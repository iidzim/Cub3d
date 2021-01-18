/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 16:33:36 by iidzim            #+#    #+#             */
/*   Updated: 2021/01/18 14:39:46 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_get_data(t_data *d)
{
	int i;
	int j;

	i = 0;
	while (d->data[i] && d->element_cpt < 8)
	{
		j = 0;
		if (!ft_strncmp(d->data[i], "R ", 2))
			ft_check_resolution(d, d->data[i++]);
		else if (!ft_strncmp(d->data[i], "C ", 2))
			ft_check_color(d, d->data[i++], 'C');
		else if (!ft_strncmp(d->data[i], "F ", 2))
			ft_check_color(d, d->data[i++], 'F');
		else if (d->data[i][j] == '\0')
			i++;
		else
		{
			ft_get_data2(d, i, 0);
			i++;
		}
	}
	ft_get_data2(d, i, 1);
	return (1);
}

int		ft_get_data2(t_data *d, int i, int off)
{
	if (off == 0)
	{
		if (!ft_strncmp(d->data[i], "NO ", 3))
			ft_check_ntxt(d, d->data[i++]);
		else if (!ft_strncmp(d->data[i], "SO ", 3))
			ft_check_stxt(d, d->data[i++]);
		else if (!ft_strncmp(d->data[i], "WE ", 3))
			ft_check_wtxt(d, d->data[i++]);
		else if (!ft_strncmp(d->data[i], "EA ", 3))
			ft_check_etxt(d, d->data[i++]);
		else if (!ft_strncmp(d->data[i], "S ", 2))
			ft_check_sprite_txt(d, d->data[i++]);
		else
			ft_print_msg("wrong identifier", d);
	}
	else if (off == 1)
	{
		d->data[i] ? ft_print_msg("more than 8 identifiers", d) : 0;
		d->element_cpt != 8 ? ft_print_msg("missing information", d) : 0;
	}
	return (1);
}

void	ft_check_resolution(t_data *d, char *s)
{
	int			i;
	int			j;
	char		**r;
	long long	w;
	long long	h;

	if (d->height != -1 && d->width != -1)
		ft_print_msg("Duplicated argument", d);
	r = ft_split(s, ' ');
	j = ft_count_args(r);
	if (j != 3)
		ft_print_msg("wrong number of arguments -R", d);
	i = 1;
	while (i < j)
	{
		i == 1 ? w = ft_atoi(d, r[i++]) : 0;
		i == 2 ? h = ft_atoi(d, r[i++]) : 0;
	}
	d->width = ((w > MAX_INT) || (w > MAX_WIDTH)) ? MAX_WIDTH : (int)w;
	d->height = ((h > MAX_INT) || (h > MAX_HEIGHT)) ? MAX_HEIGHT : (int)h;
	(d->width < 0 || d->height < 0) ? ft_print_msg("wrong value -R", d) : 0;
	d->limit = d->height * d->width;
	d->element_cpt += 1;
	ft_clear(r);
	free(s);
}

int		ft_txt(t_data *d)
{
	if (!d->mlx_img_txt[0] || !d->mlx_img_txt[1] || !d->mlx_img_txt[2]
		|| !d->mlx_img_txt[3] || !d->mlx_img_txt[4])
	{
		ft_print_msg("missing path", d);
		ft_exit(d, 1);
	}
	if ((d->txt.texture[0] = mlx_get_data_addr(d->mlx_img_txt[0], &d->bpp,
			&d->size_line, &d->endian)) == NULL)
		ft_exit(d, 1);
	if ((d->txt.texture[1] = mlx_get_data_addr(d->mlx_img_txt[1], &d->bpp,
			&d->size_line, &d->endian)) == NULL)
		ft_exit(d, 1);
	if ((d->txt.texture[2] = mlx_get_data_addr(d->mlx_img_txt[2], &d->bpp,
			&d->size_line, &d->endian)) == NULL)
		ft_exit(d, 1);
	if ((d->txt.texture[3] = mlx_get_data_addr(d->mlx_img_txt[3], &d->bpp,
			&d->size_line, &d->endian)) == NULL)
		ft_exit(d, 1);
	if ((d->txt.texture[4] = mlx_get_data_addr(d->mlx_img_txt[4], &d->bpp,
			&d->size_line, &d->endian)) == NULL)
		ft_exit(d, 1);
	return (0);
}

void	ft_check_map(t_data *d)
{
	int i;

	ft_empty_line(d);
	ft_check_intrus(d);
	ft_check_colmn(d);
	ft_check_line(d);
	ft_check_space(d);
	ft_init_player(d);
	ft_txt(d);
	if (!(d->s.sprite = malloc(sizeof(double*) * (d->s.nbr + 1))))
		ft_exit(d, 1);
	i = -1;
	while (d->s.nbr > ++i)
	{
		if (!(d->s.sprite[i] = malloc(sizeof(double) * 3)))
			ft_exit(d, 1);
	}
	ft_sprite(d);
}
