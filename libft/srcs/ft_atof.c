/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:15:13 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/17 17:40:51 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	parse_integer_part(char **s, int *sign)
{
	double	integer_part;

	integer_part = 0;
	while (**s == '+' || **s == '-')
	{
		if (**s == '-')
			*sign *= -1;
		(*s)++;
	}
	while (**s && **s != '.')
	{
		integer_part = (integer_part * 10) + (**s - '0');
		(*s)++;
	}
	return (integer_part);
}

static double	parse_fraction_part(char **s)
{
	double	fraction_part;
	double	power;

	fraction_part = 0;
	power = 1;
	if (**s == '.')
		(*s)++;
	while (**s)
	{
		power /= 10;
		fraction_part += (**s - '0') * power;
		(*s)++;
	}
	return (fraction_part);
}

double	ft_atof(char *s)
{
	double	integer_part;
	double	fraction_part;
	int		sign;

	integer_part = 0;
	fraction_part = 0;
	sign = 1;
	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	integer_part = parse_integer_part(&s, &sign);
	fraction_part = parse_fraction_part(&s);
	return (sign * (integer_part + fraction_part));
}
