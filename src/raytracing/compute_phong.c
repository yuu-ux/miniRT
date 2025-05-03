/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_phong.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 17:26:19 by ssoeno            #+#    #+#             */
/*   Updated: 2025/05/03 18:05:30 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>
#include <raytracing.h>

t_color	scale_color(t_color c, double factor)
{
	t_color	result;

	result.r = fmin(c.r * factor, 255);
	result.g = fmin(c.g * factor, 255);
	result.b = fmin(c.b * factor, 255);
	return (result);
}

t_vec	reflect(t_vec l, t_vec n)
{
	t_vec	reflected;

	reflected = subtract(scale(n, 2 * dot_product(l, n)), l);
	return (reflected);
}
// R = 2N(L·N) - L

t_color	compute_phong(t_scene *scene, t_object *obj,
		t_vec hit_point, t_vec view_dir)
{
	t_color	color;
	t_vec	normal;
	t_vec	light_dir;
	t_vec	reflected_dir;
	double	diffuse;
	double	specular;

	normal = get_normal(obj, hit_point);
	light_dir = normalize(subtract(scene->light.position, hit_point));
	diffuse = fmax(dot_product(normal, light_dir), 0.0);
	reflected_dir = reflect(scale(light_dir, -1.0), normal);
	specular = pow(fmax(dot_product(reflected_dir,
					normalize(scale(view_dir, -1))), 0.0), SHININESS);
	color.r = fmin(scene->ambient.brightness * obj->color.r
			+ diffuse * scene->light.color.r * (obj->color.r / 255.0)
			+ specular * scene->light.color.r, 255);
	color.g = fmin(scene->ambient.brightness * obj->color.g
			+ diffuse * scene->light.color.g * (obj->color.g / 255.0)
			+ specular * scene->light.color.g, 255);
	color.b = fmin(scene->ambient.brightness * obj->color.b
			+ diffuse * scene->light.color.b * (obj->color.b / 255.0)
			+ specular * scene->light.color.b, 255);
	return (color);
}
