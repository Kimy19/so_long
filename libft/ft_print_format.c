/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:46:11 by yaekim            #+#    #+#             */
/*   Updated: 2024/04/10 12:48:25 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_c(va_list ptr, int *len)
{
	char	c;
	int		temp;

	c = va_arg(ptr, int);
	temp = write(1, &c, 1);
	if (temp == -1)
		(*len) = -1;
	else
		(*len) += temp;
}

void	print_s(va_list ptr, int *len)
{
	char	*s;
	int		temp;

	s = va_arg(ptr, char *);
	if (!s)
	{
		temp = write(1, "(null)", 6);
		if (temp != 6)
			(*len) = -1;
		else
			(*len) += temp;
		return ;
	}
	while (*s)
	{
		temp = write(1, s, 1);
		if (temp == -1)
		{
			(*len) = -1;
			return ;
		}
		(*len)++;
		s++;
	}
}

void	print_di(va_list ptr, int *len)
{
	int				i;
	int				n;
	int				temp;
	char			*num;

	i = 0;
	n = va_arg(ptr, int);
	num = ft_itoa(n);
	if (!num)
	{
		*len = -1;
		return ;
	}
	while (num[i])
	{
		temp = write(1, &num[i++], 1);
		if (temp == -1)
		{	
			(*len) = -1;
			free(num);
			return ;
		}
		(*len)++;
	}
	free(num);
}
