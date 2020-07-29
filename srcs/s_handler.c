/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctobias <ctobias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 22:57:56 by ctobias           #+#    #+#             */
/*   Updated: 2020/07/29 15:20:44 by ctobias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		s_writer(t_flags *flags, int max_s, void *arg)
{
	int i;
	int len;

	len = ft_strlen(arg);
	i = 0;
	if (flags->minus)
	{
		i += ft_putstr(arg, max_s);
		while (i < flags->width)
		{
			ft_putchar(' ');
			++i;
		}
	}
	else
	{
		while (i < flags->width - min_int(max_s, len))
		{
			ft_putchar(flags->null ? '0' : ' ');
			++i;
		}
		i += ft_putstr(arg, max_s);
	}
	return (i);
}

static	void	s_check_stars(t_flags *flags, va_list argptr)
{
	if (flags->width_sub)
	{
		flags->width = va_arg(argptr, int);
		if (flags->width < 0)
		{
			flags->minus = 1;
			flags->width *= -1;
		}
	}
	if (flags->accuracy_sub)
	{
		flags->accuracy = va_arg(argptr, int);
		if (flags->accuracy < 0)
		{
			flags->accuracy = 0;
			flags->point = 0;
		}
	}
}

int				s_handler(t_flags *flags, va_list argptr)
{
	void	*arg;
	int		max_s;

	s_check_stars(flags, argptr);
	arg = va_arg(argptr, void*);
	if (!arg)
		arg = "(null)";
	if (flags->accuracy)
		max_s = flags->accuracy;
	else if (flags->point)
		max_s = 0;
	else
		max_s = ft_strlen(arg);
	return (s_writer(flags, max_s, arg));
}
