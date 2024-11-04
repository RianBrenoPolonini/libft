/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 05:56:19 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/04 07:36:50 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "libft.h"
#include <ctype.h>

Test(ft_isalnum, basic_tests) {
    cr_assert_eq(ft_isalnum('A'), 1, "Erro: 'A' deveria ser alfanumérico.");
    cr_assert_eq(ft_isalnum('z'), 1, "Erro: 'z' deveria ser alfanumérico.");
    cr_assert_eq(ft_isalnum('0'), 1, "Erro: '0' deveria ser alfanumérico.");
    cr_assert_eq(ft_isalnum('@'), 0, "Erro: '@' não deveria ser alfanumérico.");
    cr_assert_eq(ft_isalnum(' '), 0, "Erro: ' ' não deveria ser alfanumérico.");
    cr_assert_eq(ft_isalnum('-'), 0, "Erro: '-' não deveria ser alfanumérico.");
}

Test(ft_isalnum, extended_ascii_tests) {
    cr_assert_eq(ft_isalnum(128), 0, "Erro: 128 não deveria ser alfanumérico.");
    cr_assert_eq(ft_isalnum(255), 0, "Erro: 255 não deveria ser alfanumérico.");
}

Test(ft_isalnum, digits_and_letters) {
    for (char c = '0'; c <= '9'; c++) {
        cr_assert_eq(ft_isalnum(c), 1, "Erro: '%c' deveria ser alfanumérico.", c);
    }
    for (char c = 'A'; c <= 'Z'; c++) {
        cr_assert_eq(ft_isalnum(c), 1, "Erro: '%c' deveria ser alfanumérico.", c);
    }
    for (char c = 'a'; c <= 'z'; c++) {
        cr_assert_eq(ft_isalnum(c), 1, "Erro: '%c' deveria ser alfanumérico.", c);
    }
}

Test(ft_isalnum, non_alphanumeric) {
    char non_alphanum[] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', '{', '}', '|', ':', '"', '<', '>', '?', '~', '`'};
    for (size_t i = 0; i < sizeof(non_alphanum); i++) {
        cr_assert_eq(ft_isalnum(non_alphanum[i]), 0, "Erro: '%c' não deveria ser alfanumérico.", non_alphanum[i]);
    }
}

Test(ft_isalnum, lib_tests) {
		for (int i = 0; i < 256; i++) {
				cr_assert_eq(ft_isalnum(i), isalnum(i) ? 1 : 0, 
										 "Erro: Esperado %d para o caractere %c, mas obteve %d", 
										 isalnum(i) ? 1 : 0, i, ft_isalnum(i));
		}
}
