/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shokosoeno <shokosoeno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 20:07:47 by yehara            #+#    #+#             */
/*   Updated: 2025/04/20 22:35:13 by shokosoeno       ###   ########.fr       */
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
/*
oc (origin to center)
*/

int hit_object(t_vec origin, t_vec dir, t_object *obj)
{
	if (obj->shape == SPHERE)
		return (hit_sphere(obj->center, obj->diameter / 2.0, origin, dir));
	// else if (obj->shape == PLANE)
	// 	;
	// else if (obj->shape == CYLINDER)
	// 	return (hit_cylinder(obj, origin, dir));
	return (0);
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
	t_object	*object;
	double		screen_z;
	double		ndc_x;
	double		ndc_y;

	int x, y;
	ray_origin = mlx->scene.camera.orientation;
	object = (t_object *)mlx->scene.objects->content;
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
			// t_vec horizontal = scale(cam->right, cam->viewport_width);
			// t_vec vertical = scale(cam->up, cam->viewport_height);
			// t_vec target = add(
            //       add(cam->lower_left_corner,
            //               scale(horizontal, (double)x / (mlx.img_width - 1))),
            //       scale(vertical, (double)y / (img_height - 1)));
			// dir = normalize(subtract(target, cam->position));

			// 衝突判定
			// if (hit_sphere(sphere->center, sphere->diameter / 2.0, ray_origin,
			// 		dir))
			if (hit_object(ray_origin, dir, object))
				ft_pixel_put(x, y, &mlx->img, 0xFF0000); // 赤で描画
			else
				ft_pixel_put(x, y, &mlx->img, 0x000000); // 黒で背景
			x++;
		}
		y++;
	}
}
