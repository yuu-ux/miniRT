/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:56:49 by yehara            #+#    #+#             */
/*   Updated: 2024/09/30 21:58:45 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char const *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
		{
			in_word = 0;
		}
		s++;
	}
	return (count);
}

static size_t	word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static void	*allocate_buf(char **buf, int len, int i)
{
	buf[i] = (char *)malloc((len + 1) * sizeof(char));
	if (buf[i] == NULL)
	{
		i--;
		while (0 <= i)
			free(buf[i--]);
		return (NULL);
	}
	return (buf[i]);
}

static char	**split_string(char **buf, char const *s, char c)
{
	int	word_length;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*(s) == '\0')
			break ;
		word_length = word_len(s, c);
		if (allocate_buf(buf, word_length, i) == NULL)
			return (NULL);
		while (j < word_length)
		{
			buf[i][j++] = *s++;
		}
		buf[i][j] = '\0';
		j = 0;
		i++;
	}
	buf[i] = NULL;
	return (buf);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**buf;
	char	**result;

	words = 0;
	if (s == NULL)
		return (NULL);
	words = word_count(s, c);
	buf = (char **)malloc((words + 1) * sizeof(char *));
	if (buf == NULL)
		return (NULL);
	result = split_string(buf, s, c);
	if (result == NULL)
	{
		free(buf);
		return (NULL);
	}
	return (result);
}
