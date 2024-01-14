/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erreur_fin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhirzel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:04:11 by nhirzel           #+#    #+#             */
/*   Updated: 2021/12/23 17:47:35 by nhirzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	clean(t_info *info)
{
	if (!info->map)
	{
		while (info->map_height > 0)
		{
			free(info->map[info->map_height]);
			(info->map_height)--;
		}
		free(info->map);
	}
	mlx_destroy_image(info->mlx_ptr, info->img.sol);
	mlx_destroy_image(info->mlx_ptr, info->img.mur);
	mlx_destroy_image(info->mlx_ptr, info->img.exite);
	mlx_destroy_image(info->mlx_ptr, info->img.player);
	mlx_destroy_image(info->mlx_ptr, info->img.token);
	mlx_destroy_window(info->mlx_ptr, info->win_ptr);
//	while(1)
//	{}
	exit(0);
}

void	mes_erreur(char *c, t_info *info)
{
	printf("%s", "Error\n");
	printf("%s", c);
	clean(info);
}

void	lettre(char c, t_info *info)
{
	if (c != '1' && c != '0' && c != 'P'
		&& c != 'E' && c != 'C' && c != '\n')
		mes_erreur("il n'y a pas que des C, P, E, 0, 1 dans la map", info);
}

void	contoure(t_info *info, int i, int j)
{
	if (i == 0 || i == info->map_height - 1
		|| j == 0 || j == info->map_width - 1)
	{
		if (info->map[i][j] != '1')
			mes_erreur("il y a un trous dans la map(1)", info);
	}
}

void	start_ok(t_info *info)
{
	if (info->playeur != 1)
		mes_erreur("manque ou trop de (P) sur la map", info);
	if (info->exite != 1)
		mes_erreur("manque ou trop de (E) sur la map", info);
	if (info->coin < 1)
		mes_erreur("pas de coin pour jouer dommage", info);
}
