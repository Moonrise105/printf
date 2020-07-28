/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctobias <ctobias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 23:45:41 by ctobias           #+#    #+#             */
/*   Updated: 2020/07/28 20:19:39 by ctobias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/ft_printf.h"

int 	decider(t_flags *flags, va_list argptr)
{
	int len;

	len = 0;
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

static void parse_width(const char *str, int *i, t_flags *flags)
{
	while (str[*i] != '\0' && ft_isdigit(str[*i]))
	{
		flags->width = flags->width * 10 + (str[*i] - 48);
		++*i;
	}
	--*i;
}

static void parse_accur(const char *str, int *i, t_flags *flags)
{
	while (str[*i] != '\0' && ft_isdigit(str[*i]))
	{
		flags->accuracy = flags->accuracy * 10 + (str[*i] - 48);
		++*i;
	}
	--*i;
}

static int	parse_flags(char *specifier_list, int *i, 
						t_flags *flags, const char *str)
{
	if (ft_strchr(specifier_list, str[*i]))
		{
			flags->spec = str[*i];
			return (0);
		}
	else if (str[*i] == '-' && !(flags->minus && flags->null))
		flags->minus = 1;
	else if (str[*i] == '0' && !(flags->minus && flags->null) \
		&& !(str[*i - 1] == '.'))
		flags->null = 1;
	else if (str[*i] == '.' && (flags->width || flags->width_sub \
		|| str[*i - 1] == '.' || str[*i - 1] == '%' || str[*i - 1] == '-'))
		flags->point = 1; 
	else if (ft_isdigit(str[*i]) && !flags->width && \
			 ft_strchr("%-0", str[*i - 1]))
		parse_width(str, i, flags);
	else if (ft_isdigit(str[*i]) && str[*i - 1] == '.')
		parse_accur(str, i, flags);
	else if (str[*i] == '*' && str[*i - 1] == '.')
		flags->accuracy_sub = 1; 
	else if (str[*i] == '*' && ft_strchr("%-0", str[*i - 1]))
		flags->width_sub = 1;
	else 
		return (-1);
	return (1);
}

int		ft_parse_spec(const char *str, int *i, t_flags *flags)
{
	char *specifier_list;

	specifier_list = "cspdiuxX%";
	while (str[*i] != '\0')
	{
		if (parse_flags(specifier_list, i, flags, str) <= 0)
			return (0);	
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
			init_flags(flags);
			i = 1;
			ft_parse_spec(str, &i, flags);
			if (flags->spec == '0')
			{
				ft_free(flags);
				return (0);
			}
				
			len += decider(flags, argptr);
			str += i;
		}
		else
			if (write(1, str, 1) < 0)
			{
				ft_free(flags);
				return (-1);
			}
				
			else
				len++;
		str++;
	}
	va_end(argptr);
	ft_free(flags);
	return (len);
}

