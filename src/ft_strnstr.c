/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:36:27 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/05 12:40:00 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;

	if (!*little)
		return ((char *)big);
	little_len = ft_strlen(little);
	while (*big && len >= little_len)
	{
		if (*big == *little && !ft_strncmp(big, little, little_len))
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
