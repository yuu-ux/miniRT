/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:39:25 by shokosoeno        #+#    #+#             */
/*   Updated: 2025/05/03 17:57:03 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <mlx_util.h>

void	setup_camera(t_camera *cam, int img_w, int img_h)
{
	double	fov_rad;
	t_vec	world_up;
	t_vec	center;
	t_vec	half_w;
	t_vec	half_h;

	fov_rad = cam->fov * M_PI / 180;
	cam->viewport_height = 2.0 * tan(fov_rad / 2.0);
	cam->viewport_width = cam->viewport_height * ((double)img_w / img_h);
	cam->forward = cam->orientation;
	if (fabs(cam->forward.x) == 0 && fabs(cam->forward.z) == 0)
		world_up = (t_vec){0, 0, 1};
	else
		world_up = (t_vec){0, 1, 0};
	cam->right = normalize(cross_product(cam->forward, world_up));
	cam->up = cross_product(cam->right, cam->forward);
	center = add(cam->position, cam->forward);
	half_w = scale(cam->right, cam->viewport_width / 2.0);
	half_h = scale(cam->up, cam->viewport_height / 2.0);
	cam->lower_left_corner = subtract(subtract(center, half_w), half_h);
}
/*
The image plane is placed at a distance of 1 unit from the camera (z = 1)
The forward vector is the direction the camera is looking at (z-axis)
3D normalized orientation vector, in the range [-1,1] for each x, y, z axis:
0.0,0.0,1.0
"word up" is the default up vector (y-axis)
"right" vector is the cross product of forward and world up
if the camera is looking straight up (0, 1, 0) or down(0, -1, 0), 
the cross product of forward and world up(0, 1, 0) will be (0,0,0)
because these two vectors are parallel
*/
