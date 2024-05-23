/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 09:45:20 by yaekim            #+#    #+#             */
/*   Updated: 2023/10/30 14:50:55 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int		is_negative;
	long	num;

	is_negative = 0;
	num = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			is_negative = !is_negative;
		str++;
	}
	while ((*str >= '0' && *str <= '9'))
	{
		num = 10 * num + (*str - '0');
		str++;
	}
	if (is_negative == 1)
		num *= -1;
	return ((int)num);
}
