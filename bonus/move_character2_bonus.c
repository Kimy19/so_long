/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_character2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 07:27:27 by yaekim            #+#    #+#             */
/*   Updated: 2024/05/28 15:41:47 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	success_exit(void)
{
	ft_printf("SUCCESS!");
	exit(0);
}

void	restore_frame(t_info *info)
{
	mlx_put_image_to_window(info->mlx, info->mlx_win, \
							info->ground_img, info->x, info->y);
	if (info->map[info->y / 32][info->x / 32] == 'E')
		mlx_put_image_to_window(info->mlx, info->mlx_win, \
								info->exit_img, info->x, info->y);
}

void	check_coin(t_info *info)
{
	if (info->map[(info->y / 32)][(info->x / 32)] == 'C')
	{	
		mlx_put_image_to_window(info->mlx, info->mlx_win, \
								info->ground_img, info->x, info->y);
		mlx_put_image_to_window(info->mlx, info->mlx_win, \
								info->char_img, info->x, info->y);
		info->map[(info->y / 32)][(info->x / 32)] = '0';
		info->c_count -= 1;
		check_and_draw_exit(info);
	}
}

void	check_and_draw_exit(t_info *info)
{
	int		img_w;
	int		img_h;

	if (info->c_count == 0)
	{
		info->exit_img = mlx_xpm_file_to_image(info->mlx, \
							"./images/door_opened.xpm", &img_w, &img_h);
		mlx_put_image_to_window(info->mlx, info->mlx_win, info->exit_img, \
								info->exit[1] * 32, info->exit[0] * 32);
	}
}
