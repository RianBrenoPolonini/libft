/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 08:51:52 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/04 08:21:12 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "libft.h"
#include <string.h>

Test(ft_strchr, basic_usage) {
    const char *str = "Hello World!";

    cr_assert_eq(ft_strchr(str, 'W'), strchr(str, 'W'), 
                 "Erro: Esperado ponteiro para '%s', mas obteve ponteiro para '%s'.", strchr(str, 'W'), ft_strchr(str, 'W'));

    cr_assert_eq(ft_strchr(str, 'H'), strchr(str, 'H'), 
                 "Erro: Esperado ponteiro para '%s', mas obteve ponteiro para '%s'.", strchr(str, 'H'), ft_strchr(str, 'H'));

    cr_assert_eq(ft_strchr(str, '!'), strchr(str, '!'), 
                 "Erro: Esperado ponteiro para '%s', mas obteve ponteiro para '%s'.", strchr(str, '!'), ft_strchr(str, '!'));
}

Test(ft_strchr, null_terminator) {
    const char *str = "Hello World!";

    cr_assert_eq(ft_strchr(str, '\0'), strchr(str, '\0'), 
                 "Erro: Esperado ponteiro para o terminador nulo, mas obteve ponteiro para '%s'.", ft_strchr(str, '\0'));
}

Test(ft_strchr, character_not_found) {
    const char *str = "Hello World!";

    cr_assert_null(ft_strchr(str, 'x'), "Erro: Esperado NULL para caractere inexistente.");
}

Test(ft_strchr, empty_string) {
    const char *str = "";

    cr_assert_null(ft_strchr(str, 'a'), "Erro: Esperado NULL para string vazia com caractere não encontrado.");
    cr_assert_eq(ft_strchr(str, '\0'), str, "Erro: Esperado ponteiro para o terminador nulo na string vazia.");
}

Test(ft_strchr, multiple_occurrences) {
    const char *str = "banana";

    cr_assert_eq(ft_strchr(str, 'a'), strchr(str, 'a'), 
                 "Erro: Esperado ponteiro para a primeira ocorrência de 'a', mas obteve ponteiro para '%s'.", ft_strchr(str, 'a'));
}
