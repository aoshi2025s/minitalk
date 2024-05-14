/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:31:34 by yoaoki            #+#    #+#             */
/*   Updated: 2024/05/01 20:13:16 by yoaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*curr;

	curr = 0;
	while (*str)
	{
		if (*str == (char)c)
			curr = (char *)str;
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (curr);
}
