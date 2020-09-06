/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akametan <akametan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 20:42:54 by akametan          #+#    #+#             */
/*   Updated: 2020/07/15 19:09:25 by akametan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	long long i;

	i = ft_strlen(s);
	while (0 <= i)
	{
		if (*(s + i) == c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
