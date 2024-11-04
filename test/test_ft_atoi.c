/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 07:08:29 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/04 07:13:06 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "libft.h"

Test(ft_atoi, basic_tests) {
    cr_assert_eq(ft_atoi("42"), 42, "Erro: Esperado 42, mas obteve %d", ft_atoi("42"));
    cr_assert_eq(ft_atoi("-42"), -42, "Erro: Esperado -42, mas obteve %d", ft_atoi("-42"));
    cr_assert_eq(ft_atoi("+42"), 42, "Erro: Esperado 42, mas obteve %d", ft_atoi("+42"));
    cr_assert_eq(ft_atoi("0"), 0, "Erro: Esperado 0, mas obteve %d", ft_atoi("0"));
    cr_assert_eq(ft_atoi("123456"), 123456, "Erro: Esperado 123456, mas obteve %d", ft_atoi("123456"));
    cr_assert_eq(ft_atoi("-123456"), -123456, "Erro: Esperado -123456, mas obteve %d", ft_atoi("-123456"));
}

Test(ft_atoi, whitespace_tests) {
    cr_assert_eq(ft_atoi("   42"), 42, "Erro: Esperado 42, mas obteve %d", ft_atoi("   42"));
    cr_assert_eq(ft_atoi("   -42"), -42, "Erro: Esperado -42, mas obteve %d", ft_atoi("   -42"));
    cr_assert_eq(ft_atoi("   +42"), 42, "Erro: Esperado 42, mas obteve %d", ft_atoi("   +42"));
}

Test(ft_atoi, zero_tests) {
    cr_assert_eq(ft_atoi("00042"), 42, "Erro: Esperado 42, mas obteve %d", ft_atoi("00042"));
    cr_assert_eq(ft_atoi("   +0000042"), 42, "Erro: Esperado 42, mas obteve %d", ft_atoi("   +0000042"));
    cr_assert_eq(ft_atoi("-00042"), -42, "Erro: Esperado -42, mas obteve %d", ft_atoi("-00042"));
}

Test(ft_atoi, non_numeric_tests) {
    cr_assert_eq(ft_atoi("42abc"), 42, "Erro: Esperado 42, mas obteve %d", ft_atoi("42abc"));
    cr_assert_eq(ft_atoi("-42abc"), -42, "Erro: Esperado -42, mas obteve %d", ft_atoi("-42abc"));
    cr_assert_eq(ft_atoi("abc42"), 0, "Erro: Esperado 0, mas obteve %d", ft_atoi("abc42"));
    cr_assert_eq(ft_atoi("abc"), 0, "Erro: Esperado 0, mas obteve %d", ft_atoi("abc"));
}

Test(ft_atoi, sign_only_tests) {
    cr_assert_eq(ft_atoi("+"), 0, "Erro: Esperado 0, mas obteve %d", ft_atoi("+"));
    cr_assert_eq(ft_atoi("-"), 0, "Erro: Esperado 0, mas obteve %d", ft_atoi("-"));
}

Test(ft_atoi, int_limits_tests) {
    cr_assert_eq(ft_atoi("2147483647"), 2147483647, "Erro: Esperado 2147483647, mas obteve %d", ft_atoi("2147483647"));
    cr_assert_eq(ft_atoi("-2147483648"), -2147483648, "Erro: Esperado -2147483648, mas obteve %d", ft_atoi("-2147483648"));
}

// Test(ft_atoi, overflow_tests) {
//     cr_assert_eq(ft_atoi("2147483648"), 2147483647, "Erro: Esperado INT_MAX, mas obteve %d", ft_atoi("2147483648"));
//     cr_assert_eq(ft_atoi("-2147483649"), -2147483648, "Erro: Esperado INT_MIN, mas obteve %d", ft_atoi("-2147483649"));
// }

Test(ft_atoi, empty_string) {
    cr_assert_eq(ft_atoi(""), 0, "Erro: Esperado 0 para string vazia, mas obteve %d", ft_atoi(""));
}

Test(ft_atoi, only_whitespace) {
		cr_assert_eq(ft_atoi("   "), 0, "Erro: Esperado 0 para string com espaços, mas obteve %d", ft_atoi("   "));
}

