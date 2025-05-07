/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 23:06:05 by yehara            #+#    #+#             */
/*   Updated: 2024/09/30 21:59:50 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	is_in_set(char const s1, char const *set)
{
	while (*set)
	{
		if (s1 == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	re_len;
	char	*trim_front;
	char	*trim_end;
	char	*buf;

	if (s1 == NULL || set == NULL)
		return (NULL);
	trim_front = (char *)s1;
	while (*trim_front && is_in_set(*trim_front, set))
		trim_front++;
	trim_end = (char *)s1 + ft_strlen(s1) - 1;
	while (trim_end > trim_front && is_in_set(*trim_end, set))
		trim_end--;
	re_len = trim_end - trim_front + 1;
	buf = malloc((re_len + 1) * sizeof(char));
	if (buf == NULL)
		return (NULL);
	ft_strlcpy(buf, trim_front, re_len + 1);
	buf[re_len] = '\0';
	return (buf);
}
