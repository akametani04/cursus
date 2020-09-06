/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akametan <akametan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 01:15:49 by akametan          #+#    #+#             */
/*   Updated: 2020/08/21 00:15:14 by akametan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# define ERROR -1
# define FIN 0
# define DONE 1

int		get_next_line(int fd, char **line);
int		process_error(char **buf, char **memo);
int		process_zero(char **buf, char **memo, char ***line);
void	read_mid(char **buf, char **tmp, int n, char **memo);
void	leave_memo(char **newline, char **tmp, char **memo);

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strndup(const char *s, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
