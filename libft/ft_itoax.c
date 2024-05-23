/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoax.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:03:49 by yaekim            #+#    #+#             */
/*   Updated: 2024/04/03 17:00:36 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_size_x(long long num)
{
	int	size;

	size = 0;
	while (num > 0)
	{
		num /= 16;
		size++;
	}
	return (size);
}

int	check_negative_x(long long num)
{
	if (num < 0)
		return (1);
	return (0);
}

void	convert_num(long long num, long long size, char *str, int upper_flag)
{
	char	*hex;
	char	*hex_u;

	hex = "0123456789abcdef";
	hex_u = "0123456789ABCDEF";
	while (num > 0)
	{
		if (upper_flag)
			str[size--] = hex_u[num % 16];
		else
			str[size--] = hex[num % 16];
		num /= 16;
	}
	return ;
}

char	*ft_itoax(unsigned int n, int upper_flag)
{
	unsigned int	num;
	unsigned int	size;
	int				is_negative;
	char			*result;

	if (n == 0)
		return (ft_strdup("0"));
	num = n;
	size = 0;
	is_negative = check_negative_x(num);
	if (is_negative)
		num *= -1;
	size = get_size_x(num) + is_negative;
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (!result)
		return (0);
	result[size--] = 0;
	convert_num(num, size, result, upper_flag);
	if (is_negative)
		result[size] = '-';
	return (result);
}
