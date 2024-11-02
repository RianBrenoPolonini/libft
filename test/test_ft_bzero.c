/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_bzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:42:47 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/02 11:53:40 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "libft.h"
#include <string.h>

Test(ft_bzero, basic_tests) {
    char str[10] = "abcdefghi";
		ft_bzero(str, 5);
		cr_assert_str_eq(str, "\0\0\0\0\0fghi", "Erro: Esperado 'fghi', mas obteve '%s'", str);

    char buffer[8];
    ft_bzero(buffer, 8);
    for (int i = 0; i < 8; i++) {
        cr_assert(buffer[i] == '\0', "Erro: Esperado '\0', mas obteve '%c' no índice %d", buffer[i], i);
    }
}

Test(ft_bzero, lib_tests) {
    char buffer1[10] = {0};
    char buffer2[10] = {0};
    ft_bzero(buffer1, 10);
    bzero(buffer2, 10);
    cr_assert_arr_eq(buffer1, buffer2, 10, "Erro: Os buffers deveriam ser iguais após bzero");
}
