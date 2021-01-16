/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 16:33:15 by iidzim            #+#    #+#             */
/*   Updated: 2021/01/11 19:18:19 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_ntxt(t_data *d, char *s)
{
	int i;

	if (d->mlx_img_txt[0])
		ft_print_msg("duplicated argument NO", d);
	i = 0;
	while (s[i] == 32 && s[i] != '\0')
		i++;
	if (s[i] == 'N' && s[i + 1] == 'O')
		i += 2;
	s = remove_space(s + i);
	d->mlx_img_txt[0] = mlx_xpm_file_to_image(d->mlx_ptr, s, &d->txt.w,
			&d->txt.h);
	if (!d->mlx_img_txt[0])
		ft_print_msg("invalid path NO", d);
	d->element_cpt += 1;
	free(s);
}

void	ft_check_stxt(t_data *d, char *s)
{
	int i;

	if (d->mlx_img_txt[1])
		ft_print_msg("duplicated argument SO", d);
	i = 0;
	while (s[i] == 32 && s[i] != '\0')
		i++;
	if (s[i] == 'S' && s[i + 1] == 'O')
		i += 2;
	s = remove_space(s + i);
	d->mlx_img_txt[1] = mlx_xpm_file_to_image(d->mlx_ptr, s, &d->txt.w,
			&d->txt.h);
	if (!d->mlx_img_txt[1])
		ft_print_msg("invalid path SO", d);
	d->element_cpt += 1;
	free(s);
}

void	ft_check_wtxt(t_data *d, char *s)
{
	int i;

	if (d->mlx_img_txt[2])
		ft_print_msg("duplicated argument WE", d);
	i = 0;
	while (s[i] == 32 && s[i] != '\0')
		i++;
	if (s[i] == 'W' && s[i + 1] == 'E')
		i += 2;
	s = remove_space(s + i);
	d->mlx_img_txt[2] = mlx_xpm_file_to_image(d->mlx_ptr, s, &d->txt.w,
			&d->txt.h);
	if (!d->mlx_img_txt[2])
		ft_print_msg("invalid path WE", d);
	d->element_cpt += 1;
	free(s);
}

void	ft_check_etxt(t_data *d, char *s)
{
	int i;

	if (d->mlx_img_txt[3])
		ft_print_msg("duplicated argument EA", d);
	i = 0;
	while (s[i] == 32 && s[i] != '\0')
		i++;
	if (s[i] == 'E' && s[i + 1] == 'A')
		i += 2;
	s = remove_space(s + i);
	d->mlx_img_txt[3] = mlx_xpm_file_to_image(d->mlx_ptr, s, &d->txt.w,
			&d->txt.h);
	if (!d->mlx_img_txt[3])
		ft_print_msg("invalid path EA", d);
	d->element_cpt += 1;
	free(s);
}

void	ft_check_sprite_txt(t_data *d, char *s)
{
	int i;

	if (d->mlx_img_txt[4])
		ft_print_msg("duplicated argument S", d);
	i = 0;
	while (s[i] == 32 && s[i] != '\0')
		i++;
	if (s[i] == 'S' && s[i + 1] == ' ')
		i += 2;
	s = remove_space(s + i);
	d->mlx_img_txt[4] = mlx_xpm_file_to_image(d->mlx_ptr, s, &d->s.w,
			&d->s.h);
	if (!d->mlx_img_txt[4])
		ft_print_msg("invalid path S", d);
	d->element_cpt += 1;
	free(s);
}
