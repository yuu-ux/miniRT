/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:52:27 by yehara            #+#    #+#             */
/*   Updated: 2025/04/15 20:09:43 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>
#include <mlx_util.h>
#include <raytracing.h>
#include <util.h>

int	key_event(int keycode, void *mlx)
{
	t_mlx	*_mlx;

	_mlx = (t_mlx *)mlx;
	if (keycode == KEY_ESC)
	{
		free_mlx(_mlx);
		free_objects(_mlx->scene->objects);
		exit(EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}

int	close_window(void *mlx)
{
	t_mlx	*_mlx;

	_mlx = (t_mlx *)mlx;
	free_mlx(_mlx);
	free_objects(_mlx->scene->objects);
	exit(EXIT_SUCCESS);
}

int	main_loop(t_mlx *mlx)
{
	raytracing(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img.img_ptr, 0, 0);
	return (EXIT_SUCCESS);
}
