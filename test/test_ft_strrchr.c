/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strrchr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 09:02:40 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/03 09:18:44 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "libft.h"
#include <string.h>

Test(ft_strrchr, basic_tests) {
    char str[10] = "abcdefghi";
    cr_assert_str_eq(ft_strrchr(str, 'a'), &str[0], "Erro: Esperado 'a', mas obteve '%s'", ft_strrchr(str, 'a'));
    cr_assert_str_eq(ft_strrchr(str, 'b'), &str[1], "Erro: Esperado 'b', mas obteve '%s'", ft_strrchr(str, 'b'));
    cr_assert_str_eq(ft_strrchr(str, 'c'), &str[2], "Erro: Esperado 'c', mas obteve '%s'", ft_strrchr(str, 'c'));
    cr_assert_str_eq(ft_strrchr(str, 'd'), &str[3], "Erro: Esperado 'd', mas obteve '%s'", ft_strrchr(str, 'd'));
    cr_assert_str_eq(ft_strrchr(str, 'e'), &str[4], "Erro: Esperado 'e', mas obteve '%s'", ft_strrchr(str, 'e'));
    cr_assert_str_eq(ft_strrchr(str, 'f'), &str[5], "Erro: Esperado 'f', mas obteve '%s'", ft_strrchr(str, 'f'));
    cr_assert_str_eq(ft_strrchr(str, 'g'), &str[6], "Erro: Esperado 'g', mas obteve '%s'", ft_strrchr(str, 'g'));
    cr_assert_str_eq(ft_strrchr(str, 'h'), &str[7], "Erro: Esperado 'h', mas obteve '%s'", ft_strrchr(str, 'h'));
    cr_assert_str_eq(ft_strrchr(str, 'i'), &str[8], "Erro: Esperado 'i', mas obteve '%s'", ft_strrchr(str, 'i'));
    cr_assert_null(ft_strrchr(str, 'j'), "Erro: Esperado NULL, mas obteve '%s'", ft_strrchr(str, 'j'));
}

Test(ft_strrchr, repeated_character_tests) {
    char str[15] = "abcabcabcabc";
    cr_assert_str_eq(ft_strrchr(str, 'a'), "abc", "Erro: Esperado 'abc', mas obteve '%s'", ft_strrchr(str, 'a'));
    cr_assert_str_eq(ft_strrchr(str, 'b'), "bc", "Erro: Esperado 'bc', mas obteve '%s'", ft_strrchr(str, 'b'));
    cr_assert_str_eq(ft_strrchr(str, 'c'), "c", "Erro: Esperado 'c', mas obteve '%s'", ft_strrchr(str, 'c'));
    cr_assert_null(ft_strrchr(str, 'x'), "Erro: Esperado NULL para caractere não presente");
}

Test(ft_strrchr, lib_tests) {
    char buffer1[15] = "abcabcabcabc";
    char buffer2[15] = "abcabcabcabc";
    for (int i = 0; i < 256; i++) {
        char *result_ft = ft_strrchr(buffer1, i);
        char *result_lib = strrchr(buffer2, i);
        
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