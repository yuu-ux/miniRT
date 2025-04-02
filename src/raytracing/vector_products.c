/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_products.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 22:01:25 by ssoeno            #+#    #+#             */
/*   Updated: 2025/04/02 22:40:03 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>

double dot_product(t_vec v1, t_vec v2)
{
	double	result;
	result = (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
	return (result);
}

t_vec cross_product(t_vec v1, t_vec v2)
{
	t_vec	result;

	result.x = (v1.y * v2.z) - (v1.z * v2.y);
	result.y = (v1.z * v2.x) - (v1.x * v2.z);
	result.z = (v1.x * v2.y) - (v1.y * v2.x);
	return (result);
}
/*
The cross product of two 3D vectors v1 and v2 
is a new vector that is perpendicular (90°) to both v1 and v2.
To render a 3D scene from a camera, we need
- where the camera is looking (forward, z-axis)
- what is right (x-axis)
- what is up (y-axis)
t_vec forward = normalize(camera.direction);
t_vec right = normalize(cross_product(up, forward));
t_vec up_corrected = cross_product(forward, right);
*/



