/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctobias <ctobias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 00:42:18 by ctobias           #+#    #+#             */
/*   Updated: 2020/07/29 14:07:53 by ctobias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int		count_digits(int n)
{
	unsigned int un;

	if (n == 0)
		return (0);
	if (n < 0)
	{
		un = (unsigned int)(n * -1);
		return (1 + count_digits(un / 10));
	}
	else if (n > 0)
	{
		return (1 + count_digits(n / 10));
	}
	return (0);
}

int		u_count_digits(unsigned int n)
{
	if (n == 0)
		return (0);
	else if (n > 0)
		return (1 + count_digits(n / 10));
	return (0);
}

void	putnbr_stdout(unsigned int nb)
{
	if (nb > 9)
	{
		putnbr_stdout(nb / 10);
	}
	ft_putchar((char)(nb % 10 + 48));
}

int		put_n_symbols(char c, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putchar(c);
		++i;
	}
	return (i);
}
