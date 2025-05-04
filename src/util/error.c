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

#include <parse.h>
#include <scene.h>
#include <util.h>
#include <mlx_util.h>

int	free_double_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
	return (EXIT_FAILURE);
}

static char	*get_error_message(int status)
{
	if (status == ERR_DUPLICATE)
		return ("Element is duplicated.");
	else if (status == ERR_ARG_COUNT)
		return ("Different number of arguments.");
	else if (status == ERR_BRIGHTNESS_RANGE)
		return ("Brightness is out of valid range.");
	else if (status == ERR_COLOR_FORMAT)
		return ("Invalid color format.");
	else if (status == ERR_VECTOR_FORMAT)
		return ("Invalid vector format.");
	else if (status == ERR_NORMALIZE)
		return ("Normalized vector is required.");
	else if (status == ERR_FOV_RANGE)
		return ("Field of view is out of valid range.");
	return ("Unknown error occurred.");
}

int	error_exit(char *message, int status)
{
	if (status != INVALID_ERR_STATUS)
		message = get_error_message(status);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

void	free_mlx(t_mlx *mlx)
{
	if (mlx->window)
		mlx_destroy_window(mlx->mlx, mlx->window);
	if (mlx->mlx)
	{
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
	}
}

