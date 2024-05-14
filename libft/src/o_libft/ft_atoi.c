/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:05:27 by yoaoki            #+#    #+#             */
/*   Updated: 2024/05/01 22:13:09 by yoaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

static int	is_overflow(long long num, int c)
{
	if (num > LONG_MAX / 10)
		return (1);
	if (num == LONG_MAX / 10 && c > LONG_MAX % 10)
		return (1);
	return (0);
}

static int	is_underflow(long long num, int c)
{
	if (num < LONG_MIN / 10)
		return (1);
	if (num == LONG_MIN / 10 && c > -(LONG_MIN % 10))
		return (1);
	return (0);
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
