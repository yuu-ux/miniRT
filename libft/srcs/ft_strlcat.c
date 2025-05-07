/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:50:30 by yehara            #+#    #+#             */
/*   Updated: 2024/09/30 21:59:14 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ds_co;
	size_t	sr_co;
	size_t	i;

	i = 0;
	sr_co = ft_strlen(src);
	if (src == NULL || size == 0)
		return (sr_co);
	ds_co = ft_strlen(dst);
	if (size <= ds_co)
		return (size + sr_co);
	if (size == 0)
		return (sr_co);
	while (src[i] != '\0' && ds_co + i < size - 1)
	{
		dst[ds_co + i] = src[i];
		i++;
	}
	if (ds_co < size)
		dst[ds_co + i] = '\0';
	return (ds_co + sr_co);
}
