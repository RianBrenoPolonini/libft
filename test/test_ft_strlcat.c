/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 08:18:49 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/03 08:29:52 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "libft.h"
#include <string.h>

Test(ft_strlcat, basic_tests) {
		char str[10] = "abcdefghi";
		char str2[10] = "123456789";
		
		ft_strlcat(str, str2, 5);
		cr_assert_str_eq(str, "abcdefghi", "Erro: Esperado 'abcdefghi', mas obteve '%s'", str);
		
		char buffer[10] = "abcdefghi";
		ft_strlcat(buffer, str2, 10);
		cr_assert_str_eq(buffer, "abcdefghi", "Erro: Esperado 'abcdefghi', mas obteve '%s'", buffer);
		
		char buffer2[10] = "abcdefghi";
		ft_strlcat(buffer2, str2, 9);
		cr_assert_str_eq(buffer2, "abcdefghi", "Erro: Esperado 'abcdefghi', mas obteve '%s'", buffer2);
		
		char empty_buffer[10] = "abcdefghi";
		size_t result = ft_strlcat(empty_buffer, str2, 0);
		cr_assert_eq(result, 9, "Erro: Esperado 9 para o comprimento de 'src' quando dsize é 0, mas obteve %zu", result);
		cr_assert_str_eq(empty_buffer, "abcdefghi", "Erro: O buffer deve permanecer inalterado quando dsize é 0");

		char buffer3[10] = {0};
		ft_strlcat(buffer3, "1234567890", 6);
		cr_assert_str_eq(buffer3, "12345", "Erro: Esperado '12345', mas obteve '%s'", buffer3);
}

Test(ft_strlcat, lib_tests) {
		char buffer1[10] = {0};
		char buffer2[10] = {0};

		ft_strlcat(buffer1, "1234567890", 10);
		strlcat(buffer2, "1234567890", 10);
		cr_assert_str_eq(buffer1, buffer2, "Erro: Os buffers deveriam ser iguais após strlcat");

		char buffer3[10] = {0};
		ft_strlcat(buffer3, "1234567890", 5);
		cr_assert_str_eq(buffer3, "1234", "Erro: Esperado '1234', mas obteve '%s'", buffer3);
}