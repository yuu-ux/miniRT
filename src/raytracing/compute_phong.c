/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_phong.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:51:37 by ssoeno            #+#    #+#             */
/*   Updated: 2025/05/02 20:45:24 by ssoeno           ###   ########.fr       */
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
    reflected_dir = subtract(v, scale(n, 2 * dot_product(vector, normal)));
    return (reflected_dir);
}

t_color compute_phone(t_scene *scene, t_vec hit_point, t_vec view_dir)
{
    t_color color;
    t_vec   normal;
    t_vec	light_dir;
    t_vec   reflected_dir;
    double  diffuse;
    double  specular;
    double  ambient;
    double  shininess = 50.0;

    // normalize
    normal = get_normal(scene->object, hit_point);

    // 光の方向を計算（光源位置 - 交点）
    light_dir = normalize(subtract(scene->light.position, hit_point));
    
    // diffuse (Lambert)
    diffuse = fmax(dot_product(normal, light_dir), 0.0);

    // specular (Phong)
    reflected_dir = reflect(scale(light_dir - 1), normal); // R = 2N(L·N) - L
    specular = pow(fmax(dot_product(reflected_dir, normalize(view_dir)), 0.0),
            shiness); // shininess = 50

    color.r = ambient * object_color.r
         + diffuse * scene->light.color.r * (object_color.r / 255.0)
         + specular * scene->light->color.r;
    color.g = ambient * object_color.g
         + diffuse * scene->light.color.g * (object_color.g / 255.0)
         + specular * scene->light->color.g;
    color.b = ambient * object_color.b
         + diffuse * scene->light.color.b * (object_color.b / 255.0)
         + specular * scene->light->color.b;
    
    // Clamp color values to [0, 255]
    color.r = fmin(color.r, 255);
    color.g = fmin(color.g, 255);
    color.b = fmin(color.b, 255);
    return (color);
}
