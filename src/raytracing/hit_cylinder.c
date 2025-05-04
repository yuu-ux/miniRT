/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 12:52:08 by ssoeno            #+#    #+#             */
/*   Updated: 2025/05/04 15:08:59 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <raytracing.h>

double hit_disk(t_object *obj, t_vec center, t_vec origin, t_vec dir)
{
    double	t;
    t_vec    hit_point;

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
	t_vec	oc;
	t_vec	ray_perp;
	t_vec	origin_perp;
    t_vec	hit_point;
	t_quadratic	q;
	double	t;
    double  proj_len;

	oc = subtract(origin, obj->center);
	ray_perp = subtract(dir, scale(obj->normal, dot_product(dir, obj->normal)));
	origin_perp = subtract(oc, scale(onj->normal, dot_product(oc, obj->normal)));
	q.a = dot_product(ray_perp, ray_perp);
	q.b = 2.0 * dot_product(ray_perp, origin_perp);
	q.c = dot_product(origin_perp, origin_perp) - pow(obj->diameter / 2.0, 2);
	t = solve_quadratic(q);
    if (t < 0)
        return (-1.0);
    hit_point = add(origin, scale(dir, t));
    proj_len = dot_product(obj->normal, subtract(hit_point, obj->center));
    if (fabs(proj_len) > obj->height / 2)
        return (-1.0);
	return (t);
}

double hit_cylinder(t_object *obj, t_vec origin, t_vec dir)
{
    t_cyl_hit hit;

    hit.side = hit_cylinder_side(obj, origin, dir);
    hit.top_center = add(obj->center, scale(obj->normal, obj->height / 2));
    hit.bottom_center = add(obj->center, scale(obj->normal, -obj->height / 2));
    hit.top = hit_disk(obj, obj.top_center, origin, dir);
    hit.bottom = hit_disk(obj, obj.bottom_center, origin, dir);
    hit.t_min = HIT_MAX;
    if (side > 0 && obj.side < HIT_MAX)
        hit.t_min = hit.side;
    if (top > 0 && obj.top < HIT_MAX)
        hit.t_min = hit.top;
    if (bottom > 0 && obj.bottom < HIT_MAX)
        hit.t_min = hit.bottom;
    if (hit.t_min < HIT_MAX)
        return (hit.t_min);
    else
        return (-1.0);
}
