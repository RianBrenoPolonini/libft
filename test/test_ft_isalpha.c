/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 05:27:46 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/01 05:27:47 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "libft.h"
#include <ctype.h>

Test(ft_isalpha, basic_tests) {
    cr_assert(ft_isalpha('A') == 1);
    cr_assert(ft_isalpha('z') == 1);
    cr_assert(ft_isalpha('G') == 1);
    cr_assert(ft_isalpha('1') == 0);
    cr_assert(ft_isalpha('%') == 0);
    cr_assert(ft_isalpha(' ') == 0);
}

Test(ft_isalpha, lib_tests) {
    for (int i = 0; i < 256; i++) {
        cr_assert_eq(ft_isalpha(i), isalpha(i) ? 1 : 0, 
                     "Erro: Esperado %d para o caractere %c, mas obteve %d", 
                     isalpha(i) ? 1 : 0, i, ft_isalpha(i));
    }
}