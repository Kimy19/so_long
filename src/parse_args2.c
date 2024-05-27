/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:41:30 by yaekim            #+#    #+#             */
/*   Updated: 2024/05/27 20:02:48 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_map_component(t_info *info, char c, int *count)
{
	if (c == 'C')
		count[0] += 1;
	else if (c == 'E')
		count[1] += 1;
	else if (c == 'P')
		count[2] += 1;
	else if (c == 'X')
		info->enemy_count += 1;
	else if (c != '1' && c != '0' && c != 'X')
		handle_error("Invalid map component");
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
	info->enemy_count = 0;
	while (i < info->row_size)
	{
		j = 0;
		while (info->map[i][j] && info->map[i][j] != '\n')
		{
			count_map_component(info, info->map[i][j], count);
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
			if (info->map[i][0] != '1' || \
				info->map[i][info->col_size - 1] != '1')
				handle_error("Invalid map structure");
		}
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
