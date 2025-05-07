/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:52:31 by yehara            #+#    #+#             */
/*   Updated: 2024/09/30 21:59:53 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	size_t	flen;
	size_t	i;
	char	*buf;

	i = 0;
	if (s == NULL)
		return (0);
	slen = ft_strlen(s);
	if (slen < len)
		flen = slen;
	else
		flen = len;
	while ((i < start) && (s[i] != '\0'))
		i++;
	buf = (char *)malloc((flen + 1) * sizeof(char));
	if (buf == NULL)
		return (NULL);
	ft_strlcpy(buf, s + i, flen + 1);
	return ((char *)buf);
}
