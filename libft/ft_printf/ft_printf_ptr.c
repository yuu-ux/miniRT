/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 20:24:07 by yehara            #+#    #+#             */
/*   Updated: 2024/05/16 20:48:43 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_ptr_hex(uintptr_t n)
{
	char	*hex_digit;
	int		count;

	hex_digit = HEX;
	count = 0;
	if (n >= 16)
		count += ft_printf_ptr_hex(n / 16);
	ft_printf_char(hex_digit[(n % 16)]);
	return (count + 1);
}

int	ft_printf_ptr(void *ptr)
{
	int			count;
	uintptr_t	ptr_n;

	count = 2;
	ptr_n = (uintptr_t)ptr;
	write(1, "0x", 2);
	count += ft_printf_ptr_hex(ptr_n);
	return (count);
}
