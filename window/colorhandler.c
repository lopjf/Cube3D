/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorhandler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:18:31 by loris             #+#    #+#             */
/*   Updated: 2023/12/15 19:20:10 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	get_color_tex(char wall_side, int x, int y)
{
	unsigned int	*img_data;
	unsigned int	color;
	int				bpp;
	int				size_line;
	int				endian;
	int				r;
	int				g;
	int				b;

	if (wall_side == 'W')
		img_data = (unsigned int *)mlx_get_data_addr(getb()->libx.we, &bpp, &size_line, &endian);
	else if (wall_side == 'E')
		img_data = (unsigned int *)mlx_get_data_addr(getb()->libx.ea, &bpp, &size_line, &endian);
	else if (wall_side == 'S')
		img_data = (unsigned int *)mlx_get_data_addr(getb()->libx.so, &bpp, &size_line, &endian);
	else if (wall_side == 'N')
		img_data = (unsigned int *)mlx_get_data_addr(getb()->libx.no, &bpp, &size_line, &endian);
	else
		return (0 << 24 | 255 << 16 | 255 << 8 | 255);
	color = img_data[y * size_line / 4 + x];
	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	return (0 << 24 | r << 16 | g << 8 | b);
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
