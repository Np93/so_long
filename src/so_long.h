/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhirzel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 19:20:31 by nhirzel           #+#    #+#             */
/*   Updated: 2021/12/09 18:44:01 by nhirzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdint.h>
# include <stdbool.h>
# include <limits.h>
# include <string.h>

# define BUFFER_SIZE 1

typedef struct s_img
{
	void	*sol;
	void	*mur;
	void	*exite;
	void	*token;
	void	*player;
}	t_img;

typedef struct s_info
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	char	**map;
	int		map_width;
	int		map_height;
	int		playerx;
	int		playery;
	int		coin;
	int		playeur;
	int		exite;
	int		mouvement;
}	t_info;

# define KEY_ESC 53
# define KEY_PRESS 2
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

char	*get_next_line(int fd);
int		ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
int		main(int argc, char **argv);
char	*ft_itoa(int n);
void	start_ok(t_info *info);
void	contoure(t_info *info, int i, int j);
void	lettre(char c, t_info *info);
void	mes_erreur(char *c, t_info *info);
int		clean(t_info *info);
void	lectur_map(t_info *info, char *dos);
void	parcourire_map(t_info *info);
int		info_wall(int keycode, t_info *info);
int		info_end(int keycode, t_info *info);

#endif
