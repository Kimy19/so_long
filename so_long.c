/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 19:46:26 by yaekim            #+#    #+#             */
/*   Updated: 2024/05/25 20:52:57 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_error(char *str)
{
	ft_printf("Error\n%s\n", str);
	exit(1);
}

void	save_map(t_info *info, int fd, int row_size)
{
	int		i;
	char	*line;

	i = 0;
	while (i < row_size)
	{
		line = get_next_line(fd);
		if (!line)
			handle_error(strerror(errno));
		(info->map)[i] = line;
		i++;
	}
}

void	check_map_size(t_info *info)
{
	int		i;
	int		j;
	int		col_size;

	j = 0;
	while (info->map[0][j] && info->map[0][j] != '\n')
		j++;
	col_size = j;
	i = 1;
	while (i < info->row_size)
	{
		j = 0;
		while (info->map[i][j] && info->map[i][j] != '\n')
			j++;
		if (j != col_size)
			handle_error("The map must be rectangular");
		i++;
	}
	info->col_size = col_size;
}

void	check_map_component(t_info *info)
{
	int		i;
	int		j;
	int		count[3];

	i = 0;
	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	while (i < info->row_size)
	{
		j = 0;

		while (info->map[i][j] && info->map[i][j] != '\n')
		{
			if (info->map[i][j] == 'C')
				count[0] += 1; 
			else if (info->map[i][j] == 'E')
				count[1] += 1;
			else if (info->map[i][j] == 'P')
				count[2] += 1;
			else if (info->map[i][j] != '1' && info->map[i][j] != '0')
				handle_error("Invalid map component");
			j++;
		}
		i++;
	}
	if (count[0] == 0)
		handle_error("Invalid number of map component");
	if (count[1] != 1 || count[2] != 1)
		handle_error("Invalid number of map component");
}

void	check_wall(t_info *info)
{
	int		i;
	int		j;

	i = 0;
	while (i < info->row_size)
	{
		if (i == 0 || i == info->row_size - 1)
		{
			j = 0;
			while (j < info->col_size)
			{
				if (info->map[i][j] != '1')
					handle_error("Invalid map structure");
				j++;
			}
		}
		else
		{
			if (info->map[i][0] != '1' || info->map[i][info->col_size - 1] != '1')
				handle_error("Invalid map structure");
		}
		i++;
	}
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
			else if (map[i][j] == 'E')
				init_spot(info, i, j, 'E');
			else if (map[i][j] == 'P')
				init_spot(info, i, j, 'P');
			j++;
		}
		i++;
	}
}

void	init_dxdy(int *arr, int n1, int n2, int n3, int n4)
{
	arr[0] = n1;
	arr[1] = n2;
	arr[2] = n3;
	arr[3] = n4;
}

void	move_spot(int *tx, int *ty, int  *spot, int i)
{
	int	dx[4];
	int	dy[4];

	init_dxdy(dx, 1, -1, 0, 0);
	init_dxdy(dy, 0, 0, 1, -1);
	*tx = spot[0] + dx[i];
	*ty = spot[1] + dy[i];
}

void	dfs(t_info *info, int *spot, int *count, int **visit)
{
	int	i;
	int	tx;
	int	ty;
	int	temp[2];

	i = 0;
	while (i < 4)
	{
		move_spot(&tx, &ty, spot, i);
		i++;
		if (tx < 0 || tx >= info->row_size || ty < 0 || ty >= info->col_size)
			continue ;
		if (info->map[tx][ty] == '1' || visit[tx][ty] == 1)
			continue ;
		if (info->map[tx][ty] == 'C')
			*count += 1;
		visit[tx][ty] = 1;
		temp[0] = tx;
		temp[1] = ty;
		dfs(info, temp, count, visit); 
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

void	check_path(t_info *info)
{
	int	count;
	int	**visit;
	int	spot[2];
	int	i;
	int j;

	i = 0;
	visit = (int **)malloc(sizeof(int *) * info->row_size);
	if (!visit)
		handle_error(strerror(errno));
	while (i < info->row_size)
	{
		visit[i] = (int *)malloc(sizeof(int) * info->col_size);
		if (!visit[i])
			handle_error(strerror(errno));
		i++;
	}
	i = 0;
	j = 0;
	while (i < info->row_size)
	{
		while (j < info->col_size)
			visit[i][j++] = 0;
		i++;
	}
	count = 0;
	spot[0] = info->start[0];
	spot[1] = info->start[1];
	dfs(info, spot, &count, visit);
	if (visit[info->exit[0]][info->exit[1]] == 1 && count == info->c_count)
	{
		free_arr(visit, info);
		return ;
	}
	free_arr(visit, info);
	handle_error("Invalid map path");
}

void	check_map(t_info *info)
{
	check_map_size(info);
	check_wall(info);
	check_map_component(info);
	init_map_info(info);
	check_path(info);
}

void	read_map(int fd, t_info *info)
{
	char	*line;
	int		row_size;
	int		i;

	row_size = 0;
	line = get_next_line(fd);
	while (line)
	{
		row_size++;
		free(line);
		line = get_next_line(fd);
	}
	if (row_size < 3)
		handle_error("Invalid map size");
	info->map = (char **)malloc(sizeof(char *) * row_size);
	if (!info->map)
		exit(0);
	i = 0;
	while (i < row_size)
		info->map[i++] = NULL;
	fd = open(info->filename, O_RDONLY);
	save_map(info, fd, row_size);
	info->row_size = row_size;
	check_map(info);
	close(fd);
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
			mlx_put_image_to_window(info->mlx, info->mlx_win, info->ground_img, x, y);
			x += 32;
		}
		y += 32;
	}
	ft_printf("Moved %d steps\n", count);
	num = ft_itoa(count);
	str = ft_strjoin(num, " steps");
	mlx_string_put(info->mlx, info->mlx_win, IMG_SIZE, (info->row_size + 0.5) * IMG_SIZE, 255, str);
	free(num);
	free(str);
}

void	draw_image(void *mlx, void *mlx_win, t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->row_size)
	{
		j = 0;
		while (j < info->col_size)
		{
			mlx_put_image_to_window(mlx, mlx_win, info->ground_img, IMG_SIZE * j, IMG_SIZE * i);
			if (info->map[i][j] == '1')
				mlx_put_image_to_window(mlx, mlx_win, info->wall_img, IMG_SIZE * j, IMG_SIZE * i);
			else if (info->map[i][j] == 'E')
				mlx_put_image_to_window(mlx, mlx_win, info->exit_img, IMG_SIZE * j, IMG_SIZE * i);
			else if (info->map[i][j] == 'C')
				mlx_put_image_to_window(mlx, mlx_win, info->coin_img, IMG_SIZE * j, IMG_SIZE * i);
			else if (info->map[i][j] == 'P')
				mlx_put_image_to_window(mlx, mlx_win, info->char_img, IMG_SIZE * j, IMG_SIZE * i);
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
	else if (keycode ==KEY_ESC)
	{
		ft_printf("Exited\n");
		exit(0);
	}
	if (temp < count)
		print_steps(info, count);
	return (0);
}

void init_sprites(t_info *info)
{
    info->sprite.img = mlx_xpm_file_to_image(info->mlx, "./images/bird.xpm", &info->sprite.width, &info->sprite.height);
    info->sprite.frame_count = 4; // Assuming each direction has 4 frames
}

// void loop_hook(t_info *info)
// {

// }

int	destroy_window(t_info *info)
{
	mlx_destroy_window(info->mlx, info->mlx_win);
	ft_printf("Exited\n");
	exit(0);
	return (0);
}

void check_arg(t_info *info, char *argv[])
{
	char *str;
	int		i;

	i = 0;
	
	str = ft_strnstr(ft_strrchr(argv[1],'.'), ".ber", ft_strlen(argv[1]));
	if (str == 0)
		handle_error("Invalid type of map file");
	while (i < 4)
	{
		str++;
		i++;
	}
	if (*str != 0)
		handle_error("Invalid type of map file");
	info->filename = argv[1];
}

void	init_info(t_info *info)
{
	int img_width;
	int img_height;

	info->mlx = mlx_init();
	info->mlx_win = mlx_new_window(info->mlx, info->col_size * IMG_SIZE, (info->row_size + 1) * IMG_SIZE, "so_long");
	init_sprites(info);
	info->x = info->start[1] * IMG_SIZE;
	info->y = info->start[0] * IMG_SIZE;
	info->ground_img = mlx_xpm_file_to_image(info->mlx, "./images/grass.xpm",&img_width, &img_height);
	info->wall_img = mlx_xpm_file_to_image(info->mlx, "./images/stone.xpm",&img_width, &img_height);
	info->char_img = mlx_xpm_file_to_image(info->mlx, "./images/down.xpm",&img_width, &img_height);
	info->coin_img = mlx_xpm_file_to_image(info->mlx, "./images/heart.xpm",&img_width, &img_height);
	info->exit_img = mlx_xpm_file_to_image(info->mlx, "./images/door.xpm",&img_width, &img_height);
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
	draw_image(info->mlx, info->mlx_win, info);
	mlx_key_hook(info->mlx_win, key_hook, info);
	mlx_hook(info->mlx_win, 17, 0, destroy_window, info);
	// mlx_loop_hook(info->mlx_win, loop_hook, info);
	mlx_loop(info->mlx);
	
	return(0);
}

