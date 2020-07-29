/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctobias <ctobias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 00:35:32 by ctobias           #+#    #+#             */
/*   Updated: 2020/07/29 16:13:19 by ctobias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		count_digits_16(unsigned long long nb, t_flags *flags)
{
	int size;

	if (!nb && flags->point && !flags->accuracy)
		return (2);
	if (!nb)
		return (3);
	size = 1;
	while (nb /= 16)
		size++;
	return (size + 2);
}

int		x_count_digits(unsigned int nb, int n)
{
	int size;

	if (n)
		return (0);
	size = 1;
	while (nb /= 16)
	{
		size++;
	}
	return (size);
}

char	*ft_itoa_base(unsigned long long value, int base, int caps)
{
	char				*str;
	int					size;
	char				*tab;
	unsigned long long	tmp;

	size = 0;
	if (!caps)
		tab = "0123456789abcdef";
	else
		tab = "0123456789ABCDEF";
	if (base < 2 || base > 16)
		return (0);
	tmp = value;
	while (tmp /= base)
		size++;
	size = size + 1;
	str = (char*)malloc(sizeof(char) * size + 1);
	str[size] = '\0';
	while (size > 0)
	{
		str[size - 1] = tab[ft_abs(value % base)];
		size--;
		value /= base;
	}
	return (str);
}

int		ft_put_adress(size_t pointer, t_flags *flags)
{
	char	*str;
	int		i;

	i = 0;
	if (!pointer && flags->point && !flags->accuracy)
		return (write(1, "0x", 2));
	if ((str = ft_itoa_base(pointer, 16, 0)))
	{
		if (!(write(1, "0x", 2)))
		{
			ft_free(str);
			return (0);
		}
		i = ft_putstr(str, ft_strlen(str));
	}
	ft_free(str);
	return (i + 2);
}

int		max_int(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}
