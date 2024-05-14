/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:05:15 by yoaoki            #+#    #+#             */
/*   Updated: 2024/04/24 23:23:17 by yoaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	count;

	if (!haystack && !len)
		return (0);
	if (!(*needle))
		return ((char *)haystack);
	count = 0;
	while (*haystack && count < len)
	{
		if (ft_strncmp(haystack, needle, ft_strlen(needle)) == 0)
		{
			if (count + ft_strlen(needle) > len)
				return (0);
			else
				return ((char *)haystack);
		}
		haystack++;
		count++;
	}
	return (0);
}
