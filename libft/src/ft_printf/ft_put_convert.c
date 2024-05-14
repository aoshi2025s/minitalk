/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 02:22:54 by yoaoki            #+#    #+#             */
/*   Updated: 2024/05/06 19:05:59 by yoaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_convert(const char *str, va_list *ap)
{
	str++;
	if (*str == 'c')
		return (ft_print_char(ap));
	if (*str == 's')
		return (ft_print_str(ap));
	if (*str == 'p')
		return (ft_print_ptr(ap));
	if (*str == 'd')
		return (ft_print_int(ap));
	if (*str == 'i')
		return (ft_print_int(ap));
	if (*str == 'u')
		return (ft_print_uint(ap));
	if (*str == 'x')
		return (ft_print_hex(ap));
	if (*str == 'X')
		return (ft_print_hexup(ap));
	if (*str == '%')
		return (ft_print_percent());
	return (-1);
}
