/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akametan <akametan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 20:31:40 by akametan          #+#    #+#             */
/*   Updated: 2020/07/13 23:47:04 by akametan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	convert_c(int x)
{
	return (x + '0');
}

int		len_count(int n)
{
	int count;

	count = 0;
	if (n == -2147483648)
		return (11);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (0 < n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		n_len;
	char	*ptr;

	n_len = len_count(n);
	if (!(ptr = (char *)malloc((n_len + 1) * sizeof(char))))
		return (NULL);
	ptr[n_len] = '\0';
	if (n == -2147483648)
	{
		ptr[--n_len] = '8';
		n = -214748364;
	}
	if (n < 0)
	{
		ptr[0] = '-';
		n *= -1;
	}
	n_len--;
	while (0 <= n_len && ptr[n_len] != '-')
	{
		ptr[n_len] = convert_c(n % 10);
		n /= 10;
		n_len--;
	}
	return (ptr);
}
