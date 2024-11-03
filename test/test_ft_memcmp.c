/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:18:21 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/03 11:35:44 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "libft.h"
#include <string.h>

Test(ft_memcmp, basic_tests) {
	char str1[] = "Hello World!";
	char str2[] = "Hello World";
	char str3[] = "Hello World!";
	char str4[] = "Hello, World!";
	
	cr_assert_eq(ft_memcmp(str1, str2, 12), 33, "Erro: Esperado 33, mas obteve %d", ft_memcmp(str1, str2, 12));
	cr_assert_eq(ft_memcmp(str2, str1, 12), -33, "Erro: Esperado -33, mas obteve %d", ft_memcmp(str2, str1, 12));
	cr_assert_eq(ft_memcmp(str1, str3, 12), 0, "Erro: Esperado 0, mas obteve %d", ft_memcmp(str1, str3, 12));
	cr_assert_eq(ft_memcmp(str1, str4, 12), -12, "Erro: Esperado -12, mas obteve %d", ft_memcmp(str1, str4, 12));
	cr_assert_eq(ft_memcmp(str1, str1, 0), 0, "Erro: Esperado 0, mas obteve %d", ft_memcmp(str1, str1, 0));
}

Test(ft_memcmp, lib_tests) {
	char	*str1 = "Hello World!";
	char	*str2 = "Hello World!";
	cr_assert_eq(ft_memcmp(str1, str2, 12), memcmp(str1, str2, 12));

	str1 = "Hello World!";
	str2 = "Hello World";
	cr_assert_eq(ft_memcmp(str1, str2, 12), memcmp(str1, str2, 12));

	str1 = "Hello World";
	str2 = "Hello World!";
	cr_assert_eq(ft_memcmp(str1, str2, 12), memcmp(str1, str2, 12));
}