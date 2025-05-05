/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 12:52:08 by ssoeno            #+#    #+#             */
/*   Updated: 2025/05/04 17:54:01 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <raytracing.h>

double	hit_disk(t_object *obj, t_vec center, t_vec origin, t_vec dir)
{
	double	t;
	t_vec	hit_point;

	t = hit_plane(center, obj->normal, origin, dir);
	if (t < 0)
		return (t);
	hit_point = add(origin, scale(dir, t));
	if (length(subtract(hit_point, center)) > obj->diameter / 2)
		return (-1.0);
	return (t);
}

double	hit_cylinder_side(t_object *obj, t_vec origin, t_vec dir)
{
	t_vec		oc;
	double		t;
	t_cyl_side	s;

	oc = subtract(origin, obj->center);
	s.ray_perp = subtract(dir,
			scale(obj->normal, dot_product(dir, obj->normal)));
	s.origin_perp = subtract(oc,
			scale(obj->normal, dot_product(oc, obj->normal)));
	s.q.a = dot_product(s.ray_perp, s.ray_perp);
	s.q.b = 2.0 * dot_product(s.ray_perp, s.origin_perp);
	s.q.c = dot_product(s.origin_perp, s.origin_perp)
		- pow(obj->diameter / 2.0, 2);
	t = solve_quadratic(s.q);
	if (t < 0)
		return (-1.0);
	s.hit_point = add(origin, scale(dir, t));
	s.proj_len = dot_product(obj->normal, subtract(s.hit_point, obj->center));
	if (fabs(s.proj_len) > obj->height / 2)
		return (-1.0);
	else
		return (t);
}

double	hit_cylinder(t_object *obj, t_vec origin, t_vec dir)
{
	t_cyl_hit	hit;

	hit.side = hit_cylinder_side(obj, origin, dir);
	hit.top_center = add(obj->center, scale(obj->normal, obj->height / 2));
	hit.bottom_center = add(obj->center, scale(obj->normal, -obj->height / 2));
	hit.top = hit_disk(obj, hit.top_center, origin, dir);
	hit.bottom = hit_disk(obj, hit.bottom_center, origin, dir);
	hit.t_min = HIT_MAX;
	if (hit.side > 0 && hit.side < hit.t_min)
		hit.t_min = hit.side;
	if (hit.top > 0 && hit.top < hit.t_min)
		hit.t_min = hit.top;
	if (hit.bottom > 0 && hit.bottom < hit.t_min)
		hit.t_min = hit.bottom;
	if (hit.t_min < HIT_MAX)
		return (hit.t_min);
	else
		return (-1.0);
}
