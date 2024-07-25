/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:25:57 by yoaoki            #+#    #+#             */
/*   Updated: 2024/04/25 06:34:07 by yoaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*result;
	char const	*start_s;
	size_t		s_len;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (start >= s_len || len == 0)
		return (ft_strdup(""));
	if (len > s_len)
		len = s_len;
	result = (char *)malloc(len + 1);
	if (!result)
		return (0);
	start_s = &s[start];
	ft_strlcpy(result, start_s, len + 1);
	return (result);
}
