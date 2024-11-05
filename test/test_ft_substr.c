/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_substr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:32:39 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/05 12:33:06 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "libft.h"
#include <string.h>

Test(ft_substr, basic_case) {
    const char *s = "Hello, World!";
    char *result = ft_substr(s, 7, 5);
    
    cr_assert_str_eq(result, "World", "Erro: Esperado 'World', mas obteve '%s'", result);
    free(result);
}

Test(ft_substr, full_length) {
    const char *s = "Hello, World!";
    char *result = ft_substr(s, 0, ft_strlen(s));
    
    cr_assert_str_eq(result, s, "Erro: Esperado '%s', mas obteve '%s'", s, result);
    free(result);
}

Test(ft_substr, start_beyond_length) {
    const char *s = "Hello, World!";
    char *result = ft_substr(s, 50, 10);
    
    cr_assert_str_eq(result, "", "Erro: Esperado string vazia, mas obteve '%s'", result);
    free(result);
}

Test(ft_substr, length_exceeds_string) {
    const char *s = "Hello";
    char *result = ft_substr(s, 1, 10);
    
    cr_assert_str_eq(result, "ello", "Erro: Esperado 'ello', mas obteve '%s'", result);
    free(result);
}

Test(ft_substr, zero_length) {
    const char *s = "Hello, World!";
    char *result = ft_substr(s, 5, 0);
    
    cr_assert_str_eq(result, "", "Erro: Esperado string vazia, mas obteve '%s'", result);
    free(result);
}

Test(ft_substr, null_input) {
    char *result = ft_substr(NULL, 5, 10);
    
    cr_assert_null(result, "Erro: Esperado NULL, mas obteve '%s'", result);
}

Test(ft_substr, empty_string) {
    const char *s = "";
    char *result = ft_substr(s, 0, 5);
    
    cr_assert_str_eq(result, "", "Erro: Esperado string vazia, mas obteve '%s'", result);
    free(result);
}
