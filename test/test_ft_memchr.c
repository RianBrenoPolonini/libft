/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:11:48 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/03 11:12:05 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "libft.h"
#include <string.h>

Test(ft_memchr, basic_tests) {
	char	*str = "Hello World!";
	char	*res = ft_memchr(str, 'W', 12);
	cr_assert_eq(res, str + 6);
}

Test(ft_memchr, lib_tests) {
	char	*str = "Hello World!";
	for (int i = 0; i < 256; i++) {
		cr_assert_eq(ft_memchr(str, i, 12), memchr(str, i, 12), 
								 "Erro: Esperado %p para o caractere %c, mas obteve %p", 
								 memchr(str, i, 12), i, ft_memchr(str, i, 12));
	}
}
