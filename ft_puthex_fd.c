#include <unistd.h>

int	ft_puthex_fd(unsigned int n, int fd, int mayus)
{
	char	c;
	char	buffer[16];
	int		i;

	buffer[0] = '0';
	i = 0;
	while (n != 0 && i < 16)
	{
		if (n%16 >= 10)
		{
			if (mayus)
				c = n % 16 - 10 + 'A';
			else
				c = n % 16 - 10 + 'a';
		}
		else
			c = n % 16 + '0';
		buffer[15 - i] = c;
		n /= 16;
		i += 1;
	}
	write(fd, buffer + 16 - i, i);
	return (i);
}