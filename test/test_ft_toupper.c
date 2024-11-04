/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_toupper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 08:38:57 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/04 08:31:31 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "libft.h"
#include <ctype.h>

Test(ft_toupper, lowercase_characters) {
    cr_assert_eq(ft_toupper('a'), 'A', "Erro: Esperado 'A', mas obteve '%c'", ft_toupper('a'));
    cr_assert_eq(ft_toupper('b'), 'B', "Erro: Esperado 'B', mas obteve '%c'", ft_toupper('b'));
    cr_assert_eq(ft_toupper('z'), 'Z', "Erro: Esperado 'Z', mas obteve '%c'", ft_toupper('z'));
}

Test(ft_toupper, uppercase_characters) {
    cr_assert_eq(ft_toupper('A'), 'A', "Erro: Esperado 'A', mas obteve '%c'", ft_toupper('A'));
    cr_assert_eq(ft_toupper('Z'), 'Z', "Erro: Esperado 'Z', mas obteve '%c'", ft_toupper('Z'));
}

Test(ft_toupper, non_alphabetic_characters) {
    cr_assert_eq(ft_toupper('1'), '1', "Erro: Esperado '1', mas obteve '%c'", ft_toupper('1'));
    cr_assert_eq(ft_toupper('$'), '$', "Erro: Esperado '$', mas obteve '%c'", ft_toupper('$'));
}

Test(ft_toupper, control_characters) {
    cr_assert_eq(ft_toupper('\n'), '\n', "Erro: Esperado '\\n', mas obteve '%c'", ft_toupper('\n'));
    cr_assert_eq(ft_toupper('\t'), '\t', "Erro: Esperado '\\t', mas obteve '%c'", ft_toupper('\t'));
}

Test(ft_toupper, extended_characters) {
    cr_assert_eq(ft_toupper('ç'), 'ç', "Erro: Esperado 'ç', mas obteve '%c'", ft_toupper('ç'));
    cr_assert_eq(ft_toupper('é'), 'é', "Erro: Esperado 'é', mas obteve '%c'", ft_toupper('é'));
}

Test(ft_toupper, lib_tests) {
		for (int i = 0; i < 256; i++) {
				cr_assert_eq(ft_toupper(i), toupper(i), 
										 "Erro: Esperado %d para o caractere %c, mas obteve %d", 
										 toupper(i), i, ft_toupper(i));
		}
}