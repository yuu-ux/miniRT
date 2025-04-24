/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shokosoeno <shokosoeno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:39:25 by shokosoeno        #+#    #+#             */
/*   Updated: 2025/04/20 22:27:30 by shokosoeno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <mlx_util.h>

void setup_camera(t_camera *cam, int img_width, int img_heigt)
{
    double fov_rad = cam->fov * M_PI / 180;
    cam->viewport_height = 2.0 * tan(fov_rad / 2.0);
    cam->viewport_width = cam->viewport_height * ((double)img_width / img_heigt);
    cam->forward = normalize(cam->orientation);
    t_vec world_up = {0.0, 1.0, 0.0};
    cam->right = normalize(cross_product(cam->forward, world_up));
    cam->up = cross_product(cam->right, cam->forward);
    t_vec center = add(cam->position, cam->forward);
    t_vec half_width = scale(cam->right, cam->viewport_width / 2.0);
    t_vec half_height = scale(cam->up, cam->viewport_height / 2.0);
    cam->lower_left_corner = subtract(subtract(center, half_width), half_height);
}