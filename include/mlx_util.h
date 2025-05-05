/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_util.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:02:02 by ssoeno            #+#    #+#             */
/*   Updated: 2025/04/02 20:29:17 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTIL_H
# define MLX_UTIL_H

# include <mlx.h>
# include <scene.h>

# define KEY_ESC 65307
# define WIDTH 1600
# define HEIGHT 1200

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}			t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
	int		width;
	int		height;
	t_img	img;
	t_scene	*scene;
}			t_mlx;

int			key_event(int keycode, void *param);
int			close_window(void *param);
int			main_loop(t_mlx *mlx);

#endif
