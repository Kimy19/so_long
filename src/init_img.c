/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:33:03 by yaekim            #+#    #+#             */
/*   Updated: 2024/05/28 15:47:55 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_up(t_info *info)
{
	int	img_width;
	int	img_height;

	info->up_img[0] = mlx_xpm_file_to_image(info->mlx, \
				"./images/char/up_0.xpm", &img_width, &img_height);
	info->up_img[1] = mlx_xpm_file_to_image(info->mlx, \
				"./images/char/up_1.xpm", &img_width, &img_height);
	info->up_img[2] = mlx_xpm_file_to_image(info->mlx, \
				"./images/char/up_2.xpm", &img_width, &img_height);
	info->up_img[3] = mlx_xpm_file_to_image(info->mlx, \
				"./images/char/up_3.xpm", &img_width, &img_height);
}

void	init_down(t_info *info)
{
	int	img_width;
	int	img_height;

	info->down_img[0] = mlx_xpm_file_to_image(info->mlx, \
				"./images/char/down_0.xpm", &img_width, &img_height);
	info->down_img[1] = mlx_xpm_file_to_image(info->mlx, \
				"./images/char/down_1.xpm", &img_width, &img_height);
	info->down_img[2] = mlx_xpm_file_to_image(info->mlx, \
				"./images/char/down_2.xpm", &img_width, &img_height);
	info->down_img[3] = mlx_xpm_file_to_image(info->mlx, \
				"./images/char/down_3.xpm", &img_width, &img_height);
}

void	init_left(t_info *info)
{
	int	img_width;
	int	img_height;

	info->left_img[0] = mlx_xpm_file_to_image(info->mlx, \
				"./images/char/left_0.xpm", &img_width, &img_height);
	info->left_img[1] = mlx_xpm_file_to_image(info->mlx, \
				"./images/char/left_1.xpm", &img_width, &img_height);
	info->left_img[2] = mlx_xpm_file_to_image(info->mlx, \
				"./images/char/left_2.xpm", &img_width, &img_height);
	info->left_img[3] = mlx_xpm_file_to_image(info->mlx, \
				"./images/char/left_3.xpm", &img_width, &img_height);
}

void	init_right(t_info *info)
{
	int	img_width;
	int	img_height;

	info->right_img[0] = mlx_xpm_file_to_image(info->mlx, \
				"./images/char/right_0.xpm", &img_width, &img_height);
	info->right_img[1] = mlx_xpm_file_to_image(info->mlx, \
				"./images/char/right_1.xpm", &img_width, &img_height);
	info->right_img[2] = mlx_xpm_file_to_image(info->mlx, \
				"./images/char/right_2.xpm", &img_width, &img_height);
	info->right_img[3] = mlx_xpm_file_to_image(info->mlx, \
				"./images/char/right_3.xpm", &img_width, &img_height);
}

void	init_img(t_info *info)
{
	init_up(info);
	init_down(info);
	init_left(info);
	init_right(info);
}
