/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_character1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 07:27:27 by yaekim            #+#    #+#             */
/*   Updated: 2024/05/27 19:28:49 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_info *info, int *count)
{
	info->char_img = info->left_img[info->frame_count % 4];
	restore_frame(info);
	if (info->map[(info->y / 32)][(info->x / 32) - 1] == '1')
	{
		mlx_put_image_to_window(info->mlx, info->mlx_win, \
								info->char_img, info->x, info->y);
		return ;
	}
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
	info->char_img = info->right_img[info->frame_count % 4];
	restore_frame(info);
	if (info->map[(info->y / 32)][(info->x / 32) + 1] == '1')
	{
		mlx_put_image_to_window(info->mlx, info->mlx_win, \
								info->char_img, info->x, info->y);
		return ;
	}
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
	info->char_img = info->up_img[info->frame_count % 4];
	restore_frame(info);
	if (info->map[(info->y / 32) - 1][(info->x / 32)] == '1')
	{
		mlx_put_image_to_window(info->mlx, info->mlx_win, \
								info->char_img, info->x, info->y);
		return ;
	}
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
	info->char_img = info->down_img[info->frame_count % 4];
	restore_frame(info);
	if (info->map[(info->y / 32) + 1][(info->x / 32)] == '1')
	{
		mlx_put_image_to_window(info->mlx, info->mlx_win, \
								info->char_img, info->x, info->y);
		return ;
	}
	if (info->map[(info->y / 32) + 1][(info->x / 32)] == 'E' \
		&& info->c_count == 0)
		success_exit();
	info->y += 32;
	(*count)++;
	mlx_put_image_to_window(info->mlx, info->mlx_win, \
							info->char_img, info->x, info->y);
	check_coin(info);
}
