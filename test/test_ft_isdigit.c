/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 05:37:45 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/04 07:39:42 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "libft.h"
#include <ctype.h>

Test(ft_isdigit, basic_tests) {
    cr_assert_eq(ft_isdigit('0'), 1, "Erro: '0' deveria ser considerado um dígito.");
    cr_assert_eq(ft_isdigit('5'), 1, "Erro: '5' deveria ser considerado um dígito.");
    cr_assert_eq(ft_isdigit('9'), 1, "Erro: '9' deveria ser considerado um dígito.");

    cr_assert_eq(ft_isdigit('a'), 0, "Erro: 'a' não deveria ser considerado um dígito.");
    cr_assert_eq(ft_isdigit('Z'), 0, "Erro: 'Z' não deveria ser considerado um dígito.");
    cr_assert_eq(ft_isdigit('!'), 0, "Erro: '!' não deveria ser considerado um dígito.");
    cr_assert_eq(ft_isdigit(' '), 0, "Erro: espaço não deveria ser considerado um dígito.");
}

Test(ft_isdigit, extended_tests) {
    cr_assert_eq(ft_isdigit(-1), 0, "Erro: -1 não deveria ser considerado um dígito.");
    cr_assert_eq(ft_isdigit(10), 0, "Erro: 10 não deveria ser considerado um dígito.");
    cr_assert_eq(ft_isdigit(57), 1, "Erro: 57 (código ASCII de '9') deveria ser considerado um dígito.");
    cr_assert_eq(ft_isdigit(58), 0, "Erro: 58 não deveria ser considerado um dígito.");
}

Test(ft_isdigit, edge_cases) {
    cr_assert_eq(ft_isdigit('0'), 1, "Erro: '0' deveria ser considerado um dígito.");
    cr_assert_eq(ft_isdigit('9'), 1, "Erro: '9' deveria ser considerado um dígito.");
    cr_assert_eq(ft_isdigit('A'), 0, "Erro: 'A' não deveria ser considerado um dígito.");
    cr_assert_eq(ft_isdigit('a'), 0, "Erro: 'a' não deveria ser considerado um dígito.");
}

Test(ft_isdigit, lib_tests) {
    for (int i = 0; i < 256; i++) {
				cr_assert_eq(ft_isdigit(i), isdigit(i) ? 1 : 0, 
                     "Erro: Esperado %d para o caractere %c, mas obteve %d", 
                     ft_isdigit(i) ? 1 : 0, i, isdigit(i));
    }
}