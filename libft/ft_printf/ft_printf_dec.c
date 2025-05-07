/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 20:31:49 by yehara            #+#    #+#             */
/*   Updated: 2024/05/20 19:17:01 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_dec(int num)
{
	char	*n;
	int		i;

	i = 0;
	n = ft_itoa(num);
	if (!n)
		return (0);
	while (n[i])
	{
		ft_printf_char(n[i]);
		i++;
	}
	free(n);
	return (i);
}
