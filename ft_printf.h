#ifndef FT_PRINTF_H
# define FT_PRINTF_H
int		ft_printf(char const *, ...);
void	ft_puthex_fd(unsigned int n, int fd, int mayus);
void	ft_putpointer_fd(void *p, int fd);

#endif