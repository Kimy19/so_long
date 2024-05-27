/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:42:59 by yaekim            #+#    #+#             */
/*   Updated: 2024/05/27 19:54:46 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include <errno.h>
# include <string.h>

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define IMG_SIZE		32

typedef struct s_info
{
	char		**map;
	char		*filename;
	int			c_count;
	int			enemy_count;
	int			row_size;
	int			col_size;
	int			x;
	int			y;
	int			start[2];
	int			exit[2];
	int			*enemy_x;
	int			*enemy_y;
	void		*mlx;
	void		*mlx_win;
	void		*ground_img;
	void		*wall_img;
	void		*char_img;
	void		*coin_img;
	void		*exit_img;
	void		*up_img[4];
	void		*down_img[4];
	void		*left_img[4];
	void		*right_img[4];
	void		*enemy_img[4];
	int			frame_count;
}				t_info;

void	move_left(t_info *info, int *count);
void	move_right(t_info *info, int *count);
void	move_up(t_info *info, int *count);
void	move_down(t_info *info, int *count);
void	check_and_draw_exit(t_info *info);
void	check_coin(t_info *info);
void	restore_frame(t_info *info);
void	success_exit(void);
void	handle_error(char *str);
int		destroy_window(t_info *info);
void	init_spot(t_info *info, int i, int j, char type);
void	free_arr(int **visit, t_info *info);
void	check_path(t_info *info);
void	init_map_info(t_info *info);
void	check_map(t_info *info);
void	save_map(t_info *info, int fd, int row_size);
void	check_arg(t_info *info, char *argv[]);
void	read_map(int fd, t_info *info);
void	count_map_component(t_info *info, char c, int *count);
void	check_map_component(t_info *info);
void	check_wall(t_info *info);
void	check_map_size(t_info *info);
void	init_img(t_info *info);
void	init_enemy(t_info *info);
void	init_enemy_spot(t_info *info, int i, int j);
void	init_map_info(t_info *info);
void	init_info(t_info *info);
void	print_steps(t_info *info, int count);

#endif
