/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 05:56:19 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/01 05:57:03 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "libft.h"
#include <ctype.h>

Test(ft_isalnum, basic_tests) {
    cr_assert(ft_isalnum('A') == 1);
    cr_assert(ft_isalnum('z') == 1);
    cr_assert(ft_isalnum('5') == 1);
    cr_assert(ft_isalnum('0') == 1);
    cr_assert(ft_isalnum(' ') == 0);
    cr_assert(ft_isalnum('%') == 0);
}

Test(ft_isalnum, lib_tests) {
		for (int i = 0; i < 256; i++) {
				cr_assert_eq(ft_isalnum(i), isalnum(i) ? 1 : 0, 
										 "Erro: Esperado %d para o caractere %c, mas obteve %d", 
										 isalnum(i) ? 1 : 0, i, ft_isalnum(i));
		}
}
