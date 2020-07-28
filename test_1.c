
#include "includes/ft_printf.h"
#include <string.h>
// int ff(t_flags *flags)
// {
// 	printf("%d\n", flags->accuracy);
// 	flags->accuracy = 10;
// }





int main(void)
{
	// int len1 = 0;
	// int len2 = 0;
	// int count = 0;

	// len1 = printf("hello %-*.*d lalalad %-5c\n", 5, 10, 21, '@');
	// len2 = ft_printf("hello %-*.*d lalalad %-5c\n", 5, 10, 21, '@');
	// printf("%d\n", len1);
	// printf("%d\n", len2);


	int count;

	static char	a01;
	static unsigned char a02;
	static short a03;
	static unsigned short a04;
	static int a05;
	static unsigned int a06;
	static long a07;
	static unsigned long a08;
	static long long a09;
	static unsigned long long a10;
	static char *a11;
	static void *a12;
	//printf("%ld\n", arg);
	//count = printf("%3x", 16);
	//printf("%d\n", count);
	// count = ft_printf("%x", 12);
	// printf("%d\n", count);
	char *s_hidden = "hi low\0don't print me lol\0";

	//count = printf("|%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p|\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	// count = printf("%5s", "Fafae");
	// printf("\n%d\n", count);
	count = ft_printf("%5s", "fea");
	//printf("\n%d\n", count);

	//count = ft_printf("|%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p|\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	// count = ft_printf("%d", 4);
	// printf("\n%d\n", count);

	//printf("%ld", (size_t)p);
	//printf("%p", p);
	// char s[2*sizeof(p)];
	// for(int i = 2*sizeof(p)-1; i >= 0; --i)
    // {
    //     s[i] = "0123456789ABCDEF"[p & 0x0F];
    //     p >>= 4;
    // }
    // for(int i = 0; i < 2*sizeof(p); ++i)
    // {
    //     ft_putchar(s[i]);
    // }

	//ft_putuhex(&p);
	// putnbr_c(-5, &count);
	// printf("\n%d\n", count);
	//printf("%10d", 21);
	//printf("%10d", 2);
	//printf("\n%p\n", &p);

	return (0);
}