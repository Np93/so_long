/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhirzel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 20:15:59 by nhirzel           #+#    #+#             */
/*   Updated: 2021/10/29 22:51:49 by nhirzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*cpy(char *s, unsigned int n)
{
	int	i;

	i = 0;
	s[i] = '-';
	i++;
	n = n * -1;
	i = 11;
	while (n > 0)
	{
		i--;
		s[i] = n % 10 + 48;
		n = n / 10;
	}
	s[11] = '\0';
	return (&*s);
}

int	conte(int n)
{
	unsigned int	i;

	i = 1;
	if (n < 0)
	{
		n = n * -1;
		i = 2;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*s;
	unsigned int	i;

	i = conte(n);
	s = malloc(i + 1 * sizeof(char));
	if (n == -2147483648)
		return (cpy(s, -2147483648));
	if (s == NULL)
		return (0);
	if (n < 0)
	{
		s[0] = '-';
		n = n * -1;
	}
	if (n == 0)
		s[0] = '0';
	s[i] = '\0';
	while (n > 0)
	{
		i--;
		s[i] = n % 10 + 48;
		n = n / 10;
	}
	return (s);
}
