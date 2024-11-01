/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 05:37:45 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/01 05:42:12 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "libft.h"
#include <ctype.h>

Test(ft_isdigit, basic_tests) {
    cr_assert(ft_isdigit('0') == 1);
    cr_assert(ft_isdigit('5') == 1);
    cr_assert(ft_isdigit('9') == 1);
    cr_assert(ft_isdigit('a') == 0);
    cr_assert(ft_isdigit('Z') == 0);
    cr_assert(ft_isdigit(' ') == 0);
    cr_assert(ft_isdigit('!') == 0);
}

Test(ft_isdigit, lib_tests) {
    for (int i = 0; i < 256; i++) {
				cr_assert_eq(ft_isdigit(i), isdigit(i) ? 1 : 0, 
                     "Erro: Esperado %d para o caractere %c, mas obteve %d", 
                     ft_isdigit(i) ? 1 : 0, i, isdigit(i));
    }
}