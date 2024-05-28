/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:47:59 by yaekim            #+#    #+#             */
/*   Updated: 2024/05/28 15:42:31 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	handle_error(char *str)
{
	ft_printf("Error\n%s\n", str);
	exit(1);
}

int	destroy_window(t_info *info)
{
	mlx_destroy_window(info->mlx, info->mlx_win);
	ft_printf("Exited\n");
	exit(0);
	return (0);
}

void	init_spot(t_info *info, int i, int j, char type)
{
	if (type == 'E')
	{
		info->exit[0] = i;
		info->exit[1] = j;
	}
	else if (type == 'P')
	{
		info->start[0] = i;
		info->start[1] = j;
	}
}

void	free_arr(int **visit, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->row_size)
	{
		free(visit[i]);
		i++;
	}
	free(visit);
}

void	print_steps(t_info *info, int count)
{
	int		x;
	int		y;
	char	*num;
	char	*str;

	y = (info->row_size) * IMG_SIZE;
	while (y < (info->row_size + 1) * IMG_SIZE)
	{
		x = 0;
		while (x < info->col_size * IMG_SIZE)
		{
			mlx_pixel_put(info->mlx, info->mlx_win, x, y, 0);
			mlx_put_image_to_window(info->mlx, info->mlx_win, \
									info->ground_img, x, y);
			x += 32;
		}
		y += 32;
	}
	ft_printf("Moved %d steps\n", count);
	num = ft_itoa(count);
	str = ft_strjoin(num, " steps");
	mlx_string_put(info->mlx, info->mlx_win, IMG_SIZE, \
					(info->row_size + 0.5) * IMG_SIZE, 255, str);
	free(num);
	free(str);
}
