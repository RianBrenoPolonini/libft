/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 12:06:47 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/02 12:27:51 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*ptr_dst;
	const unsigned char	*ptr_src = (unsigned char *)src;

	if (dst == src || n == 0)
		return (dst);
	ptr_dst = (unsigned char *)dst;
	if (ptr_src < ptr_dst)
	{
		ptr_dst += n;
		ptr_src += n;
		while (n--)
			*--ptr_dst = *--ptr_src;
	}
	else
	{
		while (n--)
			*ptr_dst++ = *ptr_src++;
	}
	return (dst);
}
