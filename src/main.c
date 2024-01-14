/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhirzel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:20:15 by nhirzel           #+#    #+#             */
/*   Updated: 2021/12/09 18:28:43 by nhirzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	compteur_mouve(t_info *info)
{
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img.sol,
		0, 0);
	mlx_string_put(info->mlx_ptr, info->win_ptr, 8, 16, 1,
		ft_itoa(info->mouvement));
}

int	deal_key(int keycode, t_info *info)
{
	if (keycode == KEY_ESC)
		clean(info);
	if (!info_wall(keycode, info) && !info_end(keycode, info))
	{
		mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img.mur,
			info->playerx * 32, info->playery * 32);
		info->map[info->playery][info->playerx] = '0';
		if (keycode == KEY_W)
			info->playery -= 1;
		if (keycode == KEY_A)
			info->playerx -= 1;
		if (keycode == KEY_S)
			info->playery += 1;
		if (keycode == KEY_D)
			info->playerx += 1;
		if (info->map[info->playery][info->playerx] == 'E')
			clean(info);
		info->map[info->playery][info->playerx] = 'P';
		mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img.player,
			info->playerx * 32, info->playery * 32);
		(info->mouvement)++;
		compteur_mouve(info);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_info	info;
	int		img_width;
	int		img_height;

	if (argc != 2)
		return (0);
	img_width = 0;
	img_height = 0;
	lectur_map(&info, argv[1]);
	info.mlx_ptr = mlx_init();
	info.win_ptr = mlx_new_window(info.mlx_ptr, 32 * info.map_width,
			32 * info.map_height, "so_long");
	parcourire_map(&info);
	mlx_key_hook(info.win_ptr, deal_key, &info);
	mlx_hook(info.win_ptr, 17, 0, clean, &info);
	mlx_loop(info.mlx_ptr);
	return (0);
}
