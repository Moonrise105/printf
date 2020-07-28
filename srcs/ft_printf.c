/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctobias <ctobias@student.21.ru>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 23:45:41 by ctobias           #+#    #+#             */
/*   Updated: 2020/07/29 02:29:25 by ctobias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		decider(t_flags *flags, va_list argptr)
{
	if (flags->spec == 'd' || flags->spec == 'i')
		return (d_handler(flags, argptr));
	else if (flags->spec == 'c')
		return (c_handler(flags, argptr));
	else if (flags->spec == 'p')
		return (p_handler(flags, argptr));
	else if (flags->spec == 's')
		return (s_handler(flags, argptr));
	else if (flags->spec == 'x' || flags->spec == 'X')
		return (x_handler(flags, argptr));
	else if (flags->spec == 'u')
		return (u_handler(flags, argptr));
	else if (flags->spec == '%')
		return (perc_handler(flags, argptr));
	return (0);
}

static int		perc_parse(t_flags *flags, const char *str,
							int *i, va_list argptr)
{
	init_flags(flags);
	*i = 1;
	ft_parse_spec(str, i, flags);
	if (flags->spec == '0')
	{
		ft_free(flags);
		va_end(argptr);
		return (-1);
	}
	return (0);
}

static int		sym_parse(t_flags *flags, const char *str,
							int *len, va_list argptr)
{
	if (write(1, str, 1) < 0)
	{
		ft_free(flags);
		va_end(argptr);
		return (-1);
	}
	else
		(*len)++;
	return (0);
}

static void		end_free(t_flags *flags, va_list argptr)
{
	va_end(argptr);
	ft_free(flags);
}

int				ft_printf(const char *str, ...)
{
	int			i;
	t_flags		*flags;
	va_list		argptr;
	int			len;

	if (!(flags = malloc(sizeof(t_flags))))
		return (0);
	va_start(argptr, str);
	len = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			if (perc_parse(flags, str, &i, argptr) < 0)
				return (0);
			len += decider(flags, argptr);
			str += i;
		}
		else if (sym_parse(flags, str, &len, argptr) < 0)
			return (0);
		str++;
	}
	end_free(flags, argptr);
	return (len);
}
