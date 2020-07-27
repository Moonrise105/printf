/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctobias <ctobias@student.21.ru>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 23:31:06 by ctobias           #+#    #+#             */
/*   Updated: 2020/07/28 02:54:31 by ctobias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		c_handler(t_flags *flags, va_list argptr)
{
	char	arg;
	int		i;

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
		flags->accuracy = va_arg(argptr, int);
	arg = va_arg(argptr, int);
	i = 0;
	if (flags->minus)
	{
		i += ft_putchar(arg);
		i += put_n_symbols(' ', flags->width - i);
	}
	else
	{
		++i;
		i += put_n_symbols(' ', flags->width - i);
		ft_putchar(arg);
	}
	return (i);
}
