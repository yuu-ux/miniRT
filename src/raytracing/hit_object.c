/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:45:50 by ssoeno            #+#    #+#             */
/*   Updated: 2025/05/04 15:09:52 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <raytracing.h>

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
	if (t < 1e-4)
		return (-1.0);
	return (t);
}
/*
normal: perpendicular to the plane
dir: ray direction
denominator:
	if the dot product is 0, the ray is parallel to the plane
	if denominator > 0, the ray is coming from the back side of the plane
if the hit point is too close to the camera or behind the camera (t < 1e-4)
	return -1.0
*/

double	solve_quadratic(t_quadratic q)
{
	double	discriminant;
	double	t;

	discriminant = q.b * q.b - 4 * q.a * q.c;
	if (discriminant < 0)
		return (-1.0);
	t = (-q.b - sqrt(discriminant)) / (2.0 * q.a);
	if (t < 1e-4)
	{
		t = (-q.b + sqrt(discriminant)) / (2.0 * q.a);
		if (t < 1e-4)
			return (-1.0);
	}
	return (t);
}

double	hit_sphere(t_vec center, double radius, t_vec origin, t_vec dir)
{
	t_vec		oc;
	t_quadratic	q;
	double		t;

	oc = subtract(origin, center);
	q.a = dot_product(dir, dir);
	q.b = 2.0 * dot_product(oc, dir);
	q.c = dot_product(oc, oc) - radius * radius;
	t = solve_quadratic(q);
	return (t);
}

double	hit_object(t_vec origin, t_vec dir, t_object *obj)
{
	if (obj->shape == SPHERE)
		return (hit_sphere(obj->center, obj->diameter / 2.0, origin, dir));
	else if (obj->shape == PLANE)
		return (hit_plane(obj->center, obj->normal, origin, dir));
	else if (obj->shape == CYLINDER)
		return (hit_cylinder(obj, origin, dir));
	return (-1.0);
}
