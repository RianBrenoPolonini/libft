/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 10:35:52 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/02 11:44:59 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "libft.h"
#include <string.h>

Test(ft_memset, basic_tests) {
    char str[10] = "abcdefghi";
		ft_memset(str, 'x', 5);
		cr_assert_str_eq(str, "xxxxxfghi", "Erro: Esperado 'xxxxxfghi', mas obteve '%s'", str);

    char buffer[8];
    ft_memset(buffer, '*', 8);
    for (int i = 0; i < 8; i++) {
        cr_assert(buffer[i] == '*', "Erro: Esperado '*', mas obteve '%c' no índice %d", buffer[i], i);
    }
}

Test(ft_memset, lib_tests) {
    char buffer1[10] = {0};
    char buffer2[10] = {0};
    ft_memset(buffer1, 'x', 10);
    memset(buffer2, 'x', 10);
    cr_assert_arr_eq(buffer1, buffer2, 10, "Erro: Os buffers deveriam ser iguais após memset");
}
