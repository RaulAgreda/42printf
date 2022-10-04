/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragreda- <ragreda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:10:17 by ragreda-          #+#    #+#             */
/*   Updated: 2022/09/13 18:15:56 by ragreda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != 0)
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
	}
	if (c == 0)
		return (str);
	return (0);
}
