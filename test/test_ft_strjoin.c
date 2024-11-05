/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:37:48 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/05 12:38:27 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "libft.h"
#include <string.h>

Test(ft_strjoin, basic_join) {
    char *s1 = "Hello, ";
    char *s2 = "World!";
    char *result = ft_strjoin(s1, s2);

    cr_assert_str_eq(result, "Hello, World!", "Erro: Esperado 'Hello, World!', mas obteve '%s'", result);
    free(result);
}

Test(ft_strjoin, empty_first_string) {
    char *s1 = "";
    char *s2 = "World!";
    char *result = ft_strjoin(s1, s2);

    cr_assert_str_eq(result, "World!", "Erro: Esperado 'World!', mas obteve '%s'", result);
    free(result);
}

Test(ft_strjoin, empty_second_string) {
    char *s1 = "Hello, ";
    char *s2 = "";
    char *result = ft_strjoin(s1, s2);

    cr_assert_str_eq(result, "Hello, ", "Erro: Esperado 'Hello, ', mas obteve '%s'", result);
    free(result);
}

Test(ft_strjoin, both_strings_empty) {
    char *s1 = "";
    char *s2 = "";
    char *result = ft_strjoin(s1, s2);

    cr_assert_str_eq(result, "", "Erro: Esperado string vazia, mas obteve '%s'", result);
    free(result);
}

Test(ft_strjoin, null_first_string) {
    char *s1 = NULL;
    char *s2 = "World!";
    char *result = ft_strjoin(s1, s2);

    cr_assert_null(result, "Erro: Esperado NULL quando s1 é NULL.");
}

Test(ft_strjoin, null_second_string) {
    char *s1 = "Hello, ";
    char *s2 = NULL;
    char *result = ft_strjoin(s1, s2);

    cr_assert_null(result, "Erro: Esperado NULL quando s2 é NULL.");
}

Test(ft_strjoin, null_both_strings) {
    char *s1 = NULL;
    char *s2 = NULL;
    char *result = ft_strjoin(s1, s2);

    cr_assert_null(result, "Erro: Esperado NULL quando ambas as strings são NULL.");
}
