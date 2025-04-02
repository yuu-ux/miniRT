/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:01:34 by ssoeno            #+#    #+#             */
/*   Updated: 2025/04/02 18:54:44 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <mlx.h>

#define KEY_ESC 65307

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

int main(int argc, char **argv)
{
	// t_data data;
	void	*mlx;
	void	*mlx_win;

	(void)argv;
	if (argc != 2)
		return (ft_printf("Usage: ./miniRT scene.rt\n"));

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 600, "Hello world!");

	for (int y = 250; y < 350; y++)
	{
		for (int x = 350; x < 450; x++)
		{
			mlx_pixel_put(mlx, mlx_win, x, y, 0x00FF0000);  // 赤色 (R=255, G=0, B=0)
		}
	}
	// scene初期化
	// ft_bzero(&data, sizeof(t_scene));
	// if (parse_rt_file(argv[1], &scebe.scene) != 0)
	// 	return (1);
	// render_scene(&data);
	mlx_hook(mlx_win, 2, 1L << 0, key_event, NULL);
	mlx_hook(mlx_win, 17, 1L << 17, close_window, NULL);
	mlx_loop(mlx);
	return (0);
}
