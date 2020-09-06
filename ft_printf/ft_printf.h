/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akametan <akametan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 13:12:48 by akametan          #+#    #+#             */
/*   Updated: 2020/08/27 13:44:20 by akametan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>

typedef struct	s_spec
{
	char	flag;
	int		width;
	int		precision;
	char	type;
	bool	dot;
}				t_spec;

int				ft_printf(const char *fmt, ...);

void			init_spec(t_spec *spec);
void			dec_spec(char **str, t_spec *spec, va_list ap);
void			flag_itoa(char c, t_spec *spec, va_list ap, int *val);
void			func_switch(t_spec *spec, va_list ap, int *len);

int				istype(char c);
int				ft_isdigit(int c);
int				ft_strlen(const char *str);
void			put_char (char c, int n, int *len);

int				len_count(long long n);
int				hex_count(long long unsigned n);
int				ui_count(long long unsigned n);
void			integer_output(long long i_num, int *len);
void			num_output(long long unsigned ui_num
				, int *len, char *num, int base);

void			output_c(int c, t_spec *spec, int *len);
void			output_s(const char *str, t_spec *spec, int *len);
void			output_per(t_spec *spec, int *len);
void			output_expect(t_spec *spec, int *len);

void			output_p(void *ph, t_spec *spec, int *len);
void			output_u(unsigned int ui_num, t_spec *spec, int *len);
void			output_x(unsigned int ui_num, t_spec *spec, int *len);

void			flag_i_d(long long i_num
				, t_spec *spec, int *len);
void			output_spec(int *num_len, int *output_len
				, int *prec_len, t_spec *spec);

void			putint_precision(long long i_num, int output_len
				, int num_len, int *len);
void			putint_num(long long i_num, int num_len, int *len);
void			putint_zero(long long i_num, t_spec *spec
				, int *len, int num_len);
void			putint_left(long long i_num, t_spec *spec
				, int *len, int num_len);
void			putint_noflag(long long i_num, t_spec *spec
				, int *len, int num_len);

#endif
