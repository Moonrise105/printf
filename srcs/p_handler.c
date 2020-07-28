/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctobias <ctobias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 14:10:29 by ctobias           #+#    #+#             */
/*   Updated: 2020/07/28 20:21:16 by ctobias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		p_handler(t_flags *flags, va_list argptr)
{
	size_t arg;
	int i;
	int len;

	if (flags->width_sub)
		flags->width = va_arg(argptr, int);
	if (flags->accuracy_sub)
		flags->accuracy = va_arg(argptr, int);
	arg = va_arg(argptr, size_t);
	i = 0;
	len = count_digits_16(arg, flags);
	if (flags->minus)
	{
		i += ft_put_adress(arg, flags);
		i += put_n_symbols(' ', flags->width - i);
	}
	else
	{
		i += put_n_symbols(' ', flags->width - len - i);
		i += ft_put_adress(arg, flags);
	}
	return (i);
}