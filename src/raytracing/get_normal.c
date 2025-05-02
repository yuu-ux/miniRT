/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 20:25:41 by ssoeno            #+#    #+#             */
/*   Updated: 2025/05/02 20:31:12 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>

t_vec get_cylinder_normal(t_object *obj, t_vec hit_point)
{
    t_vec oc;
    t_vec projected;
    t_vec normal;

    oc = subtract(hit_point, obj->center);
    // ocを軸方向に投影し、z成分を0にする
    // これにより、円筒の側面の法線ベクトルを得る
    projected = scale(obj->normal, dot_product(oc, obj->normal));
    // oc - projected が側面の方向ベクトル（軸に垂直）
    normal = subtract(oc, projected);
    return (normalize(normal));
}

t_vec get_normal(t_object *obj, t_vec hit_point)
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

// hit_pointは、rayとobjectの交点 (ray_origin + t * ray_direction)
