/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isascii.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 06:02:32 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/04 07:38:50 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "libft.h"
#include <ctype.h>

Test(ft_isascii, basic_tests) {
    cr_assert_eq(ft_isascii(0), 1, "Erro: 0 deveria ser um caractere ASCII.");
    cr_assert_eq(ft_isascii(65), 1, "Erro: 65 (A) deveria ser um caractere ASCII.");
    cr_assert_eq(ft_isascii(97), 1, "Erro: 97 (a) deveria ser um caractere ASCII.");
    cr_assert_eq(ft_isascii(127), 1, "Erro: 127 deveria ser um caractere ASCII.");

    cr_assert_eq(ft_isascii(128), 0, "Erro: 128 não deveria ser um caractere ASCII.");
    cr_assert_eq(ft_isascii(255), 0, "Erro: 255 não deveria ser um caractere ASCII.");
    cr_assert_eq(ft_isascii(-1), 0, "Erro: -1 não deveria ser um caractere ASCII.");
}

Test(ft_isascii, non_printable_characters) {
    for (int i = 0; i < 32; i++) {
        cr_assert_eq(ft_isascii(i), 1, "Erro: %d deveria ser um caractere ASCII.", i);
    }
}

Test(ft_isascii, edge_cases) {
    cr_assert_eq(ft_isascii(0), 1, "Erro: 0 deveria ser um caractere ASCII.");
    cr_assert_eq(ft_isascii(127), 1, "Erro: 127 deveria ser um caractere ASCII.");
    cr_assert_eq(ft_isascii(-1), 0, "Erro: -1 não deveria ser um caractere ASCII.");
    cr_assert_eq(ft_isascii(128), 0, "Erro: 128 não deveria ser um caractere ASCII.");
}

Test(ft_isascii, lib_tests) {
		for (int i = 0; i < 256; i++) {
				cr_assert_eq(ft_isascii(i), isascii(i) ? 1 : 0, 
										 "Erro: Esperado %d para o caractere %c, mas obteve %d", 
										 isascii(i) ? 1 : 0, i, ft_isascii(i));
		}
}
