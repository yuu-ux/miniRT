/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 21:14:45 by yehara            #+#    #+#             */
/*   Updated: 2025/04/04 22:58:02 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>
#include <parse.h>
#include <util.h>


int	free_double_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
	return (EXIT_FAILURE);
}

static char *get_error_message(int status)
{
	if (status == ERR_DUPLICATE)
		return ("要素が重複してます。");
	else if (status == ERR_ARG_COUNT)
		return ("引数の数が不適切");
	else if (status == ERR_BRIGHTNESS_RANGE)
		return ("輝度が有効範囲外です。");
	else if (status == ERR_COLOR_FORMAT)
		return ("色の形式が不正です。");
	else if (status == ERR_VECTOR_FORMAT)
		return ("ベクトルの形式が不正です。");
	else if (status == ERR_NORMALIZE)
		return ("正規化ベクトルが必要です。");
	else if (status == ERR_FOV_RANGE)
		return ("視野角が有効範囲外です。");
	return ("不明なエラーが発生しました。");
}

int	error_exit(char *message, int	status)
{
	if (status == INVALID_ERR_STATUS)
		message = get_error_message(status);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

