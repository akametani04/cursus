/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akametan <akametan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 01:15:44 by akametan          #+#    #+#             */
/*   Updated: 2020/08/01 16:56:33 by akametan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	strlen;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	strlen = ft_strlen(s);
	while (i <= strlen)
	{
		if (*s == c)
			return ((char *)s);
		s++;
		i++;
	}
	return (NULL);
}

char	*ft_strndup(const char *s, size_t len)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr)
	{
		while (s && i < len)
		{
			ptr[i] = s[i];
			i++;
		}
		ptr[i] = '\0';
	}
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*ptr;
	size_t	i;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	if ((ptr = (char *)malloc(sizeof(char) * (len + 1))))
	{
		while (s1 && *s1)
		{
			ptr[i] = *s1;
			s1++;
			i++;
		}
		while (s2 && *s2)
		{
			ptr[i] = *s2;
			s2++;
			i++;
		}
		ptr[i] = '\0';
	}
	return (ptr);
}
