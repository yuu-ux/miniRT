/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehara <yehara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:24:01 by yehara            #+#    #+#             */
/*   Updated: 2025/04/03 19:26:42 by yehara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

#include <scene.h>
int	parse_ambient(char **elements, t_ambient *ambient);

// util
int	count_array(char **array);
int	parse_color(char **colors, t_color *color);
#endif

