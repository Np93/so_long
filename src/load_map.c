/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhirzel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:09:52 by nhirzel           #+#    #+#             */
/*   Updated: 2021/12/09 18:12:12 by nhirzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strnstr(const char *dos, const char *ber, size_t len)
{
	size_t	i;
	size_t	ii;

	i = 0;
	if (*ber == '\0')
		return ((char *) dos);
	while (i < len && dos[i] != '\0')
	{
		ii = 0;
		while (dos[i + ii] == ber[ii] && (i + ii) < len
			&& dos[i + ii] && ber[ii])
			ii++;
		if (ber[ii] == '\0')
			return ((char *) dos + i);
		i++;
	}
	return (NULL);
}

int	compt_ligne(char *dos)
{
	int		fd;
	int		ligne;
	int		comptread;
	char	a;

	fd = open(dos, O_RDONLY);
	if (!fd)
		return (-1);
	ligne = 0;
	comptread = 1;
	while (comptread > 0)
	{
		comptread = read(fd, &a, 1);
		if (comptread == 0)
			break ;
		if (comptread < 0)
			return (-1);
		if (a == '\n')
			ligne++;
	}
	close(fd);
	return (ligne);
}

char	**malloc_ligne(t_info *info, char *dos)
{
	char	**map;
	int		ligne;

	ligne = compt_ligne(dos);
	if (ligne <= 0)
		return (0);
	info->map_height = ligne;
	map = malloc((ligne + 2) * sizeof (char *));
	if (!map)
		return (0);
	return (map);
}

void	lectur_map(t_info *info, char *dos)
{
	int	fd;
	int	i;

	i = 0;
	if (!ft_strnstr(dos, ".ber", ft_strlen(dos)))
		mes_erreur("Ne contient pas de .ber", info);
	info->map = malloc_ligne(info, dos);
	fd = open(dos, O_RDONLY);
	while (info->map_height > i)
	{
		info->map[i] = get_next_line(fd);
		i++;
	}
	info->map_width = ft_strlen(info->map[1]) - 1;
	info->map[i] = 0;
	close(fd);
}
