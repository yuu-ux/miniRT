/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 21:18:27 by yehara            #+#    #+#             */
/*   Updated: 2025/05/06 15:23:30 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include <mlx_util.h>

int		error_exit(char *message, int status, t_mlx *mlx);
int		free_double_array(char **array);
double	ft_xatof(char *s);
void	free_mlx(t_mlx *mlx);
void	free_objects(t_list *objects);
char	**split_space(char const *s);

#endif
