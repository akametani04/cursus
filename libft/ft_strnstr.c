/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akametan <akametan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 20:42:28 by akametan          #+#    #+#             */
/*   Updated: 2020/07/12 20:42:30 by akametan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *find, size_t len)
{
	size_t i;
	size_t find_len;
	size_t s_len;

	i = 0;
	find_len = ft_strlen(find);
	s_len = ft_strlen(s);
	if (find_len == 0)
	{
		return ((char *)s);
	}
	while (i + find_len <= len && i + find_len <= s_len)
	{
		if (ft_strncmp(s + i, find, find_len) == 0)
		{
			return (char *)(s + i);
		}
		i++;
	}
	return (NULL);
}
