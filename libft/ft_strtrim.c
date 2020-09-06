/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akametan <akametan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 20:43:35 by akametan          #+#    #+#             */
/*   Updated: 2020/07/17 21:27:47 by akametan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	j;
	char	*ptr;

	if (!s1)
		return (NULL);
	if (!set || !(*set))
		return (ft_strdup(s1));
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	if (!(*s1))
	{
		if ((ptr = (char *)malloc(sizeof(char) * 1)))
			*ptr = '\0';
	}
	else
	{
		j = ft_strlen(s1) - 1;
		while (ft_strchr(set, s1[j]))
			j--;
		ptr = ft_substr(s1, 0, j + 1);
	}
	return (ptr);
}
