/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:18:55 by yaekim            #+#    #+#             */
/*   Updated: 2023/10/15 22:13:44 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dest, const char *restrict src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_dest;
	size_t	len_src;

	i = 0;
	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	j = len_dest;
	while (src[i] != 0 && (len_dest + i + 1) < size)
	{
		dest[j] = src[i];
		j++;
		i++;
	}
	dest[j] = 0;
	if (len_dest > size)
		return (len_src + size);
	return (len_dest + len_src);
}
