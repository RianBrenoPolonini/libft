/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 09:01:27 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/03 10:32:48 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char target;
	char	*last_occurrence;
	
	target = (char)c;
	last_occurrence = NULL;
	while (*s)
	{
		if (*s == (char)target)
			last_occurrence = (char *)s;
		s++;
	}
	if (target == '\0')
		return ((char *)s);
	return (last_occurrence);
}
