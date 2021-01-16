/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 16:33:20 by iidzim            #+#    #+#             */
/*   Updated: 2021/01/16 19:09:06 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_print_msg(char *msg, t_data *d)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	ft_exit(d, 1);
}

void	ft_clear(char **str)
{
	int i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_clear_double(double **str)
{
	int i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int		ft_exit(t_data *d, int i)
{
	d->img_ptr ? mlx_destroy_image(d->mlx_ptr, d->img_ptr) : 0;
	d->win_ptr ? mlx_destroy_window(d->mlx_ptr, d->win_ptr) : 0;
	if (i == 0 || i == 1)
		exit(i);
	return (1);
}

int		fttexit(t_data *d)
{
	mlx_destroy_image(d->mlx_ptr, d->img_ptr);
	mlx_destroy_window(d->mlx_ptr, d->win_ptr);
	exit(0);
}
