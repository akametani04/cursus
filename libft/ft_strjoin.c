/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akametan <akametan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 20:41:07 by akametan          #+#    #+#             */
/*   Updated: 2020/07/12 20:41:09 by akametan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	total_len;
	size_t	i;

	i = 0;
	total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr = (char *)malloc(sizeof(char) * total_len);
	if (ptr)
	{
		while (*s1)
		{
			ptr[i] = *s1++;
			i++;
		}
		while (*s2)
		{
			ptr[i] = *s2++;
			i++;
		}
		ptr[i] = '\0';
	}
	return (ptr);
}
