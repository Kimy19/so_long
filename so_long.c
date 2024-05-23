#include "so_long.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	free_exit(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->row_size)
	{
		free(info->map[i]);
		i++;
	}
	free(info->map);
	free(info);
	ft_printf("exit");
	exit(0);
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
		{
			ft_printf("Here\n");
			free_exit(info);
		}
		ft_printf("!! %s",line);
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
		{
			ft_printf("Error\nThe map must be rectangular\n");
			free_exit(info);
		}
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
			{
				ft_printf("\n!%c!\n",info->map[i][j]);
				ft_printf("invalid map component");
				exit(1);
			}
			j++;
		}
		i++;
	}
	ft_printf("%d %d %d\n",count[0],count[1],count[2]);

	if (count[0] == 0)
	{
		ft_printf("Here4\n");
		free_exit(info);
	}
	if (count[1] > 1 || count[2] > 1)
	{
		ft_printf("Here3\n");
		free_exit(info);
	}
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
				{
					ft_printf("Here1\n");
					free_exit(info);
				}
				j++;
			}
		}
		else
		{
			if (info->map[i][0] != '1' || info->map[i][info->col_size - 1] != '1')
			{
				ft_printf("Here2\n");
				free_exit(info);
			}
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

	i = 0;
	visit = (int **)malloc(sizeof(int *) * info->row_size);
	if (!visit)
		exit(0);
	while (i < info->row_size)
	{
		visit[i] = (int *)malloc(sizeof(int) * info->col_size);
		if (!visit[i])
			exit(0);
		i++;
	}
	for(int i = 0; i<info->row_size; i++)
	{
		for(int j = 0; j<info->col_size; j++)
			visit[i][j] = 0;
	}
	ft_printf("visit 값 %d\n",visit[info->exit[0]][info->exit[1]]);
	
	count = 0;
	spot[0] = info->start[0];
	spot[1] = info->start[1];

	dfs(info, spot, &count, visit);
	for(int i = 0; i<info->row_size; i++)
	{
		for(int j = 0; j<info->col_size; j++)
		{
			ft_printf("%d",visit[i][j]);
		}
		ft_printf("\n");
	}
	ft_printf("visit %d\n",visit[info->exit[0]][info->exit[1]]);
	ft_printf("count %d %d\n",count, info->c_count);

	if (visit[info->exit[0]][info->exit[1]] == 1 && count == info->c_count)
	{
		free_arr(visit, info);
		ft_printf("valid path");
		return ;
	}
	free_arr(visit, info);
	ft_printf("Not valid path");
	exit(0);
}

void	check_map(t_info *info)
{
	check_map_size(info);
	check_wall(info);
	check_map_component(info);
	init_map_info(info);

	ft_printf("map 출력\n");
	for(int i = 0; i<info->row_size; i++)
	{
		for(int j = 0; j<info->col_size; j++)
		{
			ft_printf("%c",info->map[i][j]);
		}
		ft_printf("\n");
	}
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
		ft_printf("%s\n",line);
		free(line);
		line = get_next_line(fd);
	}
	if (row_size < 3)
	{
		exit(0);
	}
	ft_printf("\n처음 row size: %d",row_size);
	info->map = (char **)malloc(sizeof(char *) * row_size);
	if (!info->map)
		exit(0);
	i = 0;
	while (i < row_size)
		info->map[i++] = NULL;


	fd = open("map.ber", O_RDONLY);
	ft_printf("\nfd %d",fd);
	save_map(info, fd, row_size);



	info->row_size = row_size;
	check_map(info);
	// i = 0;
	// while (i < row_size)
	// {
	// 	ft_printf("%s",(info->map)[i]);
	// 	i++;
	// }
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
			ft_printf("%c",info->map[i][j]);
			mlx_put_image_to_window(mlx, mlx_win, info->ground_img,  32 * j,  32 * i);
				// mlx_put_image_to_window(mlx, mlx_win, info->ground_img,  32 * j,  32 * i);
			if (info->map[i][j] == '1')
				mlx_put_image_to_window(mlx, mlx_win, info->wall_img,  32 * j,  32 * i);
			else if (info->map[i][j] == 'E')
				mlx_put_image_to_window(mlx, mlx_win, info->exit_img,  32 * j,  32 * i);
			else if (info->map[i][j] == 'C')
			{
				mlx_put_image_to_window(mlx, mlx_win, info->coin_img,  32 * j,  32 * i);
			}
			else if (info->map[i][j] == 'P')
			{
				mlx_put_image_to_window(mlx, mlx_win, info->char_img,  32 * j,  32 * i);
			}
			j++;
		}
		i++;
	}
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
		exit(0);
	}
	if (temp < count)
	{
		ft_printf("Moved %d step\n", count);
		mlx_string_put(info->mlx, info->mlx_win,64, 64, 0,"hihihihihi");
	}
		
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

int	main(void)
{
	int		fd;
	t_info	*info;
	int img_width;
	int img_height;

	info = (t_info *)malloc(sizeof(t_info));
	fd = open("map.ber", O_RDONLY);
	if (fd < 0)
		exit(0);
	read_map(fd, info);
	info->mlx = mlx_init();
	init_sprites(info);
	info->mlx_win = mlx_new_window(info->mlx, info->col_size * 32, info->row_size * 32, "so_long");
	// img.img = mlx_new_image(mlx, 1920, 1080);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	info->x = info->start[1] * 32;
	info->y = info->start[0] * 32;
	info->ground_img = mlx_xpm_file_to_image(info->mlx, "./images/grass.xpm",&img_width, &img_height);
	info->wall_img = mlx_xpm_file_to_image(info->mlx, "./images/stone.xpm",&img_width, &img_height);
	info->char_img = mlx_xpm_file_to_image(info->mlx, "./images/down.xpm",&img_width, &img_height);
	info->coin_img = mlx_xpm_file_to_image(info->mlx, "./images/heart.xpm",&img_width, &img_height);
	info->exit_img = mlx_xpm_file_to_image(info->mlx, "./images/door.xpm",&img_width, &img_height);
	ft_printf("%d %d\n",img_width,img_height);
	// mlx_put_image_to_window(mlx, mlx_win, info->ground_img, 32/1080 * 0, 32/1920 * 0);
	// mlx_put_image_to_window(mlx, mlx_win, info->ground_img, 32 * 0, 32 * 1);

	draw_image(info->mlx, info->mlx_win, info);
	mlx_key_hook(info->mlx_win, key_hook, info);
	// mlx_loop_hook(info->mlx_win, loop_hook, info);
	mlx_loop(info->mlx);
	
	return(0);
}

