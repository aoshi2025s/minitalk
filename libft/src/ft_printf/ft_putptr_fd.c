/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:27:14 by yoaoki            #+#    #+#             */
/*   Updated: 2024/05/03 16:44:29 by yoaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr_fd(unsigned long long num, int fd)
{
	if (num < 16)
	{
		ft_putchar_fd(BASE[num % 16], fd);
	}
	if (num >= 16)
	{
		ft_putptr_fd(num / 16, 1);
		ft_putchar_fd(BASE[num % 16], fd);
	}
}
