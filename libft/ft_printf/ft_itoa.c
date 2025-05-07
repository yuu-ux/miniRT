/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:41:41 by yehara            #+#    #+#             */
/*   Updated: 2024/10/02 19:37:04 by ebarayuug        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	digits_count(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*buf_secure(int digits, int flag)
{
	char	*buf;

	if (flag)
		buf = (char *)malloc((digits + 1) * sizeof(char));
	else
		buf = (char *)malloc((digits + 2) * sizeof(char));
	if (buf == NULL)
		return (NULL);
	return (buf);
}

static char	*int_to_str(char *result, int digits, int flag, int n)
{
	long long	num;

	if (flag)
	{
		result[digits] = '\0';
		while (n != 0)
		{
			result[--digits] = (n % 10) + '0';
			n /= 10;
		}
	}
	else
	{
		num = n;
		num *= -1;
		result[0] = '-';
		result[digits + 1] = '\0';
		while (num != 0)
		{
			result[digits--] = (num % 10) + '0';
			num /= 10;
		}
	}
	return (result);
}

static char	*zero_processing(void)
{
	char	*result;

	result = (char *)malloc((1 + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[0] = (char)(0 + '0');
	result[1] = '\0';
	return (result);
}

char	*ft_itoa(int n)
{
	int		flag;
	int		digits_counts;
	char	*result;

	flag = 1;
	digits_counts = 0;
	if (n == 0 || n == +0 || n == -0)
	{
		result = zero_processing();
		if (result == NULL)
			return (NULL);
		return (result);
	}
	if (n < 0)
		flag = 0;
	digits_counts = digits_count(n);
	result = buf_secure(digits_counts, flag);
	if (result == NULL)
		return (NULL);
	result = int_to_str(result, digits_counts, flag, n);
	return (result);
}
