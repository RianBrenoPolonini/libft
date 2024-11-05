/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_striteri.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:26:07 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/05 14:28:12 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "libft.h"

void modify_char(unsigned int index, char *c) {
    *c = *c + index;
}

Test(ft_striteri, basic_test) {
    char str[] = "abc";
    ft_striteri(str, modify_char);
    cr_assert_str_eq(str, "ace", "Expected string to be 'ace' after applying ft_striteri");
}

Test(ft_striteri, empty_string) {
    char str[] = "";
    ft_striteri(str, modify_char);
    cr_assert_str_eq(str, "", "Expected empty string to remain empty");
}

Test(ft_striteri, null_function) {
    char str[] = "abc";
    ft_striteri(str, NULL);
    cr_assert_str_eq(str, "abc", "Expected string to remain unchanged when function is NULL");
}

Test(ft_striteri, null_string) {
    ft_striteri(NULL, modify_char);
    cr_assert(true, "Expected ft_striteri to handle NULL string gracefully without crashing");
}

Test(ft_striteri, single_char) {
    char str[] = "a";
    ft_striteri(str, modify_char);
    cr_assert_str_eq(str, "a", "Expected single character string to remain unchanged");
}
