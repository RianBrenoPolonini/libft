/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:59:30 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/05 14:16:21 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "libft.h"

Test(ft_split, empty_string) {
    char **result = ft_split("", ' ');
    cr_assert_not_null(result);
    cr_assert_null(result[0]);
    free(result);
}

Test(ft_split, no_delimiter) {
    char **result = ft_split("HelloWorld", ' ');
    cr_assert_not_null(result);
    cr_assert_str_eq(result[0], "HelloWorld");
    cr_assert_null(result[1]);
    free(result[0]); // Libera a substring
    free(result);    // Libera o array de ponteiros
}

Test(ft_split, single_delimiter) {
    char **result = ft_split("Hello World", ' ');
    cr_assert_not_null(result);
    cr_assert_str_eq(result[0], "Hello");
    cr_assert_str_eq(result[1], "World");
    cr_assert_null(result[2]);
    free(result[0]);
    free(result[1]);
    free(result);
}

Test(ft_split, multiple_delimiters) {
    char **result = ft_split("Hello  World  ", ' ');
    cr_assert_not_null(result);
    cr_assert_str_eq(result[0], "Hello");
    cr_assert_str_eq(result[1], "World");
    cr_assert_null(result[2]);
    free(result[0]);
    free(result[1]);
    free(result);
}

Test(ft_split, delimiters_at_both_ends) {
    char **result = ft_split("  Hello World  ", ' ');
    cr_assert_not_null(result);
    cr_assert_str_eq(result[0], "Hello");
    cr_assert_str_eq(result[1], "World");
    cr_assert_null(result[2]);
    free(result[0]);
    free(result[1]);
    free(result);
}

Test(ft_split, consecutive_delimiters) {
    char **result = ft_split("Hello,,World", ',');
    cr_assert_not_null(result);
    cr_assert_str_eq(result[0], "Hello");
    cr_assert_str_eq(result[1], "World");
    cr_assert_null(result[2]);
    free(result[0]);
    free(result[1]);
    free(result);
}

Test(ft_split, only_delimiters) {
    char **result = ft_split(",,,,", ',');
    cr_assert_not_null(result);
    cr_assert_null(result[0]);
    cr_assert_null(result[1]);
    free(result);
}

Test(ft_split, string_with_special_characters) {
    // Para este teste, precisamos ajustar a função ou dividir em testes
    // diferentes para cada delimitador.
    char **result = ft_split("Hello,World! How are you?", ' '); // Usando espaço como delimitador
    cr_assert_not_null(result);
    cr_assert_str_eq(result[0], "Hello,World!");
    cr_assert_str_eq(result[1], "How");
    cr_assert_str_eq(result[2], "are");
    cr_assert_str_eq(result[3], "you?");
    cr_assert_null(result[4]);
    free(result[0]);
    free(result[1]);
    free(result[2]);
    free(result[3]);
    free(result);
}
