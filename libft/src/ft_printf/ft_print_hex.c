/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 21:18:55 by yoaoki            #+#    #+#             */
/*   Updated: 2024/05/04 04:32:06 by yoaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexlen(unsigned int num)
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

int	ft_print_hex(va_list *ap)
{
	unsigned int	num;

	num = va_arg(*ap, unsigned int);
	ft_puthex_fd(num, 1);
	return (ft_hexlen(num));
}

int	ft_print_hexup(va_list *ap)
{
	unsigned int	num;

	num = va_arg(*ap, unsigned int);
	ft_puthexup_fd(num, 1);
	return (ft_hexlen(num));
}
