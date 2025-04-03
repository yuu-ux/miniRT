/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:06:52 by ssoeno            #+#    #+#             */
/*   Updated: 2025/04/03 21:12:21 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H
# include "../libft/include/libft.h"
# include <math.h>

typedef struct s_vec {
	double	x;
	double	y;
	double	z;
}			t_vec;

typedef struct s_color {
	double	r;
	double	g;
	double	b;
}			t_color;

typedef struct s_camera {
	t_vec	position;
	t_vec	forward;　 // orientation
	t_vec	up;
	t_vec	right;
	double	fov;
}			t_camera;
// forward: Normalized vector
// fov: field of view [0〜180]）
// right, upはカメラを動かすならあったほうがいいが、マンダトリーでは不要かも

typedef struct s_light {
	t_vec	position;
	double	brightness;// [0.0〜1.0]
	t_color	color;
}			t_light;

typedef struct s_ambient {
	double	brightness;// [0.0〜1.0]
	t_color	color;
}			t_ambient;

typedef struct s_sphere {
	t_vec	center;
	double	diameter;
	t_color	color;
}			t_sphere;

typedef struct s_plane {
	t_vec	point;
	t_vec	normal;
	t_color	color;
}			t_plane;

typedef struct s_cylinder {
	t_vec	center;
	t_vec	axis; // Normalized vector
	double	diameter;
	double	height;
	t_color	color;
} t_cylinder;

typedef struct s_scene
{
	t_ambient	ambient;
	t_camera	camera;
	t_light		light;
	t_list		*objects;
}				t_scene;

typedef struct s_ray
{
	t_vec	origin;
	t_vec	direction;
}				t_ray;
// origin: camera position
// direction: normalized vector from camera to pixel

t_vec		add(t_vec a, t_vec b);
t_vec		subtract(t_vec a, t_vec b);
t_vec		scale(t_vec a, double s);
t_vec		normalize(t_vec v);
double		length(t_vec v);
double		dot_product(t_vec v1, t_vec v2);
t_vec		cross_product(t_vec v1, t_vec v2);

#endif