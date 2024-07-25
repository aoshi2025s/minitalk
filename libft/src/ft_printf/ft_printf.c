/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:57:26 by yoaoki            #+#    #+#             */
/*   Updated: 2024/07/17 20:00:43 by yoaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert(const char *str, va_list *ptr, int *len)
{
	if (*str == 'c')
		put_char((char)va_arg(*ptr, int), len);
	if (*str == 's')
		put_string(va_arg(*ptr, char *), len);
	if (*str == 'p')
	{
		*len += write(1, "0x", 2);
		put_pointer(va_arg(*ptr, unsigned long long), len);
	}
	if (*str == 'd')
		put_digit((long long int)va_arg(*ptr, int), 10, len, HEX_LOWER);
	if (*str == 'i')
		put_digit((long long int)va_arg(*ptr, int), 10, len, HEX_LOWER);
	if (*str == 'u')
		put_digit((long long int)va_arg(*ptr, unsigned int), 10, len,
			HEX_LOWER);
	if (*str == 'x')
		put_digit((long long int)va_arg(*ptr, unsigned int), 16, len,
			HEX_LOWER);
	if (*str == 'X')
		put_digit((long long int)va_arg(*ptr, unsigned int), 16, len,
			HEX_UPPER);
	if (*str == '%')
		*len += write(1, "%", 1);
}

int	ft_printf(const char *fmt, ...)
{
	int		len;
	va_list	ptr;

	len = 0;
	va_start(ptr, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			if (*fmt != '%' && *fmt != 'c' && *fmt != 's' && *fmt != 'd'
				&& *fmt != 'i' && *fmt != 'u' && *fmt != 'x' && *fmt != 'X'
				&& *fmt != 'p')
				return (va_end(ptr), -1);
			convert(fmt, &ptr, &len);
			fmt++;
		}
		else
			len += write(1, fmt++, 1);
	}
	return (va_end(ptr), len);
}
