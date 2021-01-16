/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 17:43:17 by iidzim            #+#    #+#             */
/*   Updated: 2021/01/16 17:38:52 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_args(int argc, char **argv, t_data *d)
{
	int fd;

	fd = 0;
	if (argc == 1)
		ft_print_msg("add two arguments (filename & flag)", d);
	else if (argc == 2 || argc == 3)
	{
		if (argc == 3 && ft_strncmp(argv[2], "--save", 6))
			ft_print_msg("wrong flag", d);
		if (!ft_rtsrts(argv[1], ".cub"))
			ft_print_msg("the filename must end with .cub", d);
		if ((fd = open(argv[1], O_RDONLY)) < 0)
			ft_print_msg("Error while opening the file", d);
		ft_read_file(d, fd);
	}
	resize_map(d);
	// print_new_map(d);
	ft_get_data(d);
	ft_check_map(d);
	return (fd);
}

void	ft_read_file(t_data *d, int fd)
{
	char	*line;
	int		start_map;
	char	*temp;

	start_map = 0;
	line = "";
	d->info = ft_strdup("");
	d->m = ft_strdup("");
	if (line[0] == '\0')
		get_next_line(fd, &line);
	temp = d->info;
	d->info = ft_strjoin(d->info, line);
	free(temp);
	temp = d->info;
	d->info = ft_strjoin(d->info, "\n");
	free(temp);
	free(line);
	while (get_next_line(fd, &line))
		ft_read_file2(d, line, &start_map);
	ft_read_file3(d, line);
	d->data = ft_split(d->info, '\n');
	d->old_map = ft_split(d->m, '\n');
}

void	ft_read_file2(t_data *d, char *line, int *start_map)
{
	char *tmp;

	if (ft_start_map(line, start_map, d))
	{
		tmp = d->m;
		d->m = ft_strjoin(d->m, line);
		free(tmp);
		tmp = d->m;
		d->m = ft_strjoin(d->m, "\n");
		free(tmp);
		*start_map = 1;
	}
	else if (*start_map == 0)
	{
		tmp = d->info;
		d->info = ft_strjoin(d->info, line);
		free(tmp);
		tmp = d->info;
		d->info = ft_strjoin(d->info, "\n");
		free(tmp);
	}
	free(line);
}

void	ft_read_file3(t_data *d, char *line)
{
	char *temp;

	if (ft_isdigit(line[0]) || ft_isspace(line[0]))
	{
		temp = d->m;
		d->m = ft_strjoin(d->m, line);
		free(temp);
		temp = d->m;
		d->m = ft_strjoin(d->m, "\0");
		free(temp);
	}
	else if (!line)
		ft_print_msg("invalid map", d);
	else
	{
		temp = d->info;
		d->info = ft_strjoin(d->info, line);
		free(temp);
		temp = d->info;
		d->info = ft_strjoin(d->info, "\0");
		free(temp);
	}
	free(line);
	!ft_strlen(d->m) ? ft_print_msg("add map", d) : 0;
}
