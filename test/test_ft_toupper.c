/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_toupper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 08:38:57 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/03 08:40:04 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "libft.h"
#include <ctype.h>

Test(ft_toupper, basic_tests) {
		cr_assert_eq(ft_toupper('a'), 'A');
		cr_assert_eq(ft_toupper('z'), 'Z');
		cr_assert_eq(ft_toupper('5'), '5');
		cr_assert_eq(ft_toupper('0'), '0');
		cr_assert_eq(ft_toupper(' '), ' ');
		cr_assert_eq(ft_toupper('%'), '%');
		cr_assert_eq(ft_toupper(0), 0);
		cr_assert_eq(ft_toupper(127), 127);
		cr_assert_eq(ft_toupper(128), 128);
		cr_assert_eq(ft_toupper(255), 255);
		cr_assert_eq(ft_toupper('ß'), 'ß');
}

Test(ft_toupper, lib_tests) {
		for (int i = 0; i < 256; i++) {
				cr_assert_eq(ft_toupper(i), toupper(i), 
										 "Erro: Esperado %d para o caractere %c, mas obteve %d", 
										 toupper(i), i, ft_toupper(i));
		}
}