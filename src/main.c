/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:01:34 by ssoeno            #+#    #+#             */
/*   Updated: 2025/04/02 20:31:58 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <mlx_utils.h>
#include <scene.h>

#define KEY_ESC 65307
#define WIDTH 800
#define HEIGHT 600

/**
 * @brief Handles key events.
 *
 * Checks if the received key code is the escape key. If so, it exits the program;
 * otherwise, it ignores the event.
 *
 * @param keycode The code corresponding to the key pressed.
 * @param param Unused parameter.
 *
 * @return Always returns 0.
 */
int	key_event(int keycode, void *param)
{
	(void)param;
	if (keycode == KEY_ESC)
	{
		exit(0);
	}
	return (0);
}

/**
 * @brief Terminates the application when the window is closed.
 *
 * This function serves as a callback for window close events. It immediately
 * terminates the program by calling exit(0). The provided parameter is ignored.
 */
int	close_window(void *param)
{
	(void)param;
	exit(0);
}

/**
 * @brief Draws a pixel on an image at specified coordinates.
 *
 * Computes the address within the image buffer for the pixel at (x, y)
 * and assigns it the given color value. No boundary checks are performed,
 * so ensure that (x, y) is within the valid dimensions of the image.
 *
 * @param img Pointer to the image structure containing pixel data and layout.
 * @param x Horizontal coordinate of the pixel.
 * @param y Vertical coordinate of the pixel.
 * @param color Color value to set at the specified pixel.
 */
void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

/**
 * @brief Entry point for the miniRT graphics application.
 *
 * Initializes the MiniLibX context, creates a window and an image buffer, and draws a red rectangle (RGB: 255, 0, 0)
 * onto the image. It then displays the image in the window, sets up event hooks for keyboard input and window
 * closing, and enters the main event loop. Expects a single command-line argument specifying the scene file.
 *
 * If the argument count is not equal to 2, the function prints a usage message ("Usage: ./miniRT scene.rt") and exits.
 *
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line argument strings, where argv[1] should be the path to the scene file.
 *
 * @return Returns 0 upon normal termination.
 */
int main(int argc, char **argv)
{
	t_mlx	mlx;

	(void)argv;
	if (argc != 2)
		return (ft_printf("Usage: ./miniRT scene.rt\n"));
	mlx.mlx = mlx_init();
	mlx.window = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "miniRT");
	mlx.img.img_ptr = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img_ptr, &mlx.img.bpp,
			&mlx.img.line_length, &mlx.img.endian);
	mlx.img.width = WIDTH;
	mlx.img.height = HEIGHT;

	for (int y = 250; y < 350; y++)
	{
		for (int x = 350; x < 450; x++)
		{
			put_pixel(&mlx.img, x, y, 0x00FF0000);  // 赤色 (R=255, G=0, B=0)
		}
	}
	mlx_put_image_to_window(mlx.mlx, mlx.window, mlx.img.img_ptr, 0, 0);
	// scene初期化
	// ft_bzero(&data, sizeof(t_scene));
	// if (parse_rt_file(argv[1], &scebe.scene) != 0)
	// 	return (1);
	// render_scene(&data);
	mlx_hook(mlx.window, 2, 1L << 0, key_event, NULL);
	mlx_hook(mlx.window, 17, 1L << 17, close_window, NULL);
	mlx_loop(mlx.mlx);
	return (0);
}
