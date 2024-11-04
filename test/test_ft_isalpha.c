/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 05:27:46 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/04 07:38:02 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "libft.h"
#include <ctype.h>

Test(ft_isalpha, basic_tests) {
    cr_assert_eq(ft_isalpha('A'), 1, "Erro: 'A' deveria ser alfabético.");
    cr_assert_eq(ft_isalpha('z'), 1, "Erro: 'z' deveria ser alfabético.");
    cr_assert_eq(ft_isalpha('M'), 1, "Erro: 'M' deveria ser alfabético.");
    cr_assert_eq(ft_isalpha('g'), 1, "Erro: 'g' deveria ser alfabético.");
    cr_assert_eq(ft_isalpha('1'), 0, "Erro: '1' não deveria ser alfabético.");
    cr_assert_eq(ft_isalpha('@'), 0, "Erro: '@' não deveria ser alfabético.");
    cr_assert_eq(ft_isalpha(' '), 0, "Erro: ' ' não deveria ser alfabético.");
}

Test(ft_isalpha, extended_ascii_tests) {
    cr_assert_eq(ft_isalpha(128), 0, "Erro: 128 não deveria ser alfabético.");
    cr_assert_eq(ft_isalpha(255), 0, "Erro: 255 não deveria ser alfabético.");
}

Test(ft_isalpha, case_sensitivity) {
    for (char c = 'A'; c <= 'Z'; c++) {
        cr_assert_eq(ft_isalpha(c), 1, "Erro: '%c' deveria ser alfabético.", c);
    }
    for (char c = 'a'; c <= 'z'; c++) {
        cr_assert_eq(ft_isalpha(c), 1, "Erro: '%c' deveria ser alfabético.", c);
    }
}

Test(ft_isalpha, non_alpha_characters) {
    char non_alpha[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '=', '+', '{', '}', '|', ':', '"', '<', '>', '?', '~', '`', ' '};
    for (size_t i = 0; i < sizeof(non_alpha); i++) {
        cr_assert_eq(ft_isalpha(non_alpha[i]), 0, "Erro: '%c' não deveria ser alfabético.", non_alpha[i]);
    }
}

Test(ft_isalpha, lib_tests) {
    for (int i = 0; i < 256; i++) {
        cr_assert_eq(ft_isalpha(i), isalpha(i) ? 1 : 0, 
                     "Erro: Esperado %d para o caractere %c, mas obteve %d", 
                     isalpha(i) ? 1 : 0, i, ft_isalpha(i));
    }
}
