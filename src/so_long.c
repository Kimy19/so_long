/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 19:46:26 by yaekim            #+#    #+#             */
/*   Updated: 2024/05/28 15:49:43 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_by_map(t_info *info, int i, int j)
{
	mlx_put_image_to_window(info->mlx, info->mlx_win, info->ground_img, \
									IMG_SIZE * j, IMG_SIZE * i);
	if (info->map[i][j] == '1')
		mlx_put_image_to_window(info->mlx, info->mlx_win, info->wall_img, \
							IMG_SIZE * j, IMG_SIZE * i);
	else if (info->map[i][j] == 'E')
		mlx_put_image_to_window(info->mlx, info->mlx_win, info->exit_img, \
							IMG_SIZE * j, IMG_SIZE * i);
	else if (info->map[i][j] == 'C')
		mlx_put_image_to_window(info->mlx, info->mlx_win, info->coin_img, \
							IMG_SIZE * j, IMG_SIZE * i);
	else if (info->map[i][j] == 'P')
		mlx_put_image_to_window(info->mlx, info->mlx_win, info->char_img, \
							IMG_SIZE * j, IMG_SIZE * i);
}

void	draw_image(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->row_size)
	{
		j = 0;
		while (j < info->col_size)
		{
			draw_by_map(info, i, j);
			j++;
		}
		i++;
	}
	print_steps(info, 0);
}

int	key_hook(int keycode, t_info *info)
{
	static int	count;
	int			temp;

	temp = count;
	if (keycode == KEY_W)
		move_up(info, &count);
	else if (keycode == KEY_S)
		move_down(info, &count);
	else if (keycode == KEY_A)
		move_left(info, &count);
	else if (keycode == KEY_D)
		move_right(info, &count);
	else if (keycode == KEY_ESC)
		destroy_window(info);
	if (temp < count)
		print_steps(info, count);
	return (0);
}

int	main(int argc, char *argv[])
{
	int		fd;
	t_info	*info;

	if (argc != 2)
		handle_error("Wrong number of arguments");
	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		handle_error(strerror(errno));
	check_arg(info, argv);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		handle_error(strerror(errno));
	read_map(fd, info);
	init_info(info);
	draw_image(info);
	mlx_key_hook(info->mlx_win, key_hook, info);
	mlx_hook(info->mlx_win, 17, 0, destroy_window, info);
	mlx_loop(info->mlx);
	return (0);
}
