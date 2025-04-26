/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:39:25 by shokosoeno        #+#    #+#             */
/*   Updated: 2025/04/26 16:00:15 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <mlx_util.h>

void setup_camera(t_camera *cam, int img_width, int img_heigt)
{
    double fov_rad;
    t_vec world_up;
    t_vec center;
    t_vec half_width;
    t_vec half_height;
    
    fov_rad = cam->fov * M_PI / 180;
    world_up = (t_vec){0.0, 1.0, 0.0};
    cam->viewport_height = 2.0 * tan(fov_rad / 2.0);
    cam->viewport_width = cam->viewport_height * ((double)img_width / img_heigt);
    cam->forward = cam->orientation;
    cam->right = normalize(cross_product(cam->forward, world_up));
    cam->up = cross_product(cam->right, cam->forward);
    center = add(cam->position, cam->forward);
    half_width = scale(cam->right, cam->viewport_width / 2.0);
    half_height = scale(cam->up, cam->viewport_height / 2.0);
    cam->lower_left_corner = subtract(subtract(center, half_width), half_height);
}

/*
The image plane is placed at a distance of 1 unit from the camera (z = 1)
The forward vector is the direction the camera is looking at (z-axis)
3D normalized orientation vector, in the range [-1,1] for each x, y, z axis:
0.0,0.0,1.0
"word up" is the default up vector (y-axis)
"right" vector is the cross product of forward and world up
*/