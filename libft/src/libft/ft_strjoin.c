/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:24:21 by yoaoki            #+#    #+#             */
/*   Updated: 2024/04/23 18:48:33 by yoaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	char	*result;

	if (!s1 || !s2)
		return (0);
	total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	result = (char *)malloc(total_len);
	if (!result)
		return (0);
	ft_strlcpy(result, s1, total_len);
	ft_strlcat(result, s2, total_len);
	return (result);
}
