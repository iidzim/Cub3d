/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 19:18:02 by iidzim            #+#    #+#             */
/*   Updated: 2021/01/11 18:54:21 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*ft_memset(void *str, int x, size_t l)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char*)str;
	while (0 < l--)
		ptr[i++] = x;
	return (ptr);
}

void	ft_header(t_data *d, char *header, int height)
{
	header[0] = 'B';
	header[1] = 'M';
	header[2] = d->file_size;
	header[3] = (d->file_size >> 8);
	header[4] = (d->file_size >> 16);
	header[5] = (d->file_size >> 24);
	header[10] = 54;
	header[14] = 40;
	header[18] = d->width;
	header[19] = (d->width >> 8);
	header[20] = (d->width >> 16);
	header[21] = (d->width >> 24);
	header[22] = height;
	header[23] = (height >> 8);
	header[24] = (height >> 16);
	header[25] = (height >> 24);
	header[26] = 1;
	header[28] = 32;
}

void	ft_bmp(t_data *d)
{
	int		fd;
	char	header[54];
	int		height;

	if ((fd = open("save.bmp", O_CREAT | O_RDWR, S_IRWXU)) < 0)
		ft_exit(d, 2);
	ft_memset(header, 0, 54);
	d->file_size = 40 + 14 * d->width * d->height * 4;
	height = -d->height;
	ft_header(d, header, height);
	write(fd, header, 54);
	write(fd, (char*)d->data_addr, (d->width * d->height * 4));
	close(fd);
	ft_exit(d, 0);
}
