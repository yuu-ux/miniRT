/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 20:07:47 by yehara            #+#    #+#             */
/*   Updated: 2025/05/04 12:24:21 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <mlx_util.h>
#include <raytracing.h>

t_vec	generate_ray_dir(t_camera *cam, int x, int y, t_img *img)
{
	t_vec	pixel_pos;
	t_vec	horizontal;
	t_vec	vertical;
	t_vec	ray_dir;

	horizontal = scale(cam->right, cam->viewport_width);
	vertical = scale(cam->up, cam->viewport_height);
	pixel_pos = add(
			add(cam->lower_left_corner,
				scale(horizontal, (double)x / fmax(1, img->width - 1))),
			scale(vertical, (double)y / fmax(1, img->height - 1)));
	ray_dir = normalize(subtract(pixel_pos, cam->position));
	return (ray_dir);
}

t_object	*find_closest_object(t_scene *scene,
	t_vec ray_origin, t_vec ray_dir, double *t_closest)
{
	t_list		*obj_list;
	t_object	*closest_object;
	t_object	*current_object;
	double		t;

	obj_list = scene->objects;
	closest_object = NULL;
	*t_closest = 1e30;
	while (obj_list)
	{
		current_object = (t_object *)obj_list->content;
		t = hit_object(ray_origin, ray_dir, current_object);
		if (t > 0 && t < *t_closest)
		{
			*t_closest = t;
			closest_object = current_object;
		}
		obj_list = obj_list->next;
	}
	return (closest_object);
}

bool is_in_shadow(t_vec hit_point, t_light *light, t_scene *scene)
{
	t_vec		light_dir;
	t_vec		shadow_origin;
	double		t;
	t_object	*obj;
	t_list		*list;

	light_dir = normalize(subtract(light->position, hit_point));
	shadow_origin = add(hit_point, scale(light_dir, 1e-4));
	list = scene->objects;
	while (list)
	{
		obj = (t_object *)list->content;
		t = hit_object(shadow_origin, light_dir, obj);
		if (t > 0 && t < length(subtract(light->position, hit_point)))
			return true;
		list = list->next;
	}
	return false;
}

static t_color	trace_pixel(t_mlx *mlx, int x, int y)
{
	t_vec		ray_dir;
	t_vec		ray_origin;
	t_object	*closest_object;
	t_vec		hit_point;
	double		t_closest;

	ray_origin = mlx->scene->camera.position;
	ray_dir = generate_ray_dir(&mlx->scene->camera, x, y, &mlx->img);
	closest_object = find_closest_object(mlx->scene,
			ray_origin, ray_dir, &t_closest);
	if (closest_object)
	{
		hit_point = add(ray_origin, scale(ray_dir, t_closest));
		if (is_in_shadow(hit_point, &mlx->scene->light, mlx->scene))
			return (scale_color(closest_object->color, mlx->scene->ambient.brightness));
		else
			return (compute_phong(mlx->scene, closest_object, hit_point, ray_dir));
	}
	else
		return ((t_color){0, 0, 0});
}

void	raytracing(t_mlx *mlx)
{
	int		x;
	int		y;
	t_color	color;

	y = 0;
	while (y < mlx->img.height)
	{
		x = 0;
		while (x < mlx->img.width)
		{
			x = 0;
			while (x < mlx->img.width)
			{
				color = trace_pixel(mlx, x, y);
				ft_pixel_put(x, y, &mlx->img, convert_color(color));
				x++;
			}
			x++;
		}
		y++;
	}
}
