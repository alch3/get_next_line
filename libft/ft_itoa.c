/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:45:05 by rcavadas          #+#    #+#             */
/*   Updated: 2016/02/10 18:06:18 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	lenght(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	else if (n == 0)
		return (2);
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	i++;
	return (i);
}

char		*ft_itoa(int n)
{
	int		len;
	int		i;
	char	*str;

	len = lenght(n);
	i = len - 2;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = ft_strnew(len - 1);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		str[i] = '0' - n % 10;
		n = -n / 10;
		i--;
	}
	while (i >= 0 && str[i] != '-')
	{
		str[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (str);
}
