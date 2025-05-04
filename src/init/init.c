/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shokosoeno <shokosoeno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:04:28 by yehara            #+#    #+#             */
/*   Updated: 2025/05/04 07:48:40 by shokosoeno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx_util.h>
#include <scene.h>
#include <util.h>
#include <parse.h>

#define INITIAL_VALUE -1

static void	init_scene(t_scene *scene)
{
	scene->ambient.brightness = -1;
	scene->ambient.color.r = -1;
	scene->ambient.color.g = -1;
	scene->ambient.color.b = -1;
	scene->camera.position.x = -1;
	scene->camera.position.y = -1;
	scene->camera.position.z = -1;
	scene->camera.orientation.x = -1;
	scene->camera.orientation.y = -1;
	scene->camera.orientation.z = -1;
	scene->camera.fov = -1;
	scene->light.position.x = -1;
	scene->light.position.y = -1;
	scene->light.position.z = -1;
	scene->light.brightness = -1;
	scene->light.color.r = -1;
	scene->light.color.g = -1;
	scene->light.color.b = -1;
	scene->objects = NULL;
}

static void	init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	// if (mlx->mlx == NULL)
	// 	error_exit("mlx error", INVALID_ERR_STATUS);
	mlx->window = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "miniRT");
	if (mlx->window == NULL)
		error_exit("mlx error", INVALID_ERR_STATUS);
	mlx->img.img_ptr = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	if (mlx->img.img_ptr == NULL)
		error_exit("mlx error", INVALID_ERR_STATUS);
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
