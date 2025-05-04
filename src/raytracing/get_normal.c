/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 20:25:41 by ssoeno            #+#    #+#             */
/*   Updated: 2025/05/04 14:32:37 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>

t_vec	get_cylinder_normal(t_object *obj, t_vec hit_point)
{
	t_vec	oc;
	t_vec	projected;
	t_vec	normal;
	double	proj_len;

	oc = subtract(hit_point, obj->center);
	projected = scale(obj->normal, dot_product(oc, obj->normal));
	proj_len = dot_product(oc, obj->normal);
	if (fabs(proj_len - obj->height / 2.0) < 1e-4) // top
		return (obj->normal);
	if (fabs(proj_len + obj->height / 2.0) < 1e-4) // bottom
		return (scale(obj->normal, -1.0));
	else
		normal = subtract(oc, projected);
	return (normalize(normal));
}
// oc - projected is perpendicular to the axis of the cylinder

t_vec	get_normal(t_object *obj, t_vec hit_point)
{
	t_vec	result;

	if (obj->shape == SPHERE)
		result = normalize(subtract(hit_point, obj->center));
	else if (obj->shape == PLANE)
		result = obj->normal;
	else if (obj->shape == CYLINDER)
		result = get_cylinder_normal(obj, hit_point);
	else
		result = (t_vec){0, 0, 0};
	return (result);
}
// hit_point = ray_origin + t * ray_direction)
