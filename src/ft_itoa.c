/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:03:27 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/05 13:42:24 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	allocate_digit_count(int number)
{
	int	count;

	count = 0;
	if (number < 0)
	{
		count++;
		number *= -1;
	}
	if (number == 0)
		return (1);
	while (number != 0)
	{
		number /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		length;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	length = allocate_digit_count(n);
	result = (char *)malloc(sizeof(char) * (length + 1));
	if (!result)
		return (NULL);
	if (n < 0)
	{
		result[0] = '-';
		n = -n;
	}
	result[length] = '\0';
	length--;
	while (n != 0)
	{
		result[length--] = (n % 10) + '0';
		n /= 10;
	}
	return (result);
}
