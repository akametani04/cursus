/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akametan <akametan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 20:42:08 by akametan          #+#    #+#             */
/*   Updated: 2020/07/14 22:37:34 by akametan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (*(s1 + i) == '\0' || *(s2 + i) == '\0')
			break ;
		if (*(s1 + i) != *(s2 + i))
			break ;
		if (i == n - 1)
			break ;
		i++;
	}
	return (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
}
