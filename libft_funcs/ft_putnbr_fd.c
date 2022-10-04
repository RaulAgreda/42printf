/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragreda- <ragreda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:35:43 by ragreda-          #+#    #+#             */
/*   Updated: 2022/10/01 13:13:48 by ragreda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	_ft_putnbr_fd(long n, int fd, int *counter)
{
	char	c;

	if (n < 0)
	{
		(*counter)++;
		write(fd, "-", 1);
		_ft_putnbr_fd(-n, fd, counter);
	}
	else
	{
		if (n / 10 != 0)
			_ft_putnbr_fd(n / 10, fd, counter);
		c = n % 10 + '0';
		(*counter)++;
		write(fd, &c, 1);
	}
}

int	ft_putnbr_fd(long n, int fd)
{
	int	counter;

	counter = 0;
	_ft_putnbr_fd(n, fd, &counter);
	return (counter);
}
