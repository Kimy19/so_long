/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:00:13 by yaekim            #+#    #+#             */
/*   Updated: 2023/10/16 15:43:27 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_number(int i, int fd, int num[])
{
	while (i > 0)
	{
		i--;
		write(fd, &num[i], 1);
	}
}

int	check_neg(int n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		return (1);
	}
	return (0);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		num[10];
	int		i;
	int		is_negative;

	i = 0;
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	is_negative = check_neg(n, fd);
	while (n != 0)
	{	
		if (is_negative)
			num[i] = n % 10 * -1 + '0';
		else
			num[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	print_number(i, fd, num);
}
