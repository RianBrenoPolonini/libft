/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 12:42:28 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/03 08:02:08 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "libft.h"
#include <string.h>

Test(ft_strlcpy, basic_tests) {
    char str[10] = "abcdefghi";
    char str2[10] = "123456789";
    
    ft_strlcpy(str, str2, 5);
    cr_assert_str_eq(str, "1234", "Erro: Esperado '1234', mas obteve '%s'", str);
    
    char buffer[10] = "abcdefghi";
    ft_strlcpy(buffer, str2, 10);
    cr_assert_str_eq(buffer, "123456789", "Erro: Esperado '123456789', mas obteve '%s'", buffer);
    
    char buffer2[10] = "abcdefghi";
    ft_strlcpy(buffer2, str2, 9);
    cr_assert_str_eq(buffer2, "12345678", "Erro: Esperado '12345678', mas obteve '%s'", buffer2);
    
    char empty_buffer[10] = "abcdefghi";
    size_t result = ft_strlcpy(empty_buffer, str2, 0);
    cr_assert_eq(result, 9, "Erro: Esperado 9 para o comprimento de 'src' quando dsize é 0, mas obteve %zu", result);
    cr_assert_str_eq(empty_buffer, "abcdefghi", "Erro: O buffer deve permanecer inalterado quando dsize é 0");
}

Test(ft_strlcpy, lib_tests) {
    char buffer1[10] = {0};
    char buffer2[10] = {0};

    ft_strlcpy(buffer1, "1234567890", 10);
    strlcpy(buffer2, "1234567890", 10);
    cr_assert_str_eq(buffer1, buffer2, "Erro: Os buffers deveriam ser iguais após strlcpy");

    char buffer3[10] = {0};
    ft_strlcpy(buffer3, "1234567890", 5);
    cr_assert_str_eq(buffer3, "1234", "Erro: Esperado '1234', mas obteve '%s'", buffer3);
}