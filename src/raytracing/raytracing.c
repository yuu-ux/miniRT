/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 20:07:47 by yehara            #+#    #+#             */
/*   Updated: 2025/04/27 16:30:51 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <mlx_util.h>
#include <raytracing.h>

// double	map(double num, double new_min, double new_max, double old_max)
// {
// 	return (((new_max - new_min) * num / old_max) + new_min);
// }

t_vec	generate_ray_dir(t_camera *cam, int x, int y, int width, int height)
{
	t_vec	pixel_pos;
	t_vec	horizontal;
	t_vec	vertical;
	t_vec	ray_dir;

	horizontal = scale(cam->right, cam->viewport_width);
	vertical = scale(cam->up, cam->viewport_height);
	pixel_pos = add(
		add(cam->lower_left_corner,
			scale(horizontal, (double)x / (width - 1))),
		scale(vertical, (double)y / (height - 1)));
	ray_dir = normalize(subtract(pixel_pos, cam->position));
	return (ray_dir);
}

t_object	*find_closest_object(t_scene *scene, t_vec ray_origin, t_vec ray_dir, double *t_closest)
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

void	raytracing(t_mlx *mlx)
{
	t_vec		ray_dir;
	t_vec		ray_origin;
	t_object	*object;
	int			x;
	int			y;
	t_camera	*cam;
	t_object	*closest_object;
	double		t_closest;

	cam = &mlx->scene.camera;
	ray_origin = cam->position;
	object = (t_object *)mlx->scene.objects->content;
	y = 0;
	while (y < mlx->img.height)
	{
		x = 0;
		while (x < mlx->img.width)
		{
			ray_dir = generate_ray_dir(cam, x, y, mlx->img.width, mlx->img.height);
			closest_object = find_closest_object(&mlx->scene, ray_origin, ray_dir, &t_closest);
			render_pixel(&mlx->img, x, y, object);
			x++;
		}
		y++;
	}
}
