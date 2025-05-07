/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 02:07:29 by yehara            #+#    #+#             */
/*   Updated: 2025/02/26 02:08:58 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(char *str)
{
	long	ret;
	int		sign;

	ret = 0;
	sign = 1;
	errno = 0;
	if (!str)
		return ((errno = EINVAL), 1);
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*(str++) == '-')
			sign = -1;
	}
	while (*str)
	{
		if ((ret > LONG_MAX / 10) || (ret == LONG_MAX / 10 && *str > '7'))
			return (LONG_MAX);
		else if ((ret < LONG_MIN / 10) || (ret == LONG_MIN / 10 && *str > '8'))
			return (LONG_MIN);
		ret = ret * 10 + (*(str++) - '0') * sign;
	}
	return (ret);
}
