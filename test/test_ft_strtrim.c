/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strtrim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:44:41 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/05 12:45:28 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "libft.h"
#include <string.h>

Test(ft_strtrim, basic_trim) {
    char *result = ft_strtrim("   Hello World   ", " ");
    cr_assert_str_eq(result, "Hello World", "Erro: Esperado 'Hello World', mas obteve '%s'", result);
    free(result);
}

Test(ft_strtrim, trim_start_only) {
    char *result = ft_strtrim("###Hello World", "#");
    cr_assert_str_eq(result, "Hello World", "Erro: Esperado 'Hello World', mas obteve '%s'", result);
    free(result);
}

Test(ft_strtrim, trim_end_only) {
    char *result = ft_strtrim("Hello World***", "*");
    cr_assert_str_eq(result, "Hello World", "Erro: Esperado 'Hello World', mas obteve '%s'", result);
    free(result);
}

Test(ft_strtrim, trim_both_sides) {
    char *result = ft_strtrim("$$$Hello World$$$", "$");
    cr_assert_str_eq(result, "Hello World", "Erro: Esperado 'Hello World', mas obteve '%s'", result);
    free(result);
}

Test(ft_strtrim, trim_multiple_chars) {
    char *result = ft_strtrim("###Hello World!!!", "#!");
    cr_assert_str_eq(result, "Hello World", "Erro: Esperado 'Hello World', mas obteve '%s'", result);
    free(result);
}

Test(ft_strtrim, no_trim_needed) {
    char *result = ft_strtrim("Hello World", " ");
    cr_assert_str_eq(result, "Hello World", "Erro: Esperado 'Hello World', mas obteve '%s'", result);
    free(result);
}

Test(ft_strtrim, empty_string) {
    char *result = ft_strtrim("", " ");
    cr_assert_str_eq(result, "", "Erro: Esperado string vazia, mas obteve '%s'", result);
    free(result);
}

Test(ft_strtrim, empty_set) {
    char *result = ft_strtrim("Hello World", "");
    cr_assert_str_eq(result, "Hello World", "Erro: Esperado 'Hello World' quando set é vazio, mas obteve '%s'", result);
    free(result);
}

Test(ft_strtrim, all_chars_in_set) {
    char *result = ft_strtrim("#####", "#");
    cr_assert_str_eq(result, "", "Erro: Esperado string vazia quando todos os caracteres estão no set, mas obteve '%s'", result);
    free(result);
}

Test(ft_strtrim, no_matching_set_chars) {
    char *result = ft_strtrim("Hello World", "#$");
    cr_assert_str_eq(result, "Hello World", "Erro: Esperado 'Hello World' quando nenhum caractere está no set, mas obteve '%s'", result);
    free(result);
}
