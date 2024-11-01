/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 06:14:36 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/01 06:16:17 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "libft.h"
#include <ctype.h>

Test(ft_isprint, basic_tests) {
		cr_assert(ft_isprint('A') == 1);
		cr_assert(ft_isprint('z') == 1);
		cr_assert(ft_isprint('5') == 1);
		cr_assert(ft_isprint('0') == 1);
		cr_assert(ft_isprint(' ') == 1);
		cr_assert(ft_isprint('%') == 1);
		cr_assert(ft_isprint(0) == 0);
		cr_assert(ft_isprint(127) == 0);
		cr_assert(ft_isprint(128) == 0);
		cr_assert(ft_isprint(255) == 0);
		cr_assert(ft_isprint('ß') == 0);
}

Test(ft_isprint, lib_tests) {
		for (int i = 0; i < 256; i++) {
				cr_assert_eq(ft_isprint(i), isprint(i) ? 1 : 0, 
										 "Erro: Esperado %d para o caractere %c, mas obteve %d", 
										 isprint(i) ? 1 : 0, i, ft_isprint(i));
		}
}