/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 12:42:28 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/04 08:20:15 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "libft.h"
#include <string.h>

Test(ft_strlcpy, basic_copy) {
    char dest[20];
    const char *src = "Hello, World!";

    size_t expected = strlcpy(dest, src, sizeof(dest));
    char dest_copy[20];
    size_t result = ft_strlcpy(dest_copy, src, sizeof(dest_copy));
    
    cr_assert_eq(result, expected, "Erro: Esperado %zu, mas obteve %zu", expected, result);
    cr_assert_str_eq(dest_copy, dest, "Erro: String esperada '%s', mas obteve '%s'", dest, dest_copy);
}

Test(ft_strlcpy, buffer_smaller_than_source) {
    char dest[5];
    const char *src = "Hello, World!";

    size_t expected = strlcpy(dest, src, sizeof(dest));
    char dest_copy[5];
    size_t result = ft_strlcpy(dest_copy, src, sizeof(dest_copy));
    
    cr_assert_eq(result, expected, "Erro: Esperado %zu, mas obteve %zu", expected, result);
    cr_assert_str_eq(dest_copy, dest, "Erro: String esperada '%s', mas obteve '%s'", dest, dest_copy);
}

Test(ft_strlcpy, exact_buffer_size) {
    char dest[6];
    const char *src = "Hello";

    size_t expected = strlcpy(dest, src, sizeof(dest));
    char dest_copy[6];
    size_t result = ft_strlcpy(dest_copy, src, sizeof(dest_copy));
    
    cr_assert_eq(result, expected, "Erro: Esperado %zu, mas obteve %zu", expected, result);
    cr_assert_str_eq(dest_copy, dest, "Erro: String esperada '%s', mas obteve '%s'", dest, dest_copy);
}

Test(ft_strlcpy, empty_source_string) {
    char dest[10] = "Initial";
    const char *src = "";

    size_t expected = strlcpy(dest, src, sizeof(dest));
    char dest_copy[10] = "Initial";
    size_t result = ft_strlcpy(dest_copy, src, sizeof(dest_copy));
    
    cr_assert_eq(result, expected, "Erro: Esperado %zu, mas obteve %zu", expected, result);
    cr_assert_str_eq(dest_copy, dest, "Erro: String esperada '%s', mas obteve '%s'", dest, dest_copy);
}

Test(ft_strlcpy, zero_buffer_size) {
    char dest[20] = "Initial";
    const char *src = "Hello, World!";

    size_t expected = strlcpy(dest, src, 0);
    char dest_copy[20] = "Initial";
    size_t result = ft_strlcpy(dest_copy, src, 0);
    
    cr_assert_eq(result, expected, "Erro: Esperado %zu, mas obteve %zu", expected, result);
    cr_assert_str_eq(dest_copy, dest, "Erro: String esperada '%s', mas obteve '%s'", dest, dest_copy);
}

Test(ft_strlcpy, large_source_string) {
    char dest[10];
    const char *src = "This is a very large source string";

    size_t expected = strlcpy(dest, src, sizeof(dest));
    char dest_copy[10];
    size_t result = ft_strlcpy(dest_copy, src, sizeof(dest_copy));
    
    cr_assert_eq(result, expected, "Erro: Esperado %zu, mas obteve %zu", expected, result);
    cr_assert_str_eq(dest_copy, dest, "Erro: String esperada '%s', mas obteve '%s'", dest, dest_copy);
}
