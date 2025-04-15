/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 20:07:47 by yehara            #+#    #+#             */
/*   Updated: 2025/04/15 20:08:47 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx_util.h>


void	raytracing(t_mlx *mlx)
{
	t_color pixel_color;
	t_vec ray_direction;
	int	x;
	int y;

	y = 0;
	while (y < mlx->img.height)
	{
		x = 0;
		while (x < mlx->img.width)
		{
			// 例の方向を求める
			ray_direction = calculate_ray_direction(*mlx, x, y);
			// ピクセルの色を求める
			pixel_color = trace_ray(mlx, mlx->scene->camera.position, ray_direction);
			// ピクセルの色をセットする
			set_pixel_color(&mlx->img, x, y, pixel_color);
			x++;
		}
		y++;
	}
}
