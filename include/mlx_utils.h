/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:02:02 by ssoeno            #+#    #+#             */
/*   Updated: 2025/04/01 17:16:47 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

# include "mlx.h"

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
	int		width;
	int		height;
	t_image	*img;
	t_scene scene;
	t_hook hook;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}			t_mlx;

#endif