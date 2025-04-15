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
#include <mlx_utils.h>
#include <raytracing.h>

int	key_event(int keycode, void *param)
{
	(void)param;
	if (keycode == KEY_ESC)
	{
		exit(EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}

int	close_window(void *param)
{
	(void)param;
	exit(EXIT_SUCCESS);
}

int	main_loop(t_mlx *mlx)
{
	raytracing(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img.img_ptr, 0, 0);
	return (EXIT_SUCCESS);
}
