/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 10:35:52 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/04 08:09:57 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "libft.h"
#include <string.h>

Test(ft_memset, basic_usage) {
    char buffer[10] = "abcdefghi";

    ft_memset(buffer, 'x', 5);
    cr_assert_str_eq(buffer, "xxxxxfghi", "Erro: Esperado 'xxxxxfghi', mas obteve '%s'", buffer);
}

Test(ft_memset, zero_length) {
    char buffer[10] = "abcdefghi";

    ft_memset(buffer, 'x', 0);
    cr_assert_str_eq(buffer, "abcdefghi", "Erro: Esperado 'abcdefghi' quando n = 0, mas obteve '%s'", buffer);
}

Test(ft_memset, full_length) {
    char buffer[10] = "abcdefghi";

    ft_memset(buffer, 'z', 9);
    cr_assert_str_eq(buffer, "zzzzzzzzz", "Erro: Esperado 'zzzzzzzzz', mas obteve '%s'", buffer);
}

Test(ft_memset, different_bytes) {
    char buffer[10] = "abcdefghi";

    ft_memset(buffer, 0, 5);
    cr_assert(memcmp(buffer, "\0\0\0\0\0fghi", 9) == 0, "Erro: Esperado '\\0\\0\\0\\0\\0fghi', mas obteve valores diferentes.");
}

Test(ft_memset, verify_return_value) {
    char buffer[10] = "abcdefghi";

    char *result = ft_memset(buffer, 'x', 5);
    cr_assert_eq(result, buffer, "Erro: O ponteiro de retorno não corresponde ao ponteiro de destino.");
}

Test(ft_memset, lib_tests) {
    char buffer1[10] = {0};
    char buffer2[10] = {0};
    ft_memset(buffer1, 'x', 10);
    memset(buffer2, 'x', 10);
    cr_assert_arr_eq(buffer1, buffer2, 10, "Erro: Os buffers deveriam ser iguais após memset");
}
