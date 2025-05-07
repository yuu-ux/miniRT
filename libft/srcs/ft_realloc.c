/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:44:37 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/03/11 21:45:50 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *buf, size_t size)
{
	void	*tmp;
	size_t	buf_len;

	if (buf == NULL)
		return (ft_xmalloc(size));
	buf_len = ft_strlen(buf);
	if (size <= buf_len)
		buf_len = size;
	tmp = ft_xmalloc(size);
	if (tmp == NULL)
	{
		ft_putstr_fd("malloc error\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	ft_strlcpy(tmp, buf, buf_len + 1);
	free(buf);
	return (tmp);
}
