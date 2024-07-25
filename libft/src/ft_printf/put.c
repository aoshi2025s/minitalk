/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:33:08 by yoaoki            #+#    #+#             */
/*   Updated: 2024/07/17 20:00:06 by yoaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_char(char c, int *len)
{
	*len += write(1, &c, 1);
}

void	put_string(char *str, int *len)
{
	if (str == NULL)
		str = "(null)";
	while (*str)
		*len += write(1, str++, 1);
}

void	put_pointer(unsigned long long num, int *len)
{
	if (num >= 16)
		put_pointer((num / 16), len);
	*len += write(1, &HEX_LOWER[num % 16], 1);
}

void	put_digit(long long int num, int base, int *len, char *hex)
{
	if (num < 0)
	{
		*len += write(1, "-", 1);
		num = -num;
	}
	if (num >= base)
		put_digit((num / base), base, len, hex);
	*len += write(1, &hex[num % base], 1);
}
