/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_tolower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 08:41:55 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/04 08:30:43 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "libft.h"
#include <ctype.h>

Test(ft_tolower, lowercase_characters) {
    cr_assert_eq(ft_tolower('a'), 'a', "Erro: Esperado 'a', mas obteve '%c'", ft_tolower('a'));
    cr_assert_eq(ft_tolower('b'), 'b', "Erro: Esperado 'b', mas obteve '%c'", ft_tolower('b'));
}

Test(ft_tolower, uppercase_characters) {
    cr_assert_eq(ft_tolower('A'), 'a', "Erro: Esperado 'a', mas obteve '%c'", ft_tolower('A'));
    cr_assert_eq(ft_tolower('Z'), 'z', "Erro: Esperado 'z', mas obteve '%c'", ft_tolower('Z'));
}

Test(ft_tolower, non_alphabetic_characters) {
    cr_assert_eq(ft_tolower('1'), '1', "Erro: Esperado '1', mas obteve '%c'", ft_tolower('1'));
    cr_assert_eq(ft_tolower('$'), '$', "Erro: Esperado '$', mas obteve '%c'", ft_tolower('$'));
}

Test(ft_tolower, control_characters) {
    cr_assert_eq(ft_tolower('\n'), '\n', "Erro: Esperado '\\n', mas obteve '%c'", ft_tolower('\n'));
    cr_assert_eq(ft_tolower('\t'), '\t', "Erro: Esperado '\\t', mas obteve '%c'", ft_tolower('\t'));
}

Test(ft_tolower, extended_characters) {
    cr_assert_eq(ft_tolower('ç'), 'ç', "Erro: Esperado 'ç', mas obteve '%c'", ft_tolower('ç'));
    cr_assert_eq(ft_tolower('é'), 'é', "Erro: Esperado 'é', mas obteve '%c'", ft_tolower('é'));
}

Test(ft_tolower, lib_tests) {
		for (int i = 0; i < 256; i++) {
				cr_assert_eq(ft_tolower(i), tolower(i), 
										 "Erro: Esperado %d para o caractere %c, mas obteve %d", 
										 tolower(i), i, ft_tolower(i));
		}
}
