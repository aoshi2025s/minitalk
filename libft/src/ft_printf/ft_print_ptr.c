/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:39:44 by yoaoki            #+#    #+#             */
/*   Updated: 2024/05/07 03:30:14 by yoaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptrlen(unsigned long long num)
{
	int	len;

	len = 0;
	while (num >= 16)
	{
		num /= 16;
		len++;
	}
	len++;
	return (len);
}

int	ft_print_ptr(va_list *ap)
{
	unsigned long long	ptr;

	ptr = va_arg(*ap, unsigned long long);
	ft_putstr_fd("0x", 1);
	ft_putptr_fd(ptr, 1);
	return (ft_ptrlen(ptr) + ft_strlen("0x"));
}
