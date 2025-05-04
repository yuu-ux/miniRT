/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:06:52 by ssoeno            #+#    #+#             */
/*   Updated: 2025/05/04 15:06:00 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H
# include "../libft/include/libft.h"
# include <math.h>
#include <stdbool.h>

typedef enum e_shape {
	SPHERE,
	PLANE,
	CYLINDER
} t_shape;

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
	t_vec	orientation;
	double	fov;
	t_vec	forward;
	t_vec	right;
	t_vec	up;
	double	viewport_width;
	double	viewport_height;
	t_vec	lower_left_corner;
}			t_camera;
// 視線の方向（正規化）
// fov 視野角（[0〜180]）

typedef struct s_light {
	t_vec	position;
	double	brightness;// [0.0〜1.0]
	t_color	color;
}			t_light;

typedef struct s_ambient {
	double	brightness;// [0.0〜1.0]
	t_color	color;
}			t_ambient;

typedef struct s_object {
    t_shape shape;
	t_vec	center;
	t_vec	normal;
	double	diameter;
	double	height;
	t_color	color;
} t_object;

typedef struct s_scene
{
	t_ambient	ambient;
	t_camera	camera;
	t_light		light;
	t_list		*objects;
}				t_scene;

t_vec		add(t_vec a, t_vec b);
t_vec		subtract(t_vec a, t_vec b);
t_vec		scale(t_vec a, double s);
t_vec		normalize(t_vec v);
double		length(t_vec v);
double		dot_product(t_vec v1, t_vec v2);
t_vec		cross_product(t_vec v1, t_vec v2);

#endif
