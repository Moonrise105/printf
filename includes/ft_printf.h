/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctobias <ctobias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 19:47:35 by ctobias           #+#    #+#             */
/*   Updated: 2020/07/28 20:30:01 by ctobias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
//# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
//# include <stdint.h>
//# include <limits.h>
//int		func(int number, ...);
//int		parser(char *str);


typedef struct s_flags {
	int width;
	int accuracy;
	char spec;
	int null;
	int point;
	int minus;
	int accuracy_sub;
	int width_sub;
	
} t_flags;

int		min_int (int a, int b);
int		ft_parse_spec(const char *str, int *i, t_flags *flags);
int		ft_printf(const char *str, ...);
void		putnbr_stdout(unsigned int nb);
int 	ft_putchar(char c);
int 	count_digits(int n);
int		max_int(int a, int b);
//char	*ft_itoa_base(unsigned long long value, int base, int caps);
int		ft_abs(int nb);
int		ft_put_adress(size_t pointer, t_flags *flags);
int		c_handler(t_flags *flags, va_list argptr);
int 	d_handler(t_flags *flags, va_list argptr);
int		s_handler(t_flags *flags, va_list argptr);
int 	u_handler(t_flags *flags, va_list argptr);
int			x_handler(t_flags *flags, va_list argptr);
int		s_null_handler(t_flags *flags);
int		count_digits_16(unsigned long long nb, t_flags *flags);
int		ft_putstr(char *str, int max_s);
int 	u_count_digits(unsigned int n);
void		u_putnbr_stdout(unsigned int n);
int		put_n_symbols(char c, int n);
int			d_writer(t_flags *flags, char sym, int arg);
int			d_writer(t_flags *flags, char sym, int arg);
void		d_ignore_flags(t_flags *flags);
int		s_writer(t_flags *flags, int max_s, void *arg);
int		s_null_handler(t_flags *flags);
int		s_null_writer(t_flags *flags, int max_s);
int			u_writer_minus(t_flags *flags, char sym, int len, unsigned int arg);
int			u_writer(t_flags *flags, char sym, int len, unsigned int arg);
void		u_ignore_flags(t_flags *flags);
int		x_count_digits(unsigned int nb);
void		x_ignore_flags(t_flags *flags);
int			x_writer(t_flags *flags, char sym, unsigned int arg, int caps);
int			x_writer_minus(t_flags *flags, char sym, unsigned int arg, int caps);
int		p_handler(t_flags *flags, va_list argptr);
int		perc_handler(t_flags *flags, va_list argptr);
char	*ft_itoa_base(unsigned long long value, int base, int caps);
void	init_flags (t_flags *flags);
void	ft_free(void *p);
#endif