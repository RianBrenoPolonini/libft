/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 06:14:36 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/04 07:40:37 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "libft.h"
#include <ctype.h>

Test(ft_isprint, basic_tests) {
    cr_assert_eq(ft_isprint(' '), 1, "Erro: espaço deveria ser considerado imprimível.");
    cr_assert_eq(ft_isprint('A'), 1, "Erro: 'A' deveria ser considerado imprimível.");
    cr_assert_eq(ft_isprint('z'), 1, "Erro: 'z' deveria ser considerado imprimível.");
    cr_assert_eq(ft_isprint('~'), 1, "Erro: '~' deveria ser considerado imprimível.");
    
    cr_assert_eq(ft_isprint('\n'), 0, "Erro: nova linha não deveria ser considerado imprimível.");
    cr_assert_eq(ft_isprint('\t'), 0, "Erro: tabulação não deveria ser considerado imprimível.");
    cr_assert_eq(ft_isprint('\0'), 0, "Erro: caractere nulo não deveria ser considerado imprimível.");
}

Test(ft_isprint, extended_tests) {
    cr_assert_eq(ft_isprint(31), 0, "Erro: 31 não deveria ser considerado imprimível.");
    cr_assert_eq(ft_isprint(32), 1, "Erro: 32 (espaço) deveria ser considerado imprimível.");
    cr_assert_eq(ft_isprint(126), 1, "Erro: 126 (~) deveria ser considerado imprimível.");
    cr_assert_eq(ft_isprint(127), 0, "Erro: 127 não deveria ser considerado imprimível.");
}

Test(ft_isprint, edge_cases) {
    cr_assert_eq(ft_isprint(0), 0, "Erro: 0 não deveria ser considerado imprimível.");
    cr_assert_eq(ft_isprint(31), 0, "Erro: 31 não deveria ser considerado imprimível.");
    cr_assert_eq(ft_isprint(32), 1, "Erro: 32 (espaço) deveria ser considerado imprimível.");
    cr_assert_eq(ft_isprint(126), 1, "Erro: 126 (~) deveria ser considerado imprimível.");
    cr_assert_eq(ft_isprint(127), 0, "Erro: 127 não deveria ser considerado imprimível.");
}

Test(ft_isprint, lib_tests) {
		for (int i = 0; i < 256; i++) {
				cr_assert_eq(ft_isprint(i), isprint(i) ? 1 : 0, 
										 "Erro: Esperado %d para o caractere %c, mas obteve %d", 
										 isprint(i) ? 1 : 0, i, ft_isprint(i));
		}
}