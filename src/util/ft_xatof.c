/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xatof.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:11:07 by yehara            #+#    #+#             */
/*   Updated: 2025/04/14 19:07:56 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>
#include <util.h>

static bool	is_conversion_float(char *s)
{
	while (*s)
	{
		if (!(ft_isdigit(*s) || (*s == '.') || (*s == '+') || (*s == '-')))
			return (false);
		s++;
	}
	return (true);
}

double	ft_xatof(char *s)
{
	double	res;

	if (!is_conversion_float(s))
		error_exit("input error");
	res = ft_atof(s);
	return (res);
}
