/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 21:07:34 by ssoeno            #+#    #+#             */
/*   Updated: 2025/05/02 20:25:28 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>
#include <math.h>

t_vec subtract(t_vec v1, t_vec v2)
{
	t_vec	result;

	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;
	return (result);
}
/*
direction vector = ray origin(camera) - sphere center
t_vec dir = subtract(camera.position, sphere.center)
*/

/*
The ray equation: P(t) = O + tD
where:
- P(t) is the point on the ray at distance t (possibly the hit point)
- O is the origin of the ray (camera position)
- D is the direction of the ray (a normalized vector)
- t is the distance along the ray
When a ray hits an object, 
we can find the hit point by solving for t in the ray equation.
t_vec hit_point = add(camera.position, scale(direction, t));
*/
t_vec add(t_vec v1, t_vec v2)
{
	t_vec	result;

	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;
	return (result);
}

t_vec scale(t_vec v, double scalar)
{
	t_vec	result;

	result.x = v.x * scalar;
	result.y = v.y * scalar;
	result.z = v.z * scalar;
	return (result);
}

double length(t_vec v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

t_vec normalize(t_vec v)
{
	double	len;
	t_vec	result;

	len = length(v);
	if (len == 0)
		return (t_vec){0, 0, 0};
	else
	{
		result.x = v.x / len;
		result.y = v.y / len;
		result.z = v.z / len;
	}
	return (result);
}
/*
In ray tracing, normalize vectors 
to make lighting and intersection math much simpler and stable.
t_vec dir = subtract(pixel_pos, camera_pos);
t_vec unit_dir = normalize(dir);
*/
