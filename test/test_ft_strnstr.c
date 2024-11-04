/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strnstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 06:59:18 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/04 07:02:45 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "libft.h"
#include <string.h>

Test(ft_strnstr, basic_tests) {
    const char *str = "Hello World!";
    cr_assert_eq(ft_strnstr(str, "World", 12), str + 6, "Should find 'World' at position 6");
    cr_assert_eq(ft_strnstr(str, "!", 12), str + 11, "Should find '!' at position 11");
    cr_assert_eq(ft_strnstr(str, "", 12), str, "Empty needle should return haystack start");
    cr_assert_eq(ft_strnstr(str, "Hello World!!", 12), NULL, "Should not find longer needle");
    cr_assert_eq(ft_strnstr(str, "World", 5), NULL, "Should not find 'World' within limit 5");
}
