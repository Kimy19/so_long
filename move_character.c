/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_character.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 07:27:27 by yaekim            #+#    #+#             */
/*   Updated: 2024/05/25 20:49:41 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_info *info, int *count)
{
	int		img_w;
	int		img_h;

	info->char_img = mlx_xpm_file_to_image(info->mlx, \
						"./images/left.xpm", &img_w, &img_h);
	if (info->map[(info->y / 32)][(info->x / 32) - 1] == '1')
	{
		mlx_put_image_to_window(info->mlx, info->mlx_win, \
								info->char_img, info->x, info->y);
		return ;
	}
	restore_frame(info);
	if (info->map[(info->y / 32)][(info->x / 32) - 1] == 'E' \
		&& info->c_count == 0)
		success_exit();
	info->x -= 32;
	(*count)++;
	mlx_put_image_to_window(info->mlx, info->mlx_win, \
							info->char_img, info->x, info->y);
	check_coin(info);
}

void	move_right(t_info *info, int *count)
{
	int		img_w;
	int		img_h;

	info->char_img = mlx_xpm_file_to_image(info->mlx, \
						"./images/right.xpm", &img_w, &img_h);
	if (info->map[(info->y / 32)][(info->x / 32) + 1] == '1')
	{
		mlx_put_image_to_window(info->mlx, info->mlx_win, \
								info->char_img, info->x, info->y);
		return ;
	}
	restore_frame(info);
	if (info->map[(info->y / 32)][(info->x / 32) + 1] == 'E' \
		&& info->c_count == 0)
		success_exit();
	info->x += 32;
	(*count)++;
	mlx_put_image_to_window(info->mlx, info->mlx_win, \
							info->char_img, info->x, info->y);
	check_coin(info);
}

void	move_up(t_info *info, int *count)
{
	int		img_w;
	int		img_h;

	info->char_img = mlx_xpm_file_to_image(info->mlx, \
						"./images/up.xpm", &img_w, &img_h);
	if (info->map[(info->y / 32) - 1][(info->x / 32)] == '1')
	{
		mlx_put_image_to_window(info->mlx, info->mlx_win, \
								info->char_img, info->x, info->y);
		return ;
	}
	restore_frame(info);
	if (info->map[(info->y / 32) - 1][(info->x / 32)] == 'E' \
		&& info->c_count == 0)
		success_exit();
	info->y -= 32;
	(*count)++;
	mlx_put_image_to_window(info->mlx, info->mlx_win, \
							info->char_img, info->x, info->y);
	check_coin(info);
}

void	move_down(t_info *info, int *count)
{
	int		img_w;
	int		img_h;

	info->char_img = mlx_xpm_file_to_image(info->mlx, \
						"./images/down.xpm", &img_w, &img_h);
	if (info->map[(info->y / 32) + 1][(info->x / 32)] == '1')
	{
		mlx_put_image_to_window(info->mlx, info->mlx_win, \
								info->char_img, info->x, info->y);
		return ;
	}
	restore_frame(info);
	if (info->map[(info->y / 32) + 1][(info->x / 32)] == 'E' \
		&& info->c_count == 0)
		success_exit();
	info->y += 32;
	(*count)++;
	mlx_put_image_to_window(info->mlx, info->mlx_win, \
							info->char_img, info->x, info->y);
	check_coin(info);
}
