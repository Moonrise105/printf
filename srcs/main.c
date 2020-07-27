/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctobias <ctobias@student.21.ru>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 23:45:41 by ctobias           #+#    #+#             */
/*   Updated: 2020/07/28 03:22:26 by ctobias          ###   ########.fr       */
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
	len = count_digits_16(arg);
	if (flags->minus)
	{
		i += ft_put_adress(arg);
		while (i < flags->width)
		{
			ft_putchar(' ');
			++i;
		}
	}
	else
	{
		while(i < flags->width - len)
		{
			ft_putchar(' ');
			++i;
		}
		i += ft_put_adress(arg);
	}
	return (i);
}

int 	decider(t_flags *flags, va_list argptr)
{
//	printf("minus=%d\n", flags->minus);
	int len;

	// printf("|accur=%d, width=%d, spec=%c, point = %d, null = %d, minus = %d|\n",
	//  flags->accuracy, flags->width, flags->spec, flags->point, flags->null, flags->minus);
	len = 0;
	if (flags->spec == 'd' || flags->spec == 'i')
	{
		d_ignore_flags(flags);
		return (d_handler(flags, argptr));
	}
			
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
		return (write(1, "%", 1));
}

int		ft_parse_spec(const char *str, int *i, t_flags *flags)
{
	char *specifier_list;

	specifier_list = "cspdiuxX%";
	
	//printf("in=%d\n", flags->accuracy_sub);
	
	while (str[*i] != '\0')
	{
		if (ft_strchr(specifier_list, str[*i]))
		{
			flags->spec = str[*i];
			break;
		}
		else if (str[*i] == ' ')
		{
			++*i;
			continue;
		}
		else if (str[*i] == '-' && !(flags->minus && flags->null))
			flags->minus = 1;
		else if (str[*i] == '0' && !(flags->minus && flags->null) && !(str[*i - 1] == '.'))
			flags->null = 1;
		else if (str[*i] == '.' && (flags->width || flags->width_sub || str[*i - 1] == '.' || str[*i - 1] == '%' || str[*i - 1] == '-'))
			flags->point = 1; 
		else if (ft_isdigit(str[*i]) && flags->width == 0 && (str[*i - 1] == '%' || str[*i - 1] == '0' || str[*i - 1] == '-'))
		{
			while (str[*i] != '\0' && ft_isdigit(str[*i]))
			{
				flags->width = flags->width * 10 + (str[*i] - 48);
				++*i;
			}
			--*i;
		}
		else if (ft_isdigit(str[*i]) && str[*i - 1] == '.')
		{
			while (str[*i] != '\0' && ft_isdigit(str[*i]))
			{
				flags->accuracy = flags->accuracy * 10 + (str[*i] - 48);
				++*i;
			}
			--*i;
		}
		else if (str[*i] == '*' && str[*i - 1] == '.')
			flags->accuracy_sub = 1; 
		else if (str[*i] == '*' && (str[*i - 1] == '%' || str[*i - 1] == '-' || str[*i - 1] == '0'))
			flags->width_sub = 1;
		else 
			return (-1);
		++*i;
	}
	
	return (0);
}

int		ft_printf(const char *str, ...)
{
	int i;
	t_flags *flags;
	va_list argptr;
	int len;
	
	flags = malloc(sizeof(t_flags));
	if (!flags)
		return (0);
	va_start(argptr, str);
	len = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			flags->width_sub = 0;
			flags->accuracy = 0;
			flags->minus = 0;
			flags->null = 0;
			flags->point = 0;
			flags->accuracy_sub = 0;
			flags->width = 0;
			flags->spec = '0';
			i = 1;
			ft_parse_spec(str, &i, flags);
			len += decider(flags, argptr);

			str += i;
			// printf("accur=%d, accur_sub=%d, minus=%d, null=%d, point=%d, spec=%c, width=%d, width_sub=%d\n",
			//  flags->accuracy, flags->accuracy_sub, flags->minus, flags->null, flags->point, flags->spec, flags->width, flags->width_sub);
			
		}
		else
			if (write(1, str, 1) < 0)
				return (-1);
			else
				len++;
		str++;
	}
	va_end(argptr);
	if (flags)
		{
			free(flags);
			flags = NULL;
		}
	return (len);
}

