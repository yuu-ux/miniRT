/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:52:27 by yehara            #+#    #+#             */
/*   Updated: 2025/05/05 14:09:03 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
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
