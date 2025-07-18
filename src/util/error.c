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

#include <mlx_util.h>
#include <parse.h>
#include <scene.h>
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
	else if (status == ERR_ATOF)
		return ("Failed atof");
	return ("Unknown error occurred.");
}

int	error_exit(char *message, int status, t_mlx *mlx)
{
	if (message == NULL)
		message = get_error_message(status);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	if (mlx)
	{
		free_mlx(mlx);
		if (mlx->scene)
			free_objects(mlx->scene->objects);
	}
	exit(EXIT_FAILURE);
}

void	free_mlx(t_mlx *mlx)
{
	if (mlx->img.img_ptr)
		mlx_destroy_image(mlx->mlx, mlx->img.img_ptr);
	if (mlx->window)
		mlx_destroy_window(mlx->mlx, mlx->window);
	if (mlx->mlx)
	{
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
	}
}

void	free_objects(t_list *objects)
{
	t_list	*temp;

	while (objects)
	{
		temp = objects->next;
		free(objects->content);
		free(objects);
		objects = temp;
	}
}
