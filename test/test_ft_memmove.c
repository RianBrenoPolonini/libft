/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memmove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 12:28:53 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/04 08:08:14 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "libft.h"
#include <string.h>

Test(ft_memmove, basic_copy) {
    char dest[50] = "Goodbye!";
    const char *src = "Hello, world!";

    ft_memmove(dest, src, 13);
    cr_assert_str_eq(dest, "Hello, world!", "Erro: A cópia básica falhou.");
}

Test(ft_memmove, overlapping_memory_dest_before_src) {
    char buffer[50] = "Hello, world!";

    ft_memmove(buffer + 7, buffer, 13);
    cr_assert_str_eq(buffer, "Hello, Hello, world!", "Erro: Cópia com sobreposição (dest antes de src) falhou.");
}

Test(ft_memmove, overlapping_memory_src_before_dest) {
    char buffer[50] = "Hello, world!";

    ft_memmove(buffer, buffer + 7, 6);
    cr_assert_str_eq(buffer, "world! world!", "Erro: Cópia com sobreposição (src antes de dest) falhou.");
}

Test(ft_memmove, zero_length) {
    char dest[50] = "Goodbye!";
    const char *src = "Hello, world!";

    ft_memmove(dest, src, 0);
    cr_assert_str_eq(dest, "Goodbye!", "Erro: A cópia com zero bytes não deveria alterar o destino.");
}

Test(ft_memmove, copy_within_same_buffer) {
    char buffer[20] = "Hello, world!";
    char expected[20] = "Hello, world!";

    memmove(expected + 7, expected, 5);
    ft_memmove(buffer + 7, buffer, 5);

    cr_assert_str_eq(buffer, expected, "Erro: Cópia dentro do mesmo buffer falhou.");
}

Test(ft_memmove, lib_tests) {
		char buffer1[10] = {0};
		char buffer2[10] = {0};
		ft_memmove(buffer1, "1234567890", 10);
		memmove(buffer2, "1234567890", 10);
		cr_assert_arr_eq(buffer1, buffer2, 10, "Erro: Os buffers deveriam ser iguais após memmove");
}
