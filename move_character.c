/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_character.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 07:27:27 by yaekim            #+#    #+#             */
/*   Updated: 2024/05/23 17:20:19 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	restore_frame(t_info *info)
{
	mlx_put_image_to_window(info->mlx, info->mlx_win, info->ground_img, info->x, info->y);
	if (info->map[info->y / 32][info->x / 32] == 'E')
		mlx_put_image_to_window(info->mlx, info->mlx_win, info->exit_img,  info->x, info->y);
}
void	move_left(t_info *info, int *count)
{
	int		img_w;
	int		img_h;

	info->char_img = mlx_xpm_file_to_image(info->mlx, "./images/left.xpm", &img_w, &img_h);
	if (info->map[(info->y / 32)][(info->x / 32) - 1] == '1')
	{
		mlx_put_image_to_window(info->mlx, info->mlx_win, info->char_img, info->x, info->y);
		return ;
	}
	restore_frame(info);
	if (info->map[(info->y / 32)][(info->x / 32) - 1] == 'E' && info->c_count == 0)
	{
			exit(0);
	}
	info->x -= 32;
	(*count)++;
	mlx_put_image_to_window(info->mlx, info->mlx_win, info->char_img, info->x, info->y);
	if (info->map[(info->y / 32)][(info->x / 32)] == 'C')
	{
		mlx_put_image_to_window(info->mlx, info->mlx_win, info->ground_img, info->x, info->y);
		mlx_put_image_to_window(info->mlx, info->mlx_win, info->char_img, info->x, info->y);
		info->map[(info->y / 32)][(info->x / 32)] = '0';
		info->c_count -= 1;
		if (info->c_count == 0)
		{
			info->exit_img = mlx_xpm_file_to_image(info->mlx, "./images/door_opened.xpm", &img_w, &img_h);
			mlx_put_image_to_window(info->mlx, info->mlx_win, info->exit_img, info->exit[1] * 32, info->exit[0] * 32);
		}
	}
}

void	move_right(t_info *info, int *count)
{
	int		img_w;
	int		img_h;

	info->char_img = mlx_xpm_file_to_image(info->mlx, "./images/right.xpm", &img_w, &img_h);
	if (info->map[(info->y / 32)][(info->x / 32) + 1] == '1')
	{
		mlx_put_image_to_window(info->mlx, info->mlx_win, info->char_img, info->x, info->y);
		return ;
	}
	restore_frame(info);
	if (info->map[(info->y / 32)][(info->x / 32) + 1] == 'E' && info->c_count == 0)
	{
			exit(0);
	}
	info->x += 32;
	(*count)++;
	mlx_put_image_to_window(info->mlx, info->mlx_win, info->char_img, info->x, info->y);
	if (info->map[(info->y / 32)][(info->x / 32)] == 'C')
	{	
		mlx_put_image_to_window(info->mlx, info->mlx_win, info->ground_img, info->x, info->y);
		mlx_put_image_to_window(info->mlx, info->mlx_win, info->char_img, info->x, info->y);
		info->map[(info->y / 32)][(info->x / 32)] = '0';
		info->c_count -= 1;
		if (info->c_count == 0)
		{
			info->exit_img = mlx_xpm_file_to_image(info->mlx, "./images/door_opened.xpm", &img_w, &img_h);
			mlx_put_image_to_window(info->mlx, info->mlx_win, info->exit_img, info->exit[1] * 32, info->exit[0] * 32);
		}
	}
}

void	move_up(t_info *info, int *count)
{
	int		img_w;
	int		img_h;

	info->char_img = mlx_xpm_file_to_image(info->mlx, "./images/up.xpm", &img_w, &img_h);
	if (info->map[(info->y / 32) - 1][(info->x / 32)] == '1')
	{
		mlx_put_image_to_window(info->mlx, info->mlx_win, info->char_img, info->x, info->y);
		return ;
	}
	restore_frame(info);
	if (info->map[(info->y / 32) - 1][(info->x / 32)] == 'E' && info->c_count == 0)
	{
			exit(0);
	}
	info->y -= 32;
	(*count)++;
	mlx_put_image_to_window(info->mlx, info->mlx_win, info->char_img, info->x, info->y);
	if (info->map[(info->y / 32)][(info->x / 32)] == 'C')
	{	
		mlx_put_image_to_window(info->mlx, info->mlx_win, info->ground_img, info->x, info->y);
		mlx_put_image_to_window(info->mlx, info->mlx_win, info->char_img, info->x, info->y);
		info->map[(info->y / 32)][(info->x / 32)] = '0';
		info->c_count -= 1;
		if (info->c_count == 0)
		{
			info->exit_img = mlx_xpm_file_to_image(info->mlx, "./images/door_opened.xpm", &img_w, &img_h);
			mlx_put_image_to_window(info->mlx, info->mlx_win, info->exit_img, info->exit[1] * 32, info->exit[0] * 32);
		}
	}
}

void	move_down(t_info *info, int *count)
{
	int		img_w;
	int		img_h;

	info->char_img = mlx_xpm_file_to_image(info->mlx, "./images/down.xpm", &img_w, &img_h);
	if (info->map[(info->y / 32) + 1][(info->x / 32)] == '1')
	{
		mlx_put_image_to_window(info->mlx, info->mlx_win, info->char_img, info->x, info->y);
		return ;
	}
	restore_frame(info);
	if (info->map[(info->y / 32) + 1][(info->x / 32)] == 'E' && info->c_count == 0)
	{
			exit(0);
	}
	info->y += 32;
	(*count)++;
	mlx_put_image_to_window(info->mlx, info->mlx_win, info->char_img, info->x, info->y);
	if (info->map[(info->y / 32)][(info->x / 32)] == 'C')
	{	
		mlx_put_image_to_window(info->mlx, info->mlx_win, info->ground_img, info->x, info->y);
		mlx_put_image_to_window(info->mlx, info->mlx_win, info->char_img, info->x, info->y);
		info->map[(info->y / 32)][(info->x / 32)] = '0';
		info->c_count -= 1;
		if (info->c_count == 0)
		{
			info->exit_img = mlx_xpm_file_to_image(info->mlx, "./images/door_opened.xpm", &img_w, &img_h);
			mlx_put_image_to_window(info->mlx, info->mlx_win, info->exit_img, info->exit[1] * 32, info->exit[0] * 32);
		}
	}
}
