/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xsplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 21:27:43 by yehara            #+#    #+#             */
/*   Updated: 2025/04/04 21:30:02 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	**ft_xsplit(char const *s, char c)
{
	char	**result;

	result = ft_split(s, c);
	if (result == NULL)
	{
		perror("split error\n");
		exit(EXIT_FAILURE);
	}
	return (result);
}
