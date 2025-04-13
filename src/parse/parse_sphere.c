/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 20:16:18 by yehara            #+#    #+#             */
/*   Updated: 2025/04/05 21:42:51 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>
#include <parse.h>

t_object    *parse_sphere(char **elements)
{
	t_object *sphere;

	sphere = ft_xmalloc(sizeof(t_object));
	if (count_array(elements) != 3)
		return (free(sphere), NULL);
	if (parse_vector(elements[0], &sphere->center) == EXIT_FAILURE)
		return (free(sphere), NULL);
    if (parse_color(elements[2], &sphere->color) == EXIT_FAILURE)
        return (free(sphere), NULL);
    // TODO 変換できなかった時のエラー処理を追加する
    // TODO a とか文字列だった場合は-1を返す（ft_atofを修正）
    sphere->diameter = ft_atof(elements[1]);
    sphere->shape = SPHERE;
	return (sphere);
}

