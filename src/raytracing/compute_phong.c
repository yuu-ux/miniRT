/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_phong.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:51:37 by ssoeno            #+#    #+#             */
/*   Updated: 2025/05/03 17:11:17 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>
#include <raytracing.h>

// 影になった時の色を計算する関数
t_color scale_color(t_color c, double factor)
{
	t_color result;

	result.r = fmin(c.r * factor, 255);
	result.g = fmin(c.g * factor, 255);
	result.b = fmin(c.b * factor, 255);
	return result;
}

t_vec reflect(t_vec vector, t_vec normal)
{
    t_vec reflected_dir;
    reflected_dir = subtract(scale(normal, 2 * dot_product(vector, normal)), vector);
    return (reflected_dir);
}
// R = 2N(L·N) - L

t_color compute_phong(t_scene *scene, t_object *obj, t_vec hit_point, t_vec view_dir)
{
    t_color color;
    t_color object_color = obj->color;
    t_vec   normal;
    t_vec	light_dir;
    t_vec   reflected_dir;
    double  diffuse;
    double  specular;
    double  ambient = scene->ambient.brightness;
    double  shininess = 50.0;

    normal = get_normal(obj, hit_point);
    light_dir = normalize(subtract(scene->light.position, hit_point));
    diffuse = fmax(dot_product(normal, light_dir), 0.0);
    reflected_dir = reflect(scale(light_dir, -1.0), normal);
    specular = pow(fmax(dot_product(reflected_dir, normalize(scale(view_dir, -1))), 0.0),
    shininess);
    color.r = fmin(ambient * object_color.r
         + diffuse * scene->light.color.r * (object_color.r / 255.0)
         + specular * scene->light.color.r, 255);
    color.g = fmin(ambient * object_color.g
         + diffuse * scene->light.color.g * (object_color.g / 255.0)
         + specular * scene->light.color.g, 255);
    color.b = fmin(ambient * object_color.b
         + diffuse * scene->light.color.b * (object_color.b / 255.0)
         + specular * scene->light.color.b, 255);
    return (color);
}
