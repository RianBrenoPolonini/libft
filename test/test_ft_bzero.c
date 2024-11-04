/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_bzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:42:47 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/04 07:36:03 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "libft.h"
#include <string.h>

Test(ft_bzero, basic_test) {
    char str[10] = "Hello";
    ft_bzero(str, 5);
    cr_assert_str_eq(str, "\0\0\0\0\0", "Erro: ft_bzero não zerou a memória corretamente.");
}

Test(ft_bzero, no_zeroing_when_n_is_zero) {
    char str[10] = "Hello";
    ft_bzero(str, 0);
    cr_assert_str_eq(str, "Hello", "Erro: ft_bzero não deve alterar a string quando n é 0.");
}

Test(ft_bzero, zeroing_entire_buffer) {
    char str[10] = "Hello";
    ft_bzero(str, sizeof(str));
    cr_assert_str_eq(str, "\0\0\0\0\0\0\0\0\0\0", "Erro: ft_bzero não zerou toda a memória corretamente.");
}

Test(ft_bzero, empty_string) {
    char str[1] = "";
    ft_bzero(str, 1);
    cr_assert_str_eq(str, "\0", "Erro: ft_bzero não zerou a string vazia corretamente.");
}

Test(ft_bzero, zeroing_n_bytes_in_array) {
    char str[10] = "abcdefghij";
    ft_bzero(str + 3, 4);
    cr_assert_str_eq(str, "abc\0\0\0\0ij", "Erro: ft_bzero não zerou os bytes corretamente na matriz.");
}

Test(ft_bzero, lib_tests) {
    char buffer1[10] = {0};
    char buffer2[10] = {0};
    ft_bzero(buffer1, 10);
    bzero(buffer2, 10);
    cr_assert_arr_eq(buffer1, buffer2, 10, "Erro: Os buffers deveriam ser iguais após bzero");
}
