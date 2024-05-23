/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:03:03 by yaekim            #+#    #+#             */
/*   Updated: 2024/04/10 12:48:23 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_addr_hex(void *ptr, int *len)
{
	char			temp[18];
	char			*hex;
	unsigned long	address;
	int				i;
	int				n;

	address = (unsigned long)ptr;
	hex = "0123456789abcdef";
	i = 17;
	if (address == 0)
		temp[i--] = '0';
	while (address > 0)
	{
		temp[i] = hex[address % 16];
		address /= 16;
		i--;
	}
	temp[i--] = 'x';
	temp[i--] = '0';
	n = write(1, &temp[i + 1], 17 - i);
	if (n != 17 - i)
		(*len) = -1;
	else
		(*len) += n;
}

void	print_p(va_list ptr, int *len)
{
	void	*p;

	p = va_arg(ptr, void *);
	print_addr_hex(p, len);
}

void	print_u(va_list ptr, int *len)
{
	int				i;
	int				temp;
	char			*num;
	unsigned int	n;

	i = 0;
	n = va_arg(ptr, unsigned int);
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

void	print_x(va_list ptr, int *len, int flag)
{
	unsigned int		i;
	unsigned int		n;
	int					temp;
	char				*num;

	i = 0;
	n = va_arg(ptr, unsigned int);
	num = ft_itoax(n, flag);
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
