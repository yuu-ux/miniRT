/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:54:44 by hmori             #+#    #+#             */
/*   Updated: 2025/03/12 11:36:29 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	erange_turn(int i)
{
	errno = ERANGE;
	return (i);
}

int	ft_atoi(const char *str)
{
	int			sing;
	long int	digit;

	while (ft_isspace(*str))
		str++;
	sing = 1;
	if (*str == '-')
		sing = -1;
	if (*str == '-' || *str == '+')
		str++;
	digit = 0;
	while ('0' <= *str && *str <= '9')
	{
		digit = digit * 10 + sing * (*str - '0');
		if (sing == 1 && digit < 0)
			return (erange_turn((int)LONG_MAX));
		if (sing == -1 && 0 < digit)
			return (erange_turn((int)LONG_MIN));
		str++;
	}
	return ((int)digit);
}
