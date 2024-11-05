/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strmapi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:46:43 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/05 13:56:46 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "libft.h"
#include <string.h>

char to_upper(unsigned int index, char c) {
    (void) index; // Ignorar o índice
    if (c >= 'a' && c <= 'z') {
        return c - 32; // Converte para maiúsculo
    }
    return c; // Retorna o caractere inalterado
}

char *ft_strmapi(const char *s, char (*f)(unsigned int, char));

Test(ft_strmapi, normal_string) {
    char *result = ft_strmapi("hello", to_upper);
    cr_assert_str_eq(result, "HELLO", "Expected 'HELLO', got '%s'", result);
    free(result);
}

Test(ft_strmapi, empty_string) {
    char *result = ft_strmapi("", to_upper);
    cr_assert_str_eq(result, "", "Expected empty string, got '%s'", result);
    free(result);
}

Test(ft_strmapi, null_string) {
    char *result = ft_strmapi(NULL, to_upper);
    cr_assert_null(result, "Expected NULL, got '%s'", result);
}

Test(ft_strmapi, null_function) {
    char *result = ft_strmapi("test", NULL);
    cr_assert_null(result, "Expected NULL, got '%s'", result);
}

Test(ft_strmapi, string_with_non_alpha) {
    char *result = ft_strmapi("test123", to_upper);
    cr_assert_str_eq(result, "TEST123", "Expected 'TEST123', got '%s'", result);
    free(result);
}