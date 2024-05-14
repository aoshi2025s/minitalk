/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 02:42:02 by yoaoki            #+#    #+#             */
/*   Updated: 2024/05/15 04:18:17 by yoaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

# define BASE "0123456789abcdef"
# define BASE_L "0123456789ABCDEF"

int		ft_printf(const char *format, ...);

int		ft_put_convert(const char *str, va_list *ap);
int		ft_print_char(va_list *ap);
int		ft_print_str(va_list *ap);
int		ft_print_ptr(va_list *ap);
int		ft_print_int(va_list *ap);
int		ft_print_uint(va_list *ap);
int		ft_print_hex(va_list *ap);
int		ft_print_hexup(va_list *ap);
int		ft_print_percent(void);

// utils
int		ft_numlen(long long n);
void	ft_putuint_fd(unsigned int n, int fd);
void	ft_putptr_fd(unsigned long long n, int fd);
void	ft_puthex_fd(unsigned int n, int fd);
void	ft_puthexup_fd(unsigned int n, int fd);
#endif
