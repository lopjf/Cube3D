/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:58:05 by esali             #+#    #+#             */
/*   Updated: 2023/09/30 15:00:29 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gnl(char *ret, char *save_file, int fd)
{
	char	*tmp;
	char	last_char;
	int		i;

	last_char = '\0';
	i = 0;
	while (last_char != '\n')
	{
		if (ft_strlen(save_file) == 0)
		{
			i = read(fd, save_file, BUFFER_SIZE);
			save_file[i] = '\0';
			if (i == -1)
				return (NULL);
			if (i == 0)
				break ;
		}
		tmp = ret;
		ret = concat(ret, save_file);
		free(tmp);
		remove_first_line(save_file);
		last_char = ret[ft_strlen(ret) - 1];
	}
	return (ret);
}

char	*concat(char *s1, char *s2)
{
	char	*ret;
	int		i;
	int		j;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ret)
		return (NULL);
	i = cpy_ret(ret, s1);
	j = 0;
	while (s2[j] != 0)
	{
		ret[i] = s2[j];
		if (ret[i] == '\n')
		{
			ret[i + 1] = '\0';
			return (ret);
		}
		j++;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

int	cpy_ret(char *ret, char *s1)
{
	int	i;

	i = 0;
	while (s1[i] != 0)
	{
		ret[i] = s1[i];
		i++;
	}
	return (i);
}

void	remove_first_line(char *str)
{
	int	i;

	while (str[0] != '\n' && str[0] != 0)
	{
		i = 0;
		while (str[i] != 0)
		{
			str[i] = str[i + 1];
			i++;
		}
		str[i] = 0;
	}
	i = 0;
	if (str[0] == '\n')
	{
		while (str[i] != '\0')
		{
			str[i] = str[i + 1];
			i++;
		}
	}
	str[i] = 0;
}
