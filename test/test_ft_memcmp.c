/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:18:21 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/04 08:26:57 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "libft.h"
#include <string.h>

Test(ft_memcmp, basic_tests) {
    const char *str1 = "Hello World!";
    const char *str2 = "Hello World!";
    const char *str3 = "Hello World?";
    
    cr_assert_eq(ft_memcmp(str1, str2, 12), memcmp(str1, str2, 12),
                 "Erro: Esperado %d, mas obteve %d", memcmp(str1, str2, 12), ft_memcmp(str1, str2, 12));

    int result = ft_memcmp(str1, str3, 12);
		int result2 = memcmp(str1, str3, 12);
    cr_assert_eq(result, memcmp(str1, str3, 12),
                  "Erro: Esperado que as strings fossem diferentes. Resultado: %d vs %d", result, result2);
}

Test(ft_memcmp, zero_length) {
    const char *str1 = "Hello World!";
    const char *str2 = "Hello World!";

    cr_assert_eq(ft_memcmp(str1, str2, 0), memcmp(str1, str2, 0),
                 "Erro: Esperado 0 para n = 0, mas obteve %d", ft_memcmp(str1, str2, 0));
}

Test(ft_memcmp, edge_cases) {
    const char *str1 = "abc";
    const char *str2 = "abc";
    const char *str3 = "abd";

    cr_assert_eq(ft_memcmp(str1, str2, 3), 0, "Erro: Esperado 0, mas obteve %d", ft_memcmp(str1, str2, 3));
    cr_assert_neq(ft_memcmp(str1, str3, 3), 0, "Erro: Esperado não ser igual.");
}

Test(ft_memcmp, different_lengths) {
    const char *str1 = "abc";
    const char *str2 = "abcde";

    cr_assert_neq(ft_memcmp(str1, str2, 5), 0, "Erro: Esperado não ser igual.");
}

Test(ft_memcmp, partial_differences) {
    const char *str1 = "abcdef";
    const char *str2 = "abcXef";

    cr_assert_neq(ft_memcmp(str1, str2, 6), 0, "Erro: Esperado não ser igual.");
    cr_assert_eq(ft_memcmp(str1, str2, 3), 0, "Erro: Esperado 0 para os primeiros 3 caracteres.");
}

Test(ft_memcmp, lib_tests) {
    char	*str1 = "Hello World!";
    char	*str2 = "Hello World!";
    cr_assert_eq(ft_memcmp(str1, str2, 12), memcmp(str1, str2, 12),
                 "Erro: Esperado %d, mas obteve %d", memcmp(str1, str2, 12), ft_memcmp(str1, str2, 12));

    str1 = "Hello World!";
    str2 = "Hello World";
    cr_assert_eq(ft_memcmp(str1, str2, 12), memcmp(str1, str2, 12),
                  "Erro: Esperado que as strings sejam diferentes.");
    
    str1 = "Hello World";
    str2 = "Hello World!";
    cr_assert_eq(ft_memcmp(str1, str2, 12), memcmp(str1, str2, 12),
                  "Erro: Esperado que as strings sejam diferentes.");
}
