/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_dec.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 22:26:47 by yehara            #+#    #+#             */
/*   Updated: 2024/05/16 16:42:12 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_unsigned_dec(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
		count += ft_printf_unsigned_dec(n / 10);
	ft_printf_char(((n % 10) + '0'));
	return (count + 1);
}
