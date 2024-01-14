/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_div.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhirzel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:17:57 by nhirzel           #+#    #+#             */
/*   Updated: 2021/12/09 18:19:29 by nhirzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	info_coin(int keycode, t_info *info)
{
	if (keycode == KEY_W)
	{
		if (info->map[info->playery - 1][info->playerx] == 'C')
			(info->coin)--;
	}
	if (keycode == KEY_A)
	{
		if (info->map[info->playery][info->playerx - 1] == 'C')
			(info->coin)--;
	}
	if (keycode == KEY_S)
	{
		if (info->map[info->playery + 1][info->playerx] == 'C')
			(info->coin)--;
	}
	if (keycode == KEY_D)
	{
		if (info->map[info->playery][info->playerx + 1] == 'C')
			(info->coin)--;
	}
}

int	info_end(int keycode, t_info *info)
{
	info_coin(keycode, info);
	if (!((info->coin) == 0))
	{
		if (keycode == KEY_W)
		{
			if (info->map[info->playery - 1][info->playerx] == 'E')
				return (1);
		}
		if (keycode == KEY_A)
		{
			if (info->map[info->playery][info->playerx - 1] == 'E')
				return (1);
		}
		if (keycode == KEY_S)
		{
			if (info->map[info->playery + 1][info->playerx] == 'E')
				return (1);
		}
		if (keycode == KEY_D)
		{
			if (info->map[info->playery][info->playerx + 1] == 'E')
				return (1);
		}
	}
	return (0);
}

int	info_wall(int keycode, t_info *info)
{
	if (keycode == KEY_W)
	{
		if (info->map[info->playery - 1][info->playerx] == '1')
			return (1);
	}
	if (keycode == KEY_A)
	{
		if (info->map[info->playery][info->playerx - 1] == '1')
			return (1);
	}
	if (keycode == KEY_S)
	{
		if (info->map[info->playery + 1][info->playerx] == '1')
			return (1);
	}
	if (keycode == KEY_D)
	{
		if (info->map[info->playery][info->playerx + 1] == '1')
			return (1);
	}
	return (0);
}
