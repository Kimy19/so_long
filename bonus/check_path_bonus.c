/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:44:14 by yaekim            #+#    #+#             */
/*   Updated: 2024/05/28 15:55:43 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"


void	move_spot(int *tx, int *ty, int *spot, int i)
{
	const int	dx[4] = {1, -1, 0, 0};
	const int	dy[4] = {0, 0, 1, -1};

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
		if (info->map[tx][ty] == '1' || \
			info->map[tx][ty] == 'X' || visit[tx][ty] == 1)
			continue ;
		if (info->map[tx][ty] == 'C')
			*count += 1;
		visit[tx][ty] = 1;
		temp[0] = tx;
		temp[1] = ty;
		dfs(info, temp, count, visit);
	}
}

void	init_visit(t_info *info, int **visit)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
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
}

void	check_path(t_info *info)
{
	int	count;
	int	**visit;
	int	spot[2];

	visit = (int **)malloc(sizeof(int *) * info->row_size);
	if (!visit)
		handle_error(strerror(errno));
	init_visit(info, visit);
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
