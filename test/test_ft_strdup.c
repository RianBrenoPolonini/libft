/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 07:29:59 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/04 07:30:43 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "libft.h"
#include <string.h>

Test(ft_strdup, basic_tests) {
    const char *str = "Hello World!";
    char *dup = ft_strdup(str);
    
    cr_assert_str_eq(dup, str, "Erro: A string duplicada não é igual à original.");
    cr_assert_not_null(dup, "Erro: ft_strdup retornou NULL para uma string válida.");
    
    free(dup);
}

Test(ft_strdup, empty_string) {
    const char *str = "";
    char *dup = ft_strdup(str);
    
    cr_assert_str_eq(dup, str, "Erro: A duplicata da string vazia não é igual à original.");
    cr_assert_not_null(dup, "Erro: ft_strdup retornou NULL para uma string vazia.");
    
    free(dup);
}

Test(ft_strdup, null_string) {
    char *dup = ft_strdup(NULL);
    
    cr_assert_null(dup, "Erro: ft_strdup não deve duplicar uma string nula.");
}

Test(ft_strdup, long_string) {
    const char *str = "Esta é uma string muito longa para testar a função ft_strdup corretamente.";
    char *dup = ft_strdup(str);
    
    cr_assert_str_eq(dup, str, "Erro: A string duplicada não é igual à original.");
    cr_assert_not_null(dup, "Erro: ft_strdup retornou NULL para uma string longa.");
    
    free(dup);
}

Test(ft_strdup, identical_strings) {
    const char *str = "Identical String";
    char *dup1 = ft_strdup(str);
    char *dup2 = ft_strdup(str);

    cr_assert_str_eq(dup1, str, "Erro: A primeira duplicata não é igual à original.");
    cr_assert_str_eq(dup2, str, "Erro: A segunda duplicata não é igual à original.");
    cr_assert_neq(dup1, dup2, "Erro: Ambas as duplicatas devem ser em locais diferentes da memória.");

    free(dup1);
    free(dup2);
}
