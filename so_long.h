/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:42:59 by yaekim            #+#    #+#             */
/*   Updated: 2024/05/25 20:50:15 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define IMG_SIZE		32

typedef struct s_sprite
{
    void *img;
    int width;
    int height;
    int frame_count;
}			t_sprite;

typedef struct s_info
{
	char	**map;
	char	*filename;
	int		c_count;
	int		row_size;
	int		col_size;
	int		x;
	int		y;
	int		start[2];
	int		exit[2];
	void	*mlx;
	void	*mlx_win;
	void	*ground_img;
	void	*wall_img;
	void	*char_img;
	void	*coin_img;
	void	*exit_img;
	t_sprite	sprite;
}				t_info;

# include <mlx.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include <fcntl.h>
# include <errno.h>
# include <string.h>

void	move_left(t_info *info, int *count);
void	move_right(t_info *info, int *count);
void	move_up(t_info *info, int *count);
void	move_down(t_info *info, int *count);
void	check_and_draw_exit(t_info *info);
void	check_coin(t_info *info);
void	restore_frame(t_info *info);
void	success_exit(void);

#endif
