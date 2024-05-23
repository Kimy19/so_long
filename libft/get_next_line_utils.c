/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:25:23 by yaekim            #+#    #+#             */
/*   Updated: 2024/05/10 13:49:03 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	check_line(char *str)
{
	long long	count;

	count = 0;
	if (!str)
		return (-1);
	while (*str)
	{
		count++;
		if (*str == '\n')
			return (count);
		str++;
	}
	return (-1);
}

size_t	ft_strlen(char const *str)
{
	size_t	count;

	count = 0;
	if (!str)
		return (0);
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}

char	*ft_strdup(const char *s1)
{
	unsigned int		len;
	unsigned int		i;
	char				*temp;

	i = 0;
	len = ft_strlen(s1);
	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (NULL);
	while (s1[i])
	{
		temp[i] = s1[i];
		i++;
	}
	temp[i] = 0;
	return ((char *)temp);
}

void	join_str(char **str, char *buff)
{
	char	*temp;
	char	*temp2;
	size_t	i;

	i = 0;
	if (!*str)
	{
		*str = ft_strdup(buff);
		return ;
	}
	temp = *str;
	temp2 = *str;
	*str = (char *)malloc((ft_strlen(*str) + ft_strlen(buff) + 1));
	if (!*str)
	{
		free(temp);
		return ;
	}
	while (*temp2)
		(*str)[i++] = *(temp2++);
	while (*buff)
		(*str)[i++] = *(buff++);
	(*str)[i] = 0;
	free(temp);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	i = 0;
	src_len = ft_strlen(src);
	while (src[i] != 0 && i + 1 < size)
	{
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
		dest[i] = 0;
	return (src_len);
}
