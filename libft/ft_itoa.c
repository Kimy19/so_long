/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:33:03 by yaekim            #+#    #+#             */
/*   Updated: 2024/04/01 12:57:10 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_size(long long num)
{
	int	size;

	size = 0;
	while (num > 0)
	{
		num /= 10;
		size++;
	}
	return (size);
}

int	check_negative(long long num)
{
	if (num < 0)
		return (1);
	return (0);
}

char	*ft_itoa(long long n)
{
	long long	num;
	long long	size;
	int			is_negative;
	char		*result;

	if (n == 0)
		return (ft_strdup("0"));
	num = n;
	size = 0;
	is_negative = check_negative(num);
	if (is_negative)
		num *= -1;
	size = get_size(num) + is_negative;
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (!result)
		return (0);
	result[size--] = 0;
	while (num > 0)
	{
		result[size--] = num % 10 + '0';
		num /= 10;
	}
	if (is_negative)
		result[size] = '-';
	return (result);
}
