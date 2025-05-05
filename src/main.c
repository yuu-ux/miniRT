/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:01:34 by ssoeno            #+#    #+#             */
/*   Updated: 2025/05/01 17:49:47 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <init.h>
#include <mlx_util.h>
#include <parse.h>
#include <raytracing.h>
#include <scene.h>
#include <util.h>

#define MIN_FILE_LENGTH 4
#define EXTENSIONS_NUM 3

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

static bool	is_rt_extensions(char *file)
{
	size_t	file_len;

	file_len = ft_strlen(file);
	if (file_len < MIN_FILE_LENGTH)
		return (false);
	if (ft_strncmp(file + (file_len - EXTENSIONS_NUM), ".rt",
			EXTENSIONS_NUM) != EXIT_SUCCESS)
		return (false);
	return (true);
}

int	main(int argc, char **argv)
{
	t_scene	scene;
	t_mlx	mlx;

	if (argc != 2)
		return (error_exit("Usage: ./miniRT scene.rt\n", EXIT_FAILURE, NULL));
	if (!is_rt_extensions(argv[1]))
		return (error_exit("Invalid extensions", EXIT_FAILURE, NULL));
	init_data(&scene, &mlx);
	parse_rt_file(argv[1], &scene, &mlx);
	setup_camera(&scene.camera, mlx.img.width, mlx.img.height);
	mlx.scene = &scene;
	raytracing(&mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.window, mlx.img.img_ptr, 0, 0);
	mlx_hook(mlx.window, 2, 1L << 0, key_event, &mlx);
	mlx_hook(mlx.window, 17, 1L << 17, close_window, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
