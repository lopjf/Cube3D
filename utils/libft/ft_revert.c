/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:06:08 by loris             #+#    #+#             */
/*   Updated: 2022/10/14 11:07:27 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_revert(char *s)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = strlen(s);
	ret = (char *)malloc(sizeof(char) * j + 1);
	if (!ret)
		return (NULL);
	while (i < j)
	{
		ret[i] = s[j - i - 1];
		i++;
	}
	ret[j] = '\0';
	return (ret);
}
