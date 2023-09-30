/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:39:41 by esali             #+#    #+#             */
/*   Updated: 2023/09/30 15:00:38 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//while loop into extra function
char	*get_next_line(int fd)
{
	static char	save_file[BUFFER_SIZE + 1];
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (0);
	ret = (char *)malloc(sizeof(char));
	if (!ret)
		return (NULL);
	ret[0] = '\0';
	ret = gnl(ret, save_file, fd);
	if (ret[0] == '\0')
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}
