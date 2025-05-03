/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 20:06:12 by yehara            #+#    #+#             */
/*   Updated: 2025/05/03 18:57:58 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACING_H
# define RAYTRACING_H
# include <mlx_util.h>
# define SHININESS 50.0

typedef struct s_phong_params
{
	t_vec	normal;
	t_vec	light_dir;
	t_vec	reflected_dir;
}			t_phong_params;

// hit_object.c
double	hit_sphere(t_vec center, double radius, t_vec origin, t_vec dir);
double	hit_plane(t_vec point_on_plane, t_vec normal, t_vec origin, t_vec dir);
double	hit_object(t_vec ray_origin, t_vec ray_dir, t_object *object);
double	hit_cylinder(t_vec center, double radius, t_vec normal, t_vec origin, t_vec dir);

// raytracing.c
t_vec	generate_ray_dir(t_camera *cam, int x, int y, t_img *img);
void	raytracing(t_mlx *mlx);
t_vec	generate_ray_direction(t_camera *cam, int x, int y, int width, int height);
t_object	*find_closest_object(t_scene *scene, t_vec ray_origin,
			t_vec ray_dir, double *t_closest);

// render_utils.c
void	render_pixel(t_img *img, int x, int y, t_object *object);
void	ft_pixel_put(int x, int y, t_img *img, int color);
int		convert_color(t_color color);

// setup_camera.c
void	setup_camera(t_camera *cam, int img_w, int img_h);

// compute_phong.c
t_color	compute_phong(t_scene *scene, t_object *obj, t_vec hit_point, t_vec view_dir);
t_color	scale_color(t_color c, double factor);
t_vec	reflect(t_vec vector, t_vec normal);
bool	is_in_shadow(t_vec hit_point, t_light *light, t_scene *scene);

// get_normal.c
t_vec	get_normal(t_object *obj, t_vec hit_point);
t_vec	get_cylinder_normal(t_object *obj, t_vec hit_point);

#endif