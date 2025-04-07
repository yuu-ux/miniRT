/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:01:34 by ssoeno            #+#    #+#             */
/*   Updated: 2025/04/07 20:16:21 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx_utils.h>
#include <scene.h>
#include <util.h>
#include <init.h>
#include <parse.h>

#define KEY_ESC 65307
#define MIN_FILE_LENGTH 4

int	key_event(int keycode, void *param)
{
	(void)param;
	if (keycode == KEY_ESC)
	{
		exit(0);
	}
	return (0);
}

int	close_window(void *param)
{
	(void)param;
	exit(0);
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

static	bool	is_rt_extensions(char *file)
{
	size_t file_len;

	file_len = ft_strlen(file);
	if (file_len < MIN_FILE_LENGTH)
		return (false);
	if (ft_strncmp(file + (file_len - MIN_FILE_LENGTH), ".rt", 4) != EXIT_SUCCESS)
		return (false);
	return (true);
}

int main(int argc, char **argv)
{
	t_scene	scene;
	t_mlx	mlx;

	if (argc != 2)
		return (error_exit("Usage: ./miniRT scene.rt\n"));
	if (is_rt_extensions(argv[1]))
		return (error_exit("Invalid extensions"));
	init_data(&scene, &mlx);
	parse_rt_file(argv[1], &scene);
	for (int y = 250; y < 350; y++)
	{
		for (int x = 350; x < 450; x++)
		{
			put_pixel(&mlx.img, x, y, 0x00FF0000);  // 赤色 (R=255, G=0, B=0)
		}
	}
	mlx_put_image_to_window(mlx.mlx, mlx.window, mlx.img.img_ptr, 0, 0);
	mlx_hook(mlx.window, 2, 1L << 0, key_event, NULL);
	mlx_hook(mlx.window, 17, 1L << 17, close_window, NULL);
	mlx_loop(mlx.mlx);
	return (0);
}

