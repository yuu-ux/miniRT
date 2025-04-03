/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:46:47 by ssoeno            #+#    #+#             */
/*   Updated: 2025/04/03 21:34:41 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>
#include <math.h>
#include <mlx_utils.h>

void init_camera(t_camera *cam, int width, int height)
{
    t_vec y_axis = {0, 1, 0};
    
    cam->forward = normalize(cam->forward);
    cam->right = normalize(cross_product(y_axis, cam->forward));
    cam->up = cross_product(cam->forward, cam->right);

    cam->width = width;
    cam->height = height;
    cam->aspect_ratio = (double)width / (double)height;
    cam->scale = tan(cam->fov * 0.5 * M_PI / 180.0);
    
}

t_ray	generate_ray(t_camera *cam, t_mlx *mlx, int x, int y);
{
    t_ray	ray;
	double	viewport_height = 2.0 * tan((cam->fov * M_PI / 180.0) / 2.0);
	double	viewport_width = viewport_height * (double)mlx->width / (double)mlx->height;

	double	u = (2.0 * ((double)x + 0.5) / (double)mlx->width - 1.0) * viewport_width / 2.0;
	double	v = (1.0 - 2.0 * ((double)y + 0.5) / (double)mlx->height) * viewport_height / 2.0;

	t_vec	dir = vec_add(vec_add(cam->forward,
							vec_scale(cam->right, u)),
							vec_scale(cam->up, v));
	ray.origin = cam->position;
	ray.direction = vec_normalize(dir);
	return (ray);
}

/*


1. calculate the viewport size
    Viewport is a virtual screen that the camera sees.
    tan(fov / 2) = viewport_height / distance_to_near_plane
    width = viewport_height * aspect_ratio
    aspect_ratio = viewport_width / viewport_height
2. calculate the ray direction for each pixel(x, y)
    - u = (2 * (x + 0.5) / width - 1) * viewport_width / 2
    - v = (1 - 2 * (y + 0.5) / height) * viewport_height / 2
    ray_direction = forward + right * u + up * v
    where u and v are the coordinates of the pixel on the viewport.
3. normalize the ray direction
4. create a ray struct with the camera position and the ray direction

*/

