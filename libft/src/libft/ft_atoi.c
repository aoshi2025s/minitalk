/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:05:27 by yoaoki            #+#    #+#             */
/*   Updated: 2024/07/19 23:09:00 by yoaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

static int	is_overflow(long long num, int c)
{
	return (num > (LONG_MAX - c) / 10);
}

static int	is_underflow(long long num, int c)
{
	return (num < (LONG_MIN + c) / 10);
}

int	ft_atoi(const char *str)
{
	long long	result;
	int			minus;

	result = 0;
	minus = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		if (is_overflow(result * minus, *str - '0'))
			return ((int)LONG_MAX);
		else if (is_underflow(result * minus, *str - '0'))
			return ((int)LONG_MIN);
		result = result * 10 + (*str++ - '0');
	}
	return (result * minus);
}
