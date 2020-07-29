/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctobias <ctobias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 01:27:55 by ctobias           #+#    #+#             */
/*   Updated: 2020/07/29 15:30:21 by ctobias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		parse_width(const char *str, int *i, t_flags *flags)
{
	while (str[*i] != '\0' && ft_isdigit(str[*i]))
	{
		flags->width = flags->width * 10 + (str[*i] - 48);
		++*i;
	}
	--*i;
}

static void		parse_accur(const char *str, int *i, t_flags *flags)
{
	flags->accuracy_parsed = 1;
	while (str[*i] != '\0' && ft_isdigit(str[*i]))
	{
		flags->accuracy = flags->accuracy * 10 + (str[*i] - 48);
		++*i;
	}
	--*i;
}

static int		parse_flags(char *specifier_list, int *i,
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
		|| ft_strchr("%.-0", str[*i - 1])))
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

int				ft_parse_spec(const char *str, int *i, t_flags *flags)
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
