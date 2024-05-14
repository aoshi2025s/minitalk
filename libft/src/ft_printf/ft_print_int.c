/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 23:13:32 by yoaoki            #+#    #+#             */
/*   Updated: 2024/05/03 00:28:59 by yoaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(va_list *ap)
{
	int	n;

	n = va_arg(*ap, int);
	ft_putnbr_fd(n, 1);
	return (ft_numlen(n));
}
