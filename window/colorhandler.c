/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorhandler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:18:31 by loris             #+#    #+#             */
/*   Updated: 2023/12/15 19:37:30 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

// utils is bpp, size_line and endian as per mlx_get_data_addr documentation
int	get_color_tex(char wall_side, int x, int y)
{
	unsigned int	*img_data;
	unsigned int	color;
	int				utils[3];
	int				rgb[3];

	if (wall_side == 'W')
		img_data = (unsigned int *)mlx_get_data_addr(getb()->libx.we, \
	&utils[0], &utils[1], &utils[2]);
	else if (wall_side == 'E')
		img_data = (unsigned int *)mlx_get_data_addr(getb()->libx.ea, \
	&utils[0], &utils[1], &utils[2]);
	else if (wall_side == 'S')
		img_data = (unsigned int *)mlx_get_data_addr(getb()->libx.so, \
	&utils[0], &utils[1], &utils[2]);
	else if (wall_side == 'N')
		img_data = (unsigned int *)mlx_get_data_addr(getb()->libx.no, \
	&utils[0], &utils[1], &utils[2]);
	else
		return (0 << 24 | 255 << 16 | 255 << 8 | 255);
	color = img_data[y * utils[1] / 4 + x];
	rgb[0] = (color >> 16) & 0xFF;
	rgb[1] = (color >> 8) & 0xFF;
	rgb[2] = color & 0xFF;
	return (0 << 24 | rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

int	get_rgb(char *rgb)
{
	int	r;
	int	g;
	int	b;
	int	i;

	i = 0;
	r = ft_atoi(rgb + i);
	while (rgb[i] != ',' && rgb[i] != '\0')
		i++;
	i++;
	g = ft_atoi(rgb + i);
	while (rgb[i] != ',' && rgb[i] != '\0')
		i++;
	i++;
	b = ft_atoi(rgb + i);
	return (0 << 24 | r << 16 | g << 8 | b);
}
