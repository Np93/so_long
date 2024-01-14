/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhirzel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:13:47 by nhirzel           #+#    #+#             */
/*   Updated: 2021/12/09 18:16:17 by nhirzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_1(t_info *info)
{
	int	a;
	int	b;

	info->img.sol = mlx_xpm_file_to_image(info->mlx_ptr,
			"img/map/mur.xpm", &a, &b);
	if (!info->img.sol)
		mes_erreur("probleme avec l'image des murs", info);
	info->img.mur = mlx_xpm_file_to_image(info->mlx_ptr,
			"img/map/sol.xpm", &a, &b);
	if (!info->img.mur)
		mes_erreur("probleme avec l'image du sol", info);
	info->img.exite = mlx_xpm_file_to_image(info->mlx_ptr,
			"img/map/exite.xpm", &a, &b);
	if (!info->img.exite)
		mes_erreur("probleme avec l'image de l'Exit", info);
	info->img.player = mlx_xpm_file_to_image(info->mlx_ptr,
			"img/player/player.xpm", &a, &b);
	if (!info->img.player)
		mes_erreur("probleme avec l'image du player", info);
	info->img.token = mlx_xpm_file_to_image(info->mlx_ptr,
			"img/token/token.xpm", &a, &b);
	if (!info->img.token)
		mes_erreur("probleme avec l'image des coin", info);
}

void	img_trop_long(t_info *info, int i, int j)
{
	if (info->map[i][j] == '1')
		mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img.sol,
			j * 32, i * 32);
	if (info->map[i][j] == '0')
		mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img.mur,
			j * 32, i * 32);
	if (info->map[i][j] == 'E')
	{
		(info->exite)++;
		mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img.exite,
			j * 32, i * 32);
	}
}

void	ajout_img(t_info *info, int i, int j)
{
	img_1(info);
	img_trop_long(info, i, j);
	if (info->map[i][j] == 'P')
	{
		(info->playeur)++;
		info->playerx = j;
		info->playery = i;
		mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img.mur,
			j * 32, i * 32);
		mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img.player,
			j * 32, i * 32);
	}
	if (info->map[i][j] == 'C')
	{
		mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img.mur,
			j * 32, i * 32);
		mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img.token,
			j * 32, i * 32);
		(info->coin)++;
	}
}

void	parcourire_map(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	info->coin = 0;
	info->playeur = 0;
	info->exite = 0;
	info->mouvement = 0;
	while (info->map[i])
	{
		j = 0;
		if (ft_strlen(info->map[i]) - 1 != info->map_width)
			mes_erreur("map pas rectngle", info);
		while (j < info->map_width)
		{
			ajout_img(info, i, j);
			lettre(info->map[i][j], info);
			contoure(info, i, j);
			j++;
		}
		i++;
	}
	start_ok(info);
}
