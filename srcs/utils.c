/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctobias <ctobias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 21:23:37 by ctobias           #+#    #+#             */
/*   Updated: 2020/07/28 17:40:15 by ctobias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	init_flags (t_flags *flags)
{
	flags->width_sub = 0;
	flags->accuracy = 0;
	flags->minus = 0;
	flags->null = 0;
	flags->point = 0;
	flags->accuracy_sub = 0;
	flags->width = 0;
	flags->spec = '0';
}
int		min_int (int a, int b)
{
	if (a <= b)
		return (a);
	else 
		return (b);
}

int		ft_putstr(char *str, int max_s)
{
	int i;

	i = 0;
	if (str)
	{
		while (str[i] && i < max_s)
		{
			ft_putchar(str[i]);
			++i;
		}
	}
	else 
	{
		if (max_s >= 6)
			i += write(1, "(null)", 6);
	}
	return (i);
}

int		ft_abs(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

int		count_digits_16(unsigned long long nb)
{
	int size;

	if (!nb)
		return (3);
	size = 1;
	while (nb /= 16)
		size++;
	return (size + 2);
}

int		x_count_digits(unsigned int nb)
{
	int size;

	// if (!nb)
	// 	return (5);
	size = 1;
	while (nb /= 16)
	{
		size++;
	}
		
	return (size);
}

char	*ft_itoa_base(unsigned long long value, int base, int caps)
{
	char	*str;
	int		size;
	char	*tab;
	int		flag;
	unsigned long long		tmp;
	flag = 0;
	size = 0;
	if (!caps)
		tab = "0123456789abcdef";
	else
		tab = "0123456789ABCDEF";
	if (base < 2 || base > 16)
		return (0);
	if (value < 0 && base == 10)
		flag = 1;
	tmp = value;
	while (tmp /= base)
		size++;
	
	size = size + flag + 1;
	str = (char *)malloc(sizeof(char) * size  + 1);
	str[size] = '\0';
	if (flag == 1)
		str[0] = '-';
	while (size > flag)
	{
		str[size - 1] = tab[ft_abs(value % base)];
		size--;
		value /=base;
	}
	return (str);
}

int		ft_put_adress(size_t pointer)
{
	char *str;
	int i;
	
	i = 0;
	// if (!pointer)
	// 	return (write(1, "(nil)", 5));
	if((str = ft_itoa_base(pointer, 16, 0)))
	{
		if (!(write(1, "0x", 2)))
			return (0);
		i = ft_putstr(str, ft_strlen(str));
	}
	return (i + 2);
}

int		max_int(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

int 	ft_putchar(char c)
{
	return(write(1, &c, 1));
}

int 	count_digits(int n) 
{ 
	unsigned int un;

	if (n == 0) 
        return 0;
		
	if (n < 0)
	{
		un = (unsigned int)(n * -1);
		return 1 + count_digits(un / 10);
	}
	else if (n > 0)
	{
		return 1 + count_digits(n / 10);
	}
	return (0);
}

int 	u_count_digits(unsigned int n) 
{ 

	if (n == 0) 
        return 0;
		
	else if (n > 0)
		return 1 + count_digits(n / 10);
	return (0);
} 

void		u_putnbr_stdout(unsigned int n)
{
	if (n > 9)
	{
		putnbr_stdout(n / 10);
	}
	ft_putchar((char)(n % 10 + 48));
}

void		putnbr_stdout(unsigned int nb)
{
	// unsigned int nb;
	
	// if (n < 0)
	// {
	// 	ft_putchar('-');
	// 	nb = (unsigned int)(n * -1);
	// }
	// else
	// {
	// 	nb = (unsigned int)n;
	// }
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