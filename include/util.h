/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 21:18:27 by yehara            #+#    #+#             */
/*   Updated: 2025/04/14 18:23:58 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H
# define INVALID_ERR_STATUS -1

# include <mlx_util.h>

int	error_exit(char *message, int status, t_mlx *mlx);
int		free_double_array(char **array);
double	ft_xatof(char *s);
void	free_mlx(t_mlx *mlx);
void	free_objects(t_list	*objects);

#endif
