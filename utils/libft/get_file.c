/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:08:51 by lpenelon          #+#    #+#             */
/*   Updated: 2022/10/31 00:00:00 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_file(int fd, char *buff, char *store)
{
	int		i;
	char	*tmp;

	i = 1;
	while (i != 0)
	{
		i = read(fd, buff, 1);
		if (i == -1)
		{
			free(buff);
			free(store);
			return (NULL);
		}
		buff[i] = '\0';
		tmp = ft_strdup(store);
		free(store);
		store = ft_strjoin(tmp, buff);
		free(tmp);
	}
	free (buff);
	return (store);
}

char	*get_file(int fd)
{
	static char	*store;
	char		*buff;
	char		*ret;

	if (fd < 0 || 1 <= 0 || read(fd, NULL, 0) < 0)
		return (0);
	buff = malloc(sizeof(char) * (1 + 1));
	if (!buff)
		return (NULL);
	if (!store)
	{
		store = malloc(sizeof(char));
		if (!store)
			return (NULL);
		store[0] = '\0';
	}
	store = read_file(fd, buff, store);
	ret = ft_strdup(store);
	return (ret);
}
