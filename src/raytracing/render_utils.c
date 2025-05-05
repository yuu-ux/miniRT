/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:21:04 by ssoeno            #+#    #+#             */
/*   Updated: 2025/05/05 16:40:04 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <mlx_util.h>
#include <raytracing.h>

void	ft_pixel_put(int x, int y, t_img *img, int color)
{
	size_t	offset;

	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	// x = WIDTH - x;
	// y = HEIGHT - y;
	offset = (y * img->line_length) + x * (img->bpp / 8);
	*(unsigned int *)(img->addr + offset) = color;
}

int	convert_color(t_color color)
{
	int	r;
	int	g;
	int	b;

	r = (int)color.r;
	g = (int)color.g;
	b = (int)color.b;
	return ((r << 16) | (g << 8) | b);
}
