/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 08:18:49 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/04 08:20:47 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "libft.h"
#include <string.h>

Test(ft_strlcat, basic_concatenation) {
    char dest[20] = "Hello, ";
    const char *src = "World!";

    size_t expected = strlcat(dest, src, sizeof(dest));
    char dest_copy[20] = "Hello, ";
    size_t result = ft_strlcat(dest_copy, src, sizeof(dest_copy));
    
    cr_assert_eq(result, expected, "Erro: Esperado %zu, mas obteve %zu", expected, result);
    cr_assert_str_eq(dest_copy, dest, "Erro: String esperada '%s', mas obteve '%s'", dest, dest_copy);
}

Test(ft_strlcat, destination_buffer_size_exceeded) {
    char dest[10] = "Hello";
    const char *src = " World!";

    size_t expected = strlcat(dest, src, sizeof(dest));
    char dest_copy[10] = "Hello";
    size_t result = ft_strlcat(dest_copy, src, sizeof(dest_copy));
    
    cr_assert_eq(result, expected, "Erro: Esperado %zu, mas obteve %zu", expected, result);
    cr_assert_str_eq(dest_copy, dest, "Erro: String esperada '%s', mas obteve '%s'", dest, dest_copy);
}

Test(ft_strlcat, zero_buffer_size) {
    char dest[20] = "Hello";
    const char *src = "World!";

    size_t expected = strlcat(dest, src, 0);
    char dest_copy[20] = "Hello";
    size_t result = ft_strlcat(dest_copy, src, 0);
    
    cr_assert_eq(result, expected, "Erro: Esperado %zu, mas obteve %zu", expected, result);
    cr_assert_str_eq(dest_copy, dest, "Erro: String esperada '%s', mas obteve '%s'", dest, dest_copy);
}

Test(ft_strlcat, empty_source_string) {
    char dest[20] = "Hello";
    const char *src = "";

    size_t expected = strlcat(dest, src, sizeof(dest));
    char dest_copy[20] = "Hello";
    size_t result = ft_strlcat(dest_copy, src, sizeof(dest_copy));
    
    cr_assert_eq(result, expected, "Erro: Esperado %zu, mas obteve %zu", expected, result);
    cr_assert_str_eq(dest_copy, dest, "Erro: String esperada '%s', mas obteve '%s'", dest, dest_copy);
}

Test(ft_strlcat, empty_destination_string) {
    char dest[20] = "";
    const char *src = "Hello!";

    size_t expected = strlcat(dest, src, sizeof(dest));
    char dest_copy[20] = "";
    size_t result = ft_strlcat(dest_copy, src, sizeof(dest_copy));
    
    cr_assert_eq(result, expected, "Erro: Esperado %zu, mas obteve %zu", expected, result);
    cr_assert_str_eq(dest_copy, dest, "Erro: String esperada '%s', mas obteve '%s'", dest, dest_copy);
}

Test(ft_strlcat, buffer_smaller_than_destination) {
    char dest[20] = "Hello, ";
    const char *src = "World!";

    size_t expected = strlcat(dest, src, 5);
    char dest_copy[20] = "Hello, ";
    size_t result = ft_strlcat(dest_copy, src, 5);
    
    cr_assert_eq(result, expected, "Erro: Esperado %zu, mas obteve %zu", expected, result);
    cr_assert_str_eq(dest_copy, dest, "Erro: String esperada '%s', mas obteve '%s'", dest, dest_copy);
}
