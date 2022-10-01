#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include <limits.h>

int	main(int argc, char **argv)
{
	// ft_putnbr(atol(argv[1]));
	// write(1, "\n", 1);
	unsigned char * test;
	test = malloc(1);
	// unsigned long long t = (unsigned long long)test;
	// printf("%llx\n", t);
	// printf("%p\n", test);
	// printf("%x\n", UINT_MAX);
	// ft_printf("something %X %d %d\n", 0xfffffffff,4 ,5);
	// printf("Original:	%p %x %d %i %% %. hola\n", test, test, 012, 012);
	// ft_printf("Mine:		%p %x %d %i %% %h hola\n", test, test, 012, 012);
	ft_printf("mine:		%p \n", 0x602000000010);
	printf("original:	%p \n", 0x602000000010);
	// printf("\n");
	// ft_printf("\n");
}