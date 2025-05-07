/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:41:16 by yehara            #+#    #+#             */
/*   Updated: 2024/09/30 22:02:27 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*str;

	i = 0;
	dst = (unsigned char *)dest;
	str = (unsigned char *)src;
	if (!dst && !str)
		return (NULL);
	if (str < dst)
	{
		while (count--)
		{
			dst[i + count] = str[i + count];
		}
		return (dst);
	}
	while (count--)
	{
		dst[i] = str[i];
		i++;
	}
	return (dst);
}
