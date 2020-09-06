/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akametan <akametan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 20:40:05 by akametan          #+#    #+#             */
/*   Updated: 2020/07/17 18:39:53 by akametan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			string_cnt(char const *s, char c)
{
	int count;
	int i;

	i = 0;
	count = 0;
	if (!s)
		return (count);
	while (*s && *s == c)
		s++;
	if (!(*s))
		return (count);
	while (s[i])
	{
		if (!c)
			return (1);
		if (s[i] != c && s[i + 1] == c)
			count++;
		if (s[i] != c && s[i + 1] == '\0')
			count++;
		i++;
	}
	return (count);
}

size_t		strlen_c(char const *s, char c)
{
	int count;

	count = 0;
	while (s[count] != c && s[count])
		count++;
	return (count);
}

char		**ft_split(char const *s, char c)
{
	int		str_cnt;
	char	**ans;
	int		i;

	str_cnt = string_cnt(s, c);
	if (!(ans = (char **)malloc(sizeof(char *) * (str_cnt + 1))))
		return (ans);
	i = 0;
	while (i < str_cnt)
	{
		while (*s == c)
			s++;
		ans[i] = ft_substr(s, 0, strlen_c(s, c));
		if (!ans[i])
		{
			while (--i > -1)
				free(ans[i]);
			free(ans);
			return (NULL);
		}
		s += strlen_c(s, c);
		i++;
	}
	ans[i] = NULL;
	return (ans);
}
