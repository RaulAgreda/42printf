#ifndef FT_PRINTF_H
# define FT_PRINTF_H
int	ft_printf(char const *, ...);
int	ft_puthex_fd(unsigned int n, int fd, int mayus, int pritn_zero);
int	ft_putpointer_fd(void *p, int fd);

#endif