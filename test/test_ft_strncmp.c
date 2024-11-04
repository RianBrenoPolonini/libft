/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strncmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 09:22:52 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/04 08:19:53 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "libft.h"
#include <string.h>

Test(ft_strncmp, equal_strings) {
    const char *s1 = "Hello, World!";
    const char *s2 = "Hello, World!";

    int expected = strncmp(s1, s2, 13);
    int result = ft_strncmp(s1, s2, 13);

    cr_assert_eq(result, expected, "Erro: Esperado %d, mas obteve %d", expected, result);
}

Test(ft_strncmp, different_strings) {
    const char *s1 = "Hello, World!";
    const char *s2 = "Hello, Universe!";

    int expected = strncmp(s1, s2, 13);
    int result = ft_strncmp(s1, s2, 13);

    cr_assert_eq(result, expected, "Erro: Esperado %d, mas obteve %d", expected, result);
}

Test(ft_strncmp, limit_smaller_than_difference) {
    const char *s1 = "Hello, World!";
    const char *s2 = "Hello, Universe!";

    int expected = strncmp(s1, s2, 7);
    int result = ft_strncmp(s1, s2, 7);

    cr_assert_eq(result, expected, "Erro: Esperado %d, mas obteve %d", expected, result);
}

Test(ft_strncmp, zero_length) {
    const char *s1 = "Hello, World!";
    const char *s2 = "Hello, Universe!";

    int expected = strncmp(s1, s2, 0);
    int result = ft_strncmp(s1, s2, 0);

    cr_assert_eq(result, expected, "Erro: Esperado %d, mas obteve %d", expected, result);
}

Test(ft_strncmp, partial_match) {
    const char *s1 = "Hello";
    const char *s2 = "Hello, World!";

    int expected = strncmp(s1, s2, 5);
    int result = ft_strncmp(s1, s2, 5);

    cr_assert_eq(result, expected, "Erro: Esperado %d, mas obteve %d", expected, result);
}

Test(ft_strncmp, empty_string_comparison) {
    const char *s1 = "";
    const char *s2 = "Hello";

    int expected = strncmp(s1, s2, 5);
    int result = ft_strncmp(s1, s2, 5);

    cr_assert_eq(result, expected, "Erro: Esperado %d, mas obteve %d", expected, result);
}

Test(ft_strncmp, both_empty_strings) {
    const char *s1 = "";
    const char *s2 = "";

    int expected = strncmp(s1, s2, 5);
    int result = ft_strncmp(s1, s2, 5);

    cr_assert_eq(result, expected, "Erro: Esperado %d, mas obteve %d", expected, result);
}
