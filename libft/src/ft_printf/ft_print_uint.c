/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 01:31:21 by yoaoki            #+#    #+#             */
/*   Updated: 2024/05/03 16:42:37 by yoaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_uint(va_list *ap)
{
	unsigned int	n;

	n = va_arg(*ap, unsigned int);
	ft_putuint_fd(n, 1);
	return (ft_numlen(n));
}

// 12345
// ft_print_uint(12345) -> ft_putchar_fd('5', 1);
// ft_print_uint(1234) -> ft_putchar_fd('4', 1);
// ft_print_uint(123) -> ft_putchar_fd('3', 1);
// ft_print_uint(12) -> ft_putchar_fd('2', 1);
// ft_print_uint(1) -> ft_putchar_fd('1', 1);
