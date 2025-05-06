/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xsplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 21:27:43 by yehara            #+#    #+#             */
/*   Updated: 2025/05/06 15:23:33 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static size_t	word_count(char const *s)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (!ft_isspace(*s) && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (ft_isspace(*s))
		{
			in_word = 0;
		}
		s++;
	}
	return (count);
}

static size_t	word_len(char const *s)
{
	size_t	len;

	len = 0;
	while (*s && !ft_isspace(*s))
	{
		len++;
		s++;
	}
	return (len);
}

static void	*allocate_buf(char **buf, int len, int i)
{
	buf[i] = (char *)malloc((len + 1) * sizeof(char));
	if (buf == NULL)
	{
		i--;
		while (0 <= i)
			free(buf[i--]);
		return (NULL);
	}
	return (buf[i]);
}

static char	**split_string(char **buf, char const *s)
{
	int	word_length;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*s)
	{
		while (ft_isspace(*s))
			s++;
		if (*(s) == '\0')
			break ;
		word_length = word_len(s);
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

char	**split_space(char const *s)
{
	size_t	words;
	char	**buf;

	words = 0;
	if (s == NULL)
		return (NULL);
	words = word_count(s);
	buf = (char **)malloc((words + 1) * sizeof(char *));
	if (buf == NULL)
		return (NULL);
	buf = split_string(buf, s);
	if (buf == NULL)
	{
		free(buf);
		return (NULL);
	}
	return (buf);
}
