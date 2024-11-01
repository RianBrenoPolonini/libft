/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isascii.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 06:02:32 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/01 06:07:14 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "libft.h"
#include <ctype.h>

Test(ft_isascii, basic_tests) {
		cr_assert(ft_isascii('A') == 1);
		cr_assert(ft_isascii('z') == 1);
		cr_assert(ft_isascii('5') == 1);
		cr_assert(ft_isascii('0') == 1);
		cr_assert(ft_isascii(' ') == 1);
		cr_assert(ft_isascii('%') == 1);
		cr_assert(ft_isascii(0) == 1);
		cr_assert(ft_isascii(127) == 1);
		cr_assert(ft_isascii(128) == 0);
		cr_assert(ft_isascii(255) == 0);
		cr_assert(ft_isascii('ß') == 0);
}

Test(ft_isascii, lib_tests) {
		for (int i = 0; i < 256; i++) {
				cr_assert_eq(ft_isascii(i), isascii(i) ? 1 : 0, 
										 "Erro: Esperado %d para o caractere %c, mas obteve %d", 
										 isascii(i) ? 1 : 0, i, ft_isascii(i));
		}
}

