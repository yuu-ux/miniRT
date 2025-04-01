/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:01:34 by ssoeno            #+#    #+#             */
/*   Updated: 2025/04/01 17:01:45 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int main(int argc, char **argv)
{
	// t_data data;
	void	*mlx;
	void	*mlx_win;

	(void)argv;
	if (argc != 2)
		return (ft_printf("Usage: ./miniRT scene.rt\n"));

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	// scene初期化
	// ft_bzero(&data, sizeof(t_data));
	// if (parse_rt_file(argv[1], &data.scene) != 0)
	// 	return (1);
	// render_scene(&data);
	mlx_loop(mlx);
	return (0);
}
