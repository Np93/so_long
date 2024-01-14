/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhirzel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:17:41 by nhirzel           #+#    #+#             */
/*   Updated: 2021/11/30 12:28:08 by nhirzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_read(char **str, int fd, char *buf)
{
	int		red;
	char	*temp;

	while (!ft_strchr(*str, '\n'))
	{
		red = read(fd, buf, BUFFER_SIZE);
		if (red <= 0)
			break ;
		buf[red] = 0;
		temp = *str;
		*str = ft_strjoin(*str, buf);
		free(temp);
	}
	free(buf);
}

char	*ft_gnl(char **str)
{
	char	*riturn;
	char	*stock;
	int		istr;

	if (!ft_strchr(*str, '\n'))
	{
		riturn = ft_substr(*str, 0, ft_strlen(*str));
		free(*str);
		*str = NULL;
		if (riturn[0] != '\0')
			return (riturn);
		free(riturn);
		return (NULL);
	}
	istr = ft_strlen(*str);
	riturn = ft_substr(*str, 0, istr - ft_strlen(ft_strchr(*str, '\n')) + 1);
	stock = *str;
	*str = ft_substr(ft_strchr(*str, '\n'), 1, istr);
	if (*str[0] == 0)
	{
		free(*str);
		*str = NULL;
	}
	free(stock);
	return (riturn);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buf;
	char		*retour;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buf)
		return (NULL);
	if (str == NULL)
		str = ft_substr("", 0, 1);
	ft_read(&str, fd, buf);
	if (!str)
		return (NULL);
	retour = ft_gnl(&str);
	return (retour);
}
