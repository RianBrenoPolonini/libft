/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_calloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 07:24:30 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/04 07:26:50 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "libft.h"
#include <stdlib.h>

Test(ft_calloc, basic_allocation) {
    size_t count = 5;
    size_t size = sizeof(int);

    int *arr = (int *)ft_calloc(count, size);
    cr_assert_not_null(arr, "Erro: ft_calloc retornou NULL para uma alocação válida.");

    for (size_t i = 0; i < count; i++) {
        cr_assert_eq(arr[i], 0, "Erro: A memória não foi zerada corretamente na posição %zu.", i);
    }

    free(arr);
}

Test(ft_calloc, large_allocation) {
    size_t count = 1000;
    size_t size = sizeof(double);

    double *arr = (double *)ft_calloc(count, size);
    cr_assert_not_null(arr, "Erro: ft_calloc retornou NULL para uma alocação de grande tamanho.");

    for (size_t i = 0; i < count; i++) {
        cr_assert_eq(arr[i], 0.0, "Erro: A memória não foi zerada corretamente na posição %zu.", i);
    }

    free(arr);
}

Test(ft_calloc, zero_allocation) {
    int *arr = (int *)ft_calloc(0, sizeof(int));
    cr_assert_not_null(arr, "Erro: ft_calloc retornou NULL para uma alocação de tamanho zero.");
    free(arr);

    arr = (int *)ft_calloc(5, 0);
    cr_assert_not_null(arr, "Erro: ft_calloc retornou NULL para uma alocação com tamanho de elemento zero.");
    free(arr);
}

Test(ft_calloc, overflow_allocation) {
    size_t count = (size_t)-1;
    size_t size = 2;

    void *ptr = ft_calloc(count, size);
    cr_assert_null(ptr, "Erro: ft_calloc não retornou NULL em um caso de overflow.");
}
