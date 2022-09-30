#include "ft_printf.h"
#include <unistd.h>

void	ft_putpointer_fd(void *p, int fd)
{
	// un dígito de hex son 4 bits
	unsigned long long lp;

	write(1, "0x", 2);
	lp = (unsigned long long)p;
	ft_puthex_fd(lp >> 32, 1, 0);
	ft_puthex_fd(lp, 1, 0);
}