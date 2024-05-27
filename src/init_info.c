/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 19:51:30 by yaekim            #+#    #+#             */
/*   Updated: 2024/05/27 20:08:27 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_enemy_spot(t_info *info, int i, int j)
{
	static int	index;

	info->enemy_x[index] = i;
	info->enemy_y[index] = j;
	index++;
}

void	init_map_info(t_info *info)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	map = info->map;
	info->c_count = 0;
	while (i < info->row_size)
	{
		j = 0;
		while (j < info->col_size)
		{
			if (map[i][j] == 'C')
				info->c_count += 1;
			else if (map[i][j] == 'X')
				init_enemy_spot(info, i, j);
			else if (map[i][j] == 'E')
				init_spot(info, i, j, 'E');
			else if (map[i][j] == 'P')
				init_spot(info, i, j, 'P');
			j++;
		}
		i++;
	}
}

void	init_info(t_info *info)
{
	int	img_width;
	int	img_height;

	info->mlx = mlx_init();
	info->mlx_win = mlx_new_window(info->mlx, info->col_size * IMG_SIZE, \
									(info->row_size + 1) * IMG_SIZE, "so_long");
	info->x = info->start[1] * IMG_SIZE;
	info->y = info->start[0] * IMG_SIZE;
	info->ground_img = mlx_xpm_file_to_image(info->mlx, \
					"./images/grass.xpm", &img_width, &img_height);
	info->wall_img = mlx_xpm_file_to_image(info->mlx, \
					"./images/stone.xpm", &img_width, &img_height);
	info->char_img = mlx_xpm_file_to_image(info->mlx, \
					"./images/init.xpm", &img_width, &img_height);
	info->coin_img = mlx_xpm_file_to_image(info->mlx, \
					"./images/heart.xpm", &img_width, &img_height);
	info->exit_img = mlx_xpm_file_to_image(info->mlx, \
					"./images/door.xpm", &img_width, &img_height);
	init_img(info);
	info->frame_count = 0;
}
