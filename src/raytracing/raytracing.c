/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 20:07:47 by yehara            #+#    #+#             */
/*   Updated: 2025/04/26 21:53:08 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <mlx_util.h>

double	map(double num, double new_min, double new_max, double old_max)
{
	return (((new_max - new_min) * num / old_max) + new_min);
}

double	hit_sphere(t_vec center, double radius, t_vec origin, t_vec dir)
{
	t_vec	oc;
	double	a;
	double	b;
	double	c;
	double	discriminant;
	double	t;

	oc = subtract(origin, center);
	a = dot_product(dir, dir);
	b = 2.0 * dot_product(oc, dir);
	c = dot_product(oc, oc) - radius * radius;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (-1.0);
	t = (-b - sqrt(discriminant)) / (2.0 * a);
	if (t < 1e-4)
	{
		t = (-b + sqrt(discriminant)) / (2.0 * a);
		if (t < 1e-4)
			return (-1.0);
	}
	return (t);
}
/*
oc (origin to center)
*/
double	hit_plane(t_vec point_on_plane, t_vec normal, t_vec origin, t_vec dir)
{
	double	denominator;
	double	t;
	t_vec	diff;

	denominator = dot_product(normal, dir);
	if (fabs(denominator) < 1e-6)
		return (-1.0);
	if (denominator > 0)
		return (-1.0);
	diff = subtract(point_on_plane, origin);
	t = dot_product(normal, diff) / denominator;
	if (t < 1e-4) // if the intersection point is too close to the camera or behind the camera
		return (-1.0);
	return (t);
}
/*
normal: planeの法線ベクトル normal vector（面に対して表方向に直立）
dir: rayの進行方向ベクトル
denominator: normal vectorとrayの方向が平行に近い = 内積が正 = rayがplaneの裏側から来ている
*/

double hit_object(t_vec origin, t_vec dir, t_object *obj)
{
	if (obj->shape == SPHERE)
		return (hit_sphere(obj->center, obj->diameter / 2.0, origin, dir));
	else if (obj->shape == PLANE)
		return (hit_plane(obj->center, obj->normal, origin, dir));
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

int convert_color(t_color color)
{
    int r = (int)color.r;
    int g = (int)color.g;
    int b = (int)color.b;

    return ((r << 16) | (g << 8) | b);
}

void	raytracing(t_mlx *mlx)
{
	t_vec		ray_dir;
	t_vec		ray_origin;
	t_object	*object;
	t_vec 		pixel_pos;
	t_vec		horizontal;
	t_vec		vertical;
	int			x;
	int			y;
	t_camera	*cam;
	double		t;
	double		t_closest;

	cam = &mlx->scene.camera;
	ray_origin = cam->position;
	object = (t_object *)mlx->scene.objects->content;
	horizontal = scale(cam->right, cam->viewport_width);
	vertical = scale(cam->up, cam->viewport_height);
	y = 0;
	while (y < mlx->img.height)
	{
		x = 0;
		while (x < mlx->img.width)
		{
			pixel_pos = add(
                  add(cam->lower_left_corner,
                          scale(horizontal, (double)x / (mlx->img.width - 1))),
                  scale(vertical, (double)y / (mlx->img.height - 1)));
			ray_dir = normalize(subtract(pixel_pos, cam->position));
			t_closest = 1e30;
			t = hit_object(ray_origin, ray_dir, object);
			if (t > 0 && t < t_closest)
				ft_pixel_put(x, y, &mlx->img, convert_color(object->color));
			else
				ft_pixel_put(x, y, &mlx->img, 0x000000); // 黒で背景
			x++;
		}
		y++;
	}
}

// void	raytracing(t_mlx *mlx)
// {
// 	t_vec		ray_dir;
// 	t_vec		ray_origin;
// 	// t_object	*object;
// 	t_vec 		pixel_pos;
// 	t_vec		horizontal;
// 	t_vec		vertical;
// 	int			x;
// 	int			y;
// 	t_camera	*cam;
// 	t_list	    *node;
// 	t_object	*closest_object;

// 	cam = &mlx->scene.camera;
// 	ray_origin = cam->position;
// 	// object = (t_object *)mlx->scene.objects->content;
// 	horizontal = scale(cam->right, cam->viewport_width);
// 	vertical = scale(cam->up, cam->viewport_height);
// 	y = 0;
// 	while (y < mlx->img.height)
// 	{
// 		x = 0;
// 		while (x < mlx->img.width)
// 		{
// 			pixel_pos = add(
//                   add(cam->lower_left_corner,
//                           scale(horizontal, (double)x / (mlx->img.width - 1))),
//                   scale(vertical, (double)y / (mlx->img.height - 1)));
// 			ray_dir = normalize(subtract(pixel_pos, cam->position));
// 			node = mlx->scene.objects;
// 			closest_object = NULL;
// 			while (node)
// 			{
// 				t_object *object = (t_object *)node->content;
// 				if (hit_object(ray_origin, ray_dir, object))
// 				{
// 					closest_object = object;
// 					break ;
// 				}
// 				node = node->next;
// 			}
// 			if (closest_object)
// 				ft_pixel_put(x, y, &mlx->img, convert_color(closest_object->color)); // 赤で描画
// 			else
// 				ft_pixel_put(x, y, &mlx->img, 0x000000); // 黒で背景
// 			x++;
// 		}
// 		y++;
// 	}
// }
