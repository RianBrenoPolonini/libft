/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strrchr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 09:02:40 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/04 08:29:37 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "libft.h"
#include <string.h>

Test(ft_strrchr, basic_match) {
    const char *str = "Hello, World!";
    int c = 'o';

    char *expected = strrchr(str, c);
    char *result = ft_strrchr(str, c);

    cr_assert_str_eq(result, expected, "Erro: Esperado %s, mas obteve %s", expected, result);
}

Test(ft_strrchr, character_not_found) {
    const char *str = "Hello, World!";
    int c = 'x';

    char *expected = strrchr(str, c);
    char *result = ft_strrchr(str, c);

    cr_assert_eq(result, expected, "Erro: Esperado %p, mas obteve %p", expected, result);
}

Test(ft_strrchr, match_at_end) {
    const char *str = "Hello, World!";
    int c = '!';

    char *expected = strrchr(str, c);
    char *result = ft_strrchr(str, c);

    cr_assert_str_eq(result, expected, "Erro: Esperado %s, mas obteve %s", expected, result);
}

Test(ft_strrchr, match_at_start) {
    const char *str = "aaaaaa";
    int c = 'a';

    char *expected = strrchr(str, c);
    char *result = ft_strrchr(str, c);
    
    cr_assert_str_eq(result, expected, "Erro: Esperado %s, mas obteve %s", expected, result);
}

Test(ft_strrchr, empty_string) {
    const char *str = "";
    int c = 'a';

    char *expected = strrchr(str, c);
    char *result = ft_strrchr(str, c);
    
    cr_assert_eq(result, expected, "Erro: Esperado %p, mas obteve %p", expected, result);
}

Test(ft_strrchr, match_multiple_occurrences) {
    const char *str = "Hello, World!";
    int c = 'o';

    char *expected = strrchr(str, c);
    char *result = ft_strrchr(str, c);

    cr_assert_str_eq(result, expected, "Erro: Esperado %s, mas obteve %s", expected, result);
}

Test(ft_strrchr, match_with_null_character) {
    const char *str = "Hello, World! \0";
    int c = '\0';

    char *expected = strrchr(str, c);
    char *result = ft_strrchr(str, c);

    cr_assert_str_eq(result, expected, "Erro: Esperado %s, mas obteve %s", expected, result);
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
