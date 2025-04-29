/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:45:50 by ssoeno            #+#    #+#             */
/*   Updated: 2025/04/29 16:00:49 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <mlx_util.h>
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
	if (t < 1e-4) // if the intersection point is too close to the camera or behind the camera
		return (-1.0);
	return (t);
}
/*
normal: planeの法線ベクトル normal vector（面に対して表方向に直立）
dir: rayの進行方向ベクトル
denominator: normal vectorとrayの方向が平行に近い = 内積が正 = rayがplaneの裏側から来ている
*/

double solve_quadratic(double a, double b, double c)
{
	double	discriminant;
	double	t;

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

double	hit_sphere(t_vec center, double radius, t_vec origin, t_vec dir)
{
	t_vec	oc;
	double	a;
	double	b;
	double	c;
	double	t;

	oc = subtract(origin, center);
	a = dot_product(dir, dir);
	b = 2.0 * dot_product(oc, dir);
	c = dot_product(oc, oc) - radius * radius;
	t = solve_quadratic(a, b, c);
	return (t);
}

double hit_cylinder(t_vec center, double radius, t_vec normal, t_vec origin, t_vec dir)
{
    t_vec	oc;
    t_vec	ray_perp;
    t_vec   origin_perp;
    double	a;
    double	b;
    double	c;
    double	t;
    
    oc = subtract(origin, center);
    ray_perp = subtract(dir, scale(normal, dot_product(dir, normal)));
    origin_perp = subtract(oc, scale(normal, dot_product(oc, normal)));
    a = dot_product(ray_perp, ray_perp);
    b = 2.0 * dot_product(ray_perp, origin_perp);
    c = dot_product(origin_perp, origin_perp) - radius * radius;
    t = solve_quadratic(a, b, c);
    return (t);
}

double hit_object(t_vec origin, t_vec dir, t_object *obj)
{
	if (obj->shape == SPHERE)
		return (hit_sphere(obj->center, obj->diameter / 2.0, origin, dir));
	else if (obj->shape == PLANE)
		return (hit_plane(obj->center, obj->normal, origin, dir));
	else if (obj->shape == CYLINDER)
		return (hit_cylinder(obj->center, obj->diameter / 2.0, obj->normal, origin, dir));
	return (-1.0);
}
