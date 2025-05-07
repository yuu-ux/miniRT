/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 20:28:44 by yehara            #+#    #+#             */
/*   Updated: 2024/05/16 20:48:21 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_hex(unsigned int hex, int (*up_or_low)(int))
{
	char	*hex_digit;
	int		count;

	count = 0;
	hex_digit = HEX;
	if (hex >= 16)
		count += ft_printf_hex((hex / 16), up_or_low);
	ft_printf_char(up_or_low(hex_digit[hex % 16]));
	return (count + 1);
}
