/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:15:42 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/05 13:16:03 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "libft.h"
#include "libft.h"

Test(ft_itoa, positive_number) {
    char *result = ft_itoa(12345);
    cr_assert_str_eq(result, "12345", "Expected '12345', got '%s'", result);
    free(result);
}

Test(ft_itoa, negative_number) {
    char *result = ft_itoa(-67890);
    cr_assert_str_eq(result, "-67890", "Expected '-67890', got '%s'", result);
    free(result);
}

Test(ft_itoa, zero) {
    char *result = ft_itoa(0);
    cr_assert_str_eq(result, "0", "Expected '0', got '%s'", result);
    free(result);
}

Test(ft_itoa, negative_one) {
    char *result = ft_itoa(-1);
    cr_assert_str_eq(result, "-1", "Expected '-1', got '%s'", result);
    free(result);
}

Test(ft_itoa, largest_positive_int) {
    char *result = ft_itoa(2147483647);
    cr_assert_str_eq(result, "2147483647", "Expected '2147483647', got '%s'", result);
    free(result);
}

Test(ft_itoa, smallest_negative_int) {
    char *result = ft_itoa(-2147483648);
    cr_assert_str_eq(result, "-2147483648", "Expected '-2147483648', got '%s'", result);
    free(result);
}

Test(ft_itoa, single_digit_positive) {
    char *result = ft_itoa(5);
    cr_assert_str_eq(result, "5", "Expected '5', got '%s'", result);
    free(result);
}

Test(ft_itoa, single_digit_negative) {
    char *result = ft_itoa(-3);
    cr_assert_str_eq(result, "-3", "Expected '-3', got '%s'", result);
    free(result);
}

Test(ft_itoa, maximum_digits) {
    char *result = ft_itoa(99999);
    cr_assert_str_eq(result, "99999", "Expected '99999', got '%s'", result);
    free(result);
}
