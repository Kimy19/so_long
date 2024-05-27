/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:38:25 by yaekim            #+#    #+#             */
/*   Updated: 2024/05/27 20:03:42 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_enemy_mem(t_info *info)
{
	if (!info->enemy_count)
		return ;
	info->enemy_x = (int *)malloc(sizeof(int) * info->enemy_count);
	info->enemy_y = (int *)malloc(sizeof(int) * info->enemy_count);
	if (!info->enemy_x || !info->enemy_y)
		handle_error(strerror(errno));
}

void	check_map(t_info *info)
{
	check_map_size(info);
	check_wall(info);
	check_map_component(info);
	init_enemy_mem(info);
	init_map_info(info);
	check_path(info);
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

void	check_arg(t_info *info, char *argv[])
{
	char	*str;
	int		i;

	i = 0;
	str = ft_strnstr(ft_strrchr(argv[1], '.'), ".ber", ft_strlen(argv[1]));
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
