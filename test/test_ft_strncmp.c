/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strncmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 09:22:52 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/03 09:46:40 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "libft.h"
#include <string.h>

Test(ft_strncmp, basic_tests) {
    cr_assert_eq(ft_strncmp("abcdef", "abcdef", 6), 0, "Erro: Esperado 0 para 'abcdef' e 'abcdef'");
    cr_assert_gt(ft_strncmp("abcdef", "abcde", 6), 0, "Erro: Esperado um valor positivo para 'abcdef' e 'abcde'");
    cr_assert_eq(ft_strncmp("abc", "abcdef", 3), 0, "Erro: Esperado 0 para 'abc' e 'abcdef' (comparando 3 caracteres)");
    cr_assert_eq(ft_strncmp("abcdef", "abc", 3), 0, "Erro: Esperado 0 para 'abcdef' e 'abc' (comparando 3 caracteres)");
    cr_assert_eq(ft_strncmp("", "abc", 3), strncmp("", "abc", 3), "Erro: Esperado -1 para '' e 'abc'");
    cr_assert_eq(ft_strncmp("abc", "", 3), strncmp("abc", "", 3), "Erro: Esperado 1 para 'abc' e ''");
    cr_assert_eq(ft_strncmp("abc", "abc", 0), 0, "Erro: Esperado 0 para 'abc' e 'abc' com n = 0");
    cr_assert_eq(ft_strncmp("abcdef", "abcdeg", 3), 0, "Erro: Esperado 0 para 'abcdef' e 'abcdeg' (comparando 3 caracteres)");
    cr_assert_eq(ft_strncmp("abc", "ABc", 3), strncmp("abc", "ABc", 3), "Erro: Esperado -1 para 'abc' e 'ABc' (case sensitive)");
    cr_assert_eq(ft_strncmp("ABC", "abc", 3), strncmp("ABC", "abc", 3), "Erro: Esperado 1 para 'ABC' e 'abc' (case sensitive)");
}

Test(ft_strncmp, lib_tests) {
		char buffer1[10] = "abcdefghi";
		char buffer2[10] = "abcdefghi";
		for (int i = 0; i < 256; i++) {
				int result_ft = ft_strncmp(buffer1, buffer2, i);
				int result_lib = strncmp(buffer1, buffer2, i);
				
				cr_assert_eq(result_ft, result_lib, 
										 "Erro: Esperado %d para a comparação de 'abcdefghi' e 'abcdefghi' com n = %d, mas obteve %d", 
										 result_lib, i, result_ft);
		}
}
