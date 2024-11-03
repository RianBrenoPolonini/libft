/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 08:51:52 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/03 08:58:06 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "libft.h"
#include <string.h>

Test(ft_strchr, basic_tests) {
		char str[10] = "abcdefghi";
		cr_assert_str_eq(ft_strchr(str, 'a'), "abcdefghi", "Erro: Esperado 'abcdefghi', mas obteve '%s'", ft_strchr(str, 'a'));
		cr_assert_str_eq(ft_strchr(str, 'b'), "bcdefghi", "Erro: Esperado 'bcdefghi', mas obteve '%s'", ft_strchr(str, 'b'));
		cr_assert_str_eq(ft_strchr(str, 'c'), "cdefghi", "Erro: Esperado 'cdefghi', mas obteve '%s'", ft_strchr(str, 'c'));
		cr_assert_str_eq(ft_strchr(str, 'd'), "defghi", "Erro: Esperado 'defghi', mas obteve '%s'", ft_strchr(str, 'd'));
		cr_assert_str_eq(ft_strchr(str, 'e'), "efghi", "Erro: Esperado 'efghi', mas obteve '%s'", ft_strchr(str, 'e'));
		cr_assert_str_eq(ft_strchr(str, 'f'), "fghi", "Erro: Esperado 'fghi', mas obteve '%s'", ft_strchr(str, 'f'));
		cr_assert_str_eq(ft_strchr(str, 'g'), "ghi", "Erro: Esperado 'ghi', mas obteve '%s'", ft_strchr(str, 'g'));
		cr_assert_str_eq(ft_strchr(str, 'h'), "hi", "Erro: Esperado 'hi', mas obteve '%s'", ft_strchr(str, 'h'));
		cr_assert_str_eq(ft_strchr(str, 'i'), "i", "Erro: Esperado 'i', mas obteve '%s'", ft_strchr(str, 'i'));
		cr_assert_null(ft_strchr(str, 'j'), "Erro: Esperado NULL, mas obteve '%s'", ft_strchr(str, 'j'));
}

Test(ft_strchr, lib_tests) {
    char buffer1[10] = "abcdefghi";
    char buffer2[10] = "abcdefghi";
    for (int i = 0; i < 256; i++) {
        char *result_ft = ft_strchr(buffer1, i);
        char *result_lib = strchr(buffer2, i);
        
        if (result_ft == NULL || result_lib == NULL) {
            cr_assert_null(result_ft, "Erro: Esperado NULL para o caractere %c, mas obteve '%s'", i, result_ft);
            cr_assert_null(result_lib, "Erro: Esperado NULL para o caractere %c, mas obteve '%s'", i, result_lib);
        } else {
            cr_assert_str_eq(result_ft, result_lib, 
                             "Erro: Esperado '%s' para o caractere %c, mas obteve '%s'", 
                             result_lib, i, result_ft);
        }
    }
}
