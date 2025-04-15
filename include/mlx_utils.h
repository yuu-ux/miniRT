/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:02:02 by ssoeno            #+#    #+#             */
/*   Updated: 2025/04/02 20:29:17 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

#include <mlx.h>
#include <scene.h>

#define KEY_ESC 65307

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}			t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
	int		width;
	int		height;
	t_img	img;
	t_scene	scene;
}			t_mlx;

#endif

int	key_event(int keycode, void *param);
int	close_window(void *param);
int	main_loop(t_mlx *mlx);

/*
void render(t_mlx *mlx_data)
{
    // 画面サイズ
    int w = mlx_data->width;
    int h = mlx_data->height;

    // 描画ループ
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            t_ray ray = make_ray_from_camera(&mlx_data->scene.camera, x, y, w, h);
            t_color color = trace_ray(&mlx_data->scene, &ray);
            draw_pixel(&mlx_data->img, x, y, color);
        }
    }
}
*/
