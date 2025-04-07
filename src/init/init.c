/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:04:28 by yehara            #+#    #+#             */
/*   Updated: 2025/04/07 20:14:22 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>
#include <mlx_utils.h>

#define WIDTH 800
#define HEIGHT 600

static void init_scene(t_scene *scene)
{
	ft_memset(scene, -1, sizeof(t_scene));
}

static void init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "miniRT");
	mlx->img.img_ptr = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bpp,
			&mlx->img.line_length, &mlx->img.endian);
	mlx->img.width = WIDTH;
	mlx->img.height = HEIGHT;
}

void	init_data(t_scene *scene, t_mlx *mlx)
{
	init_scene(scene);
	init_mlx(mlx);
}

