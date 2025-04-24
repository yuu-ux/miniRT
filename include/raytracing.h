/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shokosoeno <shokosoeno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 20:06:12 by yehara            #+#    #+#             */
/*   Updated: 2025/04/20 22:37:00 by shokosoeno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx_util.h>

void	raytracing(t_mlx *mlx);
void	setup_camera(t_camera *cam, int img_width, int img_heigt);
