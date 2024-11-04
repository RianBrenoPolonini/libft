/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 12:03:43 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/04 07:56:47 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "libft.h"
#include <string.h>

Test(ft_memcpy, basic_tests) {
    char dest[50];
    const char *src = "Hello World!";

    ft_memcpy(dest, src, 12);
    cr_assert_str_eq(dest, src, "Erro: A string não foi copiada corretamente.");
}

Test(ft_memcpy, zero_length) {
    char dest[50] = "Initial Value";
    const char *src = "Hello World!";

    ft_memcpy(dest, src, 0);
    cr_assert_str_eq(dest, "Initial Value", "Erro: O valor de dest não deveria ter mudado.");
}

Test(ft_memcpy, longer_source) {
    char dest[50];
    const char *src = "This is a longer source string!";

    ft_memcpy(dest, src, strlen(src) + 1);
    cr_assert_str_eq(dest, src, "Erro: A string longa não foi copiada corretamente.");
}

Test(ft_memcpy, partial_copy) {
    char dest[50] = "Goodbye!";
    const char *src = "Hello";

    ft_memcpy(dest, src, 5);
    dest[5] = '\0';
    cr_assert_str_eq(dest, "Hello", "Erro: A cópia parcial não funcionou corretamente.");
}

Test(ft_memcpy, edge_cases) {
    char dest[50] = {0};
    const char *src = "A";

    ft_memcpy(dest, src, 1);
    cr_assert_eq(dest[0], 'A', "Erro: A cópia de um único caractere falhou.");
    cr_assert_eq(dest[1], 0, "Erro: A segunda posição de dest não deve conter dados.");
}
Test(ft_memcpy, lib_tests) {
		char buffer1[10] = {0};
		char buffer2[10] = {0};
		ft_memcpy(buffer1, "1234567890", 10);
		memcpy(buffer2, "1234567890", 10);
		cr_assert_arr_eq(buffer1, buffer2, 10, "Erro: Os buffers deveriam ser iguais após memcpy");
}
