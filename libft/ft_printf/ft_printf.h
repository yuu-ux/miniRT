/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarayuuga <ebarayuuga@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:33:38 by yehara            #+#    #+#             */
/*   Updated: 2024/10/02 19:41:08 by ebarayuuga       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# define HEX "0123456789abcdef"

int		ft_tolower(int c);
int		ft_toupper(int c);
void	ft_putchar_fd(char c, int fd);
int		ft_printf(const char *str, ...);
int		ft_printf_unsigned_dec(unsigned int n);
int		ft_printf_char(char c);
int		ft_printf_str(char *s);
int		ft_printf_dec(int num);
int		ft_printf_ptr(void *ptr);
int		ft_printf_hex(unsigned int hex, int (*up_or_low)(int));
char	*ft_itoa(int n);

#endif
