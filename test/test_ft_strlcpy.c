/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 12:42:28 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/02 12:48:43 by rfaria-p         ###   ########.fr       */
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

		char buffer[8];
		ft_strlcpy(buffer, str2, 8);
		for (int i = 0; i < 7; i++) {
				cr_assert(buffer[i] == str2[i], "Erro: Esperado '%c', mas obteve '%c' no índice %d", str2[i], buffer[i], i);
		}
}

Test(ft_strlcpy, lib_tests) {
		char buffer1[10] = {0};
		char buffer2[10] = {0};
		ft_strlcpy(buffer1, "1234567890", 10);
		strlcpy(buffer2, "1234567890", 10);
		cr_assert_str_eq(buffer1, buffer2, "Erro: Os buffers deveriam ser iguais após strlcpy");
}