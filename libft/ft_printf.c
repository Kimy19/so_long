/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:40:59 by yaekim            #+#    #+#             */
/*   Updated: 2024/04/10 12:48:26 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	check_format(const char *format, va_list ptr, int *len)
{
	int	temp;

	if (*format == 'c')
		print_c(ptr, len);
	else if (*format == 's')
		print_s(ptr, len);
	else if (*format == 'p')
		print_p(ptr, len);
	else if (*format == 'd' || *format == 'i')
		print_di(ptr, len);
	else if (*format == 'u')
		print_u(ptr, len);
	else if (*format == 'x')
		print_x(ptr, len, 0);
	else if (*format == 'X')
		print_x(ptr, len, 1);
	else if (*format == '%')
	{
		temp = write(1, "%", 1);
		if (temp == -1)
			(*len) = -1;
		else
			(*len) += temp;
	}
	return ;
}

int	ft_printf(const char *format, ...)
{
	va_list	ptr;
	int		len;
	int		temp;

	len = 0;
	va_start(ptr, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			check_format(format++, ptr, &len);
			if (len == -1)
				break ;
		}
		else
		{
			temp = write(1, format++, 1);
			if (temp == -1)
				return (-1);
			len++;
		}
	}
	va_end(ptr);
	return (len);
}
