/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:33:47 by yaekim            #+#    #+#             */
/*   Updated: 2024/05/25 19:52:00 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_word(const char *str, const char *word, size_t len)
{
	size_t	n;
	size_t	len_word;

	n = 0;
	len_word = ft_strlen(word);
	while (*str && len > 0)
	{
		if (*str == *word)
		{
			n++;
			if (n == len_word)
				return (1);
			str++;
			word++;
			len--;
		}
		else
			return (0);
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (!haystack)
		return (0);
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len > 0)
	{
		if (check_word(haystack, needle, len))
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (0);
}
