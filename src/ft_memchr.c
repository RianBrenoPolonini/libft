/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:08:53 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/03 11:15:24 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str = s;
	unsigned char	target;

	target = (unsigned char)c;
	while (n--)
	{
		if (*str == target)
			return ((void *)str);
		str++;
	}
	return (NULL);
}
