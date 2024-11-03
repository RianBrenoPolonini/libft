/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_tolower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 08:41:55 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/03 08:42:10 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "libft.h"
#include <ctype.h>

Test(ft_tolower, basic_tests) {
		cr_assert_eq(ft_tolower('A'), 'a');
		cr_assert_eq(ft_tolower('Z'), 'z');
		cr_assert_eq(ft_tolower('5'), '5');
		cr_assert_eq(ft_tolower('0'), '0');
		cr_assert_eq(ft_tolower(' '), ' ');
		cr_assert_eq(ft_tolower('%'), '%');
		cr_assert_eq(ft_tolower(0), 0);
		cr_assert_eq(ft_tolower(127), 127);
		cr_assert_eq(ft_tolower(128), 128);
		cr_assert_eq(ft_tolower(255), 255);
		cr_assert_eq(ft_tolower('ß'), 'ß');
}

Test(ft_tolower, lib_tests) {
		for (int i = 0; i < 256; i++) {
				cr_assert_eq(ft_tolower(i), tolower(i), 
										 "Erro: Esperado %d para o caractere %c, mas obteve %d", 
										 tolower(i), i, ft_tolower(i));
		}
}
