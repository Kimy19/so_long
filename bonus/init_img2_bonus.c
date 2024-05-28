/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:36:16 by yaekim            #+#    #+#             */
/*   Updated: 2024/05/28 15:41:32 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_enemy(t_info *info)
{
	int	img_width;
	int	img_height;

	info->enemy_img[0] = mlx_xpm_file_to_image(info->mlx, \
				"./images/enemy/enemy_0.xpm", &img_width, &img_height);
	info->enemy_img[1] = mlx_xpm_file_to_image(info->mlx, \
				"./images/enemy/enemy_1.xpm", &img_width, &img_height);
	info->enemy_img[2] = mlx_xpm_file_to_image(info->mlx, \
				"./images/enemy/enemy_2.xpm", &img_width, &img_height);
	info->enemy_img[3] = mlx_xpm_file_to_image(info->mlx, \
				"./images/enemy/enemy_3.xpm", &img_width, &img_height);
}
