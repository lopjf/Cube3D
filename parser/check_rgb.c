/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:19:00 by loris             #+#    #+#             */
/*   Updated: 2023/12/15 19:19:01 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	check_numbers(char *str, int i)
{
	int	ret;
	int	j;
	int	nb;

	ret = 0;
	j = i;
	while (str[j] >= '0' && str[j] <= '9')
	{
		j++;
		ret++;
	}
	nb = ft_atoi(str + i);
	if (nb >= 0 && nb <= 255)
		return (ret);
	else
		free_and_exit("Error: Invalid RGB format.");
	return (ret);
}

static void	check_format(char *str)
{
	int	i;

	i = 0;
	i = check_numbers(str, i);
	if (str[i] == ',')
		i++;
	else
		free_and_exit("Error: Invalid RGB format.");
	i += check_numbers(str, i);
	if (str[i] == ',')
		i++;
	else
		free_and_exit("Error: Invalid RGB format.");
	i += check_numbers(str, i);
	if (str[i] == '\0')
		return ;
	else
		free_and_exit("Error: Invalid RGB format.");
}

void	check_rgb(void)
{
	check_format(getb()->data.f_path);
	check_format(getb()->data.c_path);
}
