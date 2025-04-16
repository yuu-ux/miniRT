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

#include "scene.h"
#include <mlx_util.h>

double	map(double num, double new_min, double new_max, double old_max)
{
	return (((new_max - new_min) * num / old_max) + new_min);
}

int	hit_sphere(t_vec center, double radius, t_vec origin, t_vec dir)
{
	t_vec	oc;
	double	a;
	double	b;
	double	c;
	double	discriminant;

	oc = subtract(origin, center);
	a = dot_product(dir, dir);
	b = 2.0 * dot_product(oc, dir);
	c = dot_product(oc, oc) - radius * radius;
	discriminant = b * b - 4 * a * c;
	return (discriminant >= 0);
}

static void	ft_pixel_put(int x, int y, t_img *img, int color)
{
	size_t	offset;

	offset = (y * img->line_length) + x * (img->bpp / 8);
	*(unsigned int *)(img->addr + offset) = color;
}

void	raytracing(t_mlx *mlx)
{
	t_vec		dir;
	t_vec		ray_origin;
	t_object	*sphere;
	double		screen_z;
	double		ndc_x;
	double		ndc_y;

	int x, y;
	ray_origin = mlx->scene.camera.orientation;
	sphere = (t_object *)mlx->scene.objects->content;
	screen_z = 1.0;
	y = 0;
	while (y < mlx->img.height)
	{
		x = 0;
		while (x < mlx->img.width)
		{
			// スクリーン上のピクセルをNDC → スクリーン座標へ変換
			ndc_x = (2.0 * x / (double)(mlx->img.width - 1)) - 1.0;
			ndc_y = 1.0 - (2.0 * y / (double)(mlx->img.height - 1));
			// レイ方向を作る
			dir = normalize((t_vec){ndc_x, ndc_y, screen_z});
			// 衝突判定（球との交差）
			if (hit_sphere(sphere->center, sphere->diameter / 2.0, ray_origin,
					dir))
				ft_pixel_put(x, y, &mlx->img, 0xFF0000); // 赤で描画
			else
				ft_pixel_put(x, y, &mlx->img, 0x000000); // 黒で背景
			x++;
		}
		y++;
	}
}
