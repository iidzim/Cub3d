/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 16:57:14 by iidzim            #+#    #+#             */
/*   Updated: 2021/01/18 19:27:54 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int		main(int argc, char **argv)
{
	t_data	*d;
	int		fd;

	d = malloc(sizeof(t_data));
	ft_init(d);
	fd = ft_args(argc, argv, d);
	d->win_ptr = mlx_new_window(d->mlx_ptr, d->width, d->height, "cub3D");
	!d->win_ptr ? ft_exit(d, 1) : 0;
	d->img_ptr = mlx_new_image(d->mlx_ptr, d->width, d->height);
	!d->img_ptr ? ft_exit(d, 1) : 0;
	d->data_addr = (int*)mlx_get_data_addr(d->img_ptr, &d->bpp, &d->size_line,
		&d->endian);
	!d->data_addr ? ft_exit(d, 1) : 0;
	cast(d);
	argc == 3 ? ft_bmp(d) : 0;
	mlx_hook(d->win_ptr, 2, 1L << 0, ft_key, d);
	mlx_hook(d->win_ptr, KEY_X, 0, fttexit, d);
	mlx_loop(d->mlx_ptr);
	ft_exit(d, 2);
	close(fd);
	return (0);
}
