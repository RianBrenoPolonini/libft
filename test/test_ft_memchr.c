/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:11:48 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/04 07:52:19 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "libft.h"
#include <string.h>

Test(ft_memchr, basic_tests) {
    const char *str = "Hello World!";
    char *res;

    res = ft_memchr(str, 'W', 12);
    cr_assert_eq(res, str + 6, "Erro: Esperado %p para 'W', mas obteve %p", str + 6, res);

    res = ft_memchr(str, 'o', 12);
    cr_assert_eq(res, str + 4, "Erro: Esperado %p para 'o', mas obteve %p", str + 4, res);

    res = ft_memchr(str, '!', 12);
    cr_assert_eq(res, str + 11, "Erro: Esperado %p para '!', mas obteve %p", str + 11, res);
}

Test(ft_memchr, not_found) {
    const char *str = "Hello World!";
    char *res;

    res = ft_memchr(str, 'x', 12);
    cr_assert_null(res, "Erro: Esperado NULL para 'x', mas obteve %p", res);
}

Test(ft_memchr, zero_length) {
    const char *str = "Hello World!";
    char *res;

    res = ft_memchr(str, 'H', 0);
    cr_assert_null(res, "Erro: Esperado NULL para n = 0, mas obteve %p", res);
}

Test(ft_memchr, edge_cases) {
    const char *str = "Hello World!";
    char *res;

    res = ft_memchr(str, 'H', 12);
    cr_assert_eq(res, str, "Erro: Esperado %p para 'H', mas obteve %p", str, res);

    res = ft_memchr(str, 'd', 12);
    cr_assert_eq(res, str + 10, "Erro: Esperado %p para 'd', mas obteve %p", str + 10, res);

    res = ft_memchr(str, '!', 10);
    cr_assert_null(res, "Erro: Esperado NULL para '!', mas obteve %p", res);
}

Test(ft_memchr, multiple_occurrences) {
    const char *str = "Hello Hello!";
    char *res;

    res = ft_memchr(str, 'l', 12);
    cr_assert_eq(res, str + 2, "Erro: Esperado %p para 'l', mas obteve %p", str + 2, res);

    res = ft_memchr(res + 1, 'l', 12 - (res - str + 1));
    cr_assert_eq(res, str + 3, "Erro: Esperado %p para 'l', mas obteve %p", str + 3, res);
}

Test(ft_memchr, lib_tests) {
	char	*str = "Hello World!";
	for (int i = 0; i < 256; i++) {
		cr_assert_eq(ft_memchr(str, i, 12), memchr(str, i, 12), 
								 "Erro: Esperado %p para o caractere %c, mas obteve %p", 
								 memchr(str, i, 12), i, ft_memchr(str, i, 12));
	}
}
