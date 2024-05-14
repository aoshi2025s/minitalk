/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 02:53:18 by yoaoki            #+#    #+#             */
/*   Updated: 2024/05/07 03:27:32 by yoaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		result;
	int		temp;
	va_list	ap;

	va_start(ap, format);
	if (!format)
		return (0);
	result = 0;
	while (*format)
	{
		temp = 0;
		if (*format == '%')
		{
			temp = ft_put_convert(format, &ap);
			format++;
		}
		else
			temp = ft_putchar_fd(*format, 1);
		if (temp < 0)
			return (-1);
		result += temp;
		format++;
	}
	va_end(ap);
	return (result);
}
