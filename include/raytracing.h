/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 20:06:12 by yehara            #+#    #+#             */
/*   Updated: 2025/04/27 16:33:02 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx_util.h>

// hit_object.c
double	hit_sphere(t_vec center, double radius, t_vec origin, t_vec dir);
double	hit_plane(t_vec point_on_plane, t_vec normal, t_vec origin, t_vec dir);
double	hit_object(t_vec ray_origin, t_vec ray_dir, t_object *object);

// raytracing.c
t_vec	generate_ray_dir(t_camera *cam, int x, int y, int width, int height);
void	raytracing(t_mlx *mlx);
t_vec	generate_ray_direction(t_camera *cam, int x, int y, int width, int height);
t_object	*find_closest_object(t_scene *scene, t_vec ray_origin, t_vec ray_dir, double *t_closest);

// render_utils.c
void	render_pixel(t_img *img, int x, int y, t_object *object);
int     convert_color(t_color color);

// setup_camera.c
void	setup_camera(t_camera *cam, int img_width, int img_heigt);