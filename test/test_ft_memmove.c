/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memmove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 12:28:53 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/02 12:30:52 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "libft.h"
#include <string.h>

Test(ft_memmove, basic_tests) {
		char str[10] = "abcdefghi";
		char str2[10] = "123456789";
		ft_memmove(str, str2, 5);
		cr_assert_str_eq(str, "12345fghi", "Erro: Esperado '12345fghi', mas obteve '%s'", str);

		char buffer[8];
		ft_memmove(buffer, str2, 8);
		for (int i = 0; i < 8; i++) {
				cr_assert(buffer[i] == str2[i], "Erro: Esperado '%c', mas obteve '%c' no índice %d", str2[i], buffer[i], i);
		}
}

Test(ft_memmove, lib_tests) {
		char buffer1[10] = {0};
		char buffer2[10] = {0};
		ft_memmove(buffer1, "1234567890", 10);
		memmove(buffer2, "1234567890", 10);
		cr_assert_arr_eq(buffer1, buffer2, 10, "Erro: Os buffers deveriam ser iguais após memmove");
}