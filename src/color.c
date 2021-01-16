/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 16:33:40 by iidzim            #+#    #+#             */
/*   Updated: 2021/01/16 19:08:34 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_color(t_data *d, char *s, char l)
{
	char	**c;
	int		i;

	if (l == 'C' && (d->c.r != -1 || d->c.g != -1 || d->c.b != -1))
		ft_print_msg("duplicated argument -C", d);
	if (l == 'F' && (d->f.r != -1 || d->f.g != -1 || d->f.b != -1))
		ft_print_msg("duplicated argument -F", d);
	!ft_check_color_form(s) ? ft_print_msg("wrong arguments -color", d) : 0;
	c = ft_split(ft_switch_comma_to_space(d, s), ' ');
	i = ft_count_args(c);
	i != 4 ? ft_print_msg("wrong number of arguments -color", d) : 0;
	if (l == 'C')
		ft_get_color(d, &d->c, c, "C");
	else if (l == 'F')
		ft_get_color(d, &d->f, c, "F");
	ft_clear(c);
	free(s);
}

void	ft_get_color(t_data *d, t_color *t, char **c, char *l)
{
	int			i;
	long long	r;
	long long	g;
	long long	b;

	i = 0;
	while (c[i])
	{
		if (!ft_strncmp(c[0], l, 1))
		{
			i += 1;
			i == 1 ? r = ft_atoi(d, c[i++]) : 0;
			i == 2 ? g = ft_atoi(d, c[i++]) : 0;
			i == 3 ? b = ft_atoi(d, c[i++]) : 0;
			if (r > 255 || g > 255 || b > 255 || r < 0 || g < 0 || b < 0)
				ft_print_msg("value >= 0 && value <= 255", d);
			t->r = (int)r;
			t->g = (int)g;
			t->b = (int)b;
			d->element_cpt += 1;
		}
	}
}

int		ft_check_color_form(char *c)
{
	char	**str;
	int		i;

	i = 0;
	str = ft_split(c, ' ');
	while (str[i])
		i++;
	ft_clear(str);
	if (i != 2)
		return (0);
	return (1);
}

char	*ft_switch_comma_to_space(t_data *d, char *s)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ',')
		{
			s[i] = 32;
			n++;
		}
		i++;
	}
	n != 2 ? ft_print_msg("wrong arguments -color", d) : 0;
	return (s);
}
