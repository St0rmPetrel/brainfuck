/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_in_big_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 13:33:40 by serma             #+#    #+#             */
/*   Updated: 2020/09/02 14:26:58 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF_SIZE 1024

char	*ft_realloc_str(char *str)
{
	char	*ret;

	ret = malloc(sizeof(*str) * (2 * strlen(str) + 1));
	strcpy(ret, str);
	free(str);
	return (ret);
}

char	*read_in_big_string(int fd)
{
	int		ret;
	char	*big_str;
	char	buf[BUF_SIZE + 1];

	big_str = malloc(sizeof(*big_str) * (BUF_SIZE + 1));
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		strcat(big_str, buf);
		if (ret == BUF_SIZE)
			big_str = ft_realloc_str(big_str);
	}
	return (big_str);
}
