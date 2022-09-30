#include "ft_printf.h"
#include <unistd.h>

int	ft_putpointer_fd(void *p, int fd)
{
	// un dígito de hex son 4 bits
	unsigned long long lp;
	int counter;

	counter = 2;
	write(1, "0x", 2);
	lp = (unsigned long long)p;
	counter += ft_puthex_fd(lp >> 32, fd, 0);
	counter += ft_puthex_fd(lp, fd, 0);
	return (counter);
}