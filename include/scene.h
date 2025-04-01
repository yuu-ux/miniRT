/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:06:52 by ssoeno            #+#    #+#             */
/*   Updated: 2025/04/01 17:15:31 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

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
	t_vec3	position;
	t_vec3	orientation;
	double	fov;
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
	t_list		*lights;
	t_list		*objects;
}				t_scene;

#endif