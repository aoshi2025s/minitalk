/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:04:04 by yoaoki            #+#    #+#             */
/*   Updated: 2024/04/18 16:37:26 by yoaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*curr;
	char	target;

	target = (char)c;
	curr = (char *)str;
	while (*curr)
	{
		if (*curr == target)
			return (curr);
		curr++;
	}
	if (target == '\0')
		return (curr);
	return (0);
}
