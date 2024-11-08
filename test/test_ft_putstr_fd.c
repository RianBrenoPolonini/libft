/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putstr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:33:57 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/05 14:38:13 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <fcntl.h>
#include "libft.h"

Test(ft_putstr_fd, write_string_to_stdout) {
    char *str = "Hello, World!";

    int temp_fd = open("temp_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    cr_assert_neq(temp_fd, -1, "Failed to open temporary file for output");

    ft_putstr_fd(str, temp_fd);

    close(temp_fd);

    char buffer[50] = {0};
    temp_fd = open("temp_output.txt", O_RDONLY);
    cr_assert_neq(temp_fd, -1, "Failed to open temporary file for reading");
    read(temp_fd, buffer, 50);

    cr_assert_str_eq(buffer, "Hello, World!", "Expected output string to be 'Hello, World!'");

    close(temp_fd);
    unlink("temp_output.txt");
}

Test(ft_putstr_fd, write_null_string) {
    int temp_fd = open("temp_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    cr_assert_neq(temp_fd, -1, "Failed to open temporary file for output");

    ft_putstr_fd(NULL, temp_fd);

    close(temp_fd);

    char buffer[1] = {0};
    temp_fd = open("temp_output.txt", O_RDONLY);
    cr_assert_neq(temp_fd, -1, "Failed to open temporary file for reading");
    read(temp_fd, buffer, 1);

    cr_assert_eq(buffer[0], '\0', "Expected no output for NULL string");

    close(temp_fd);
    unlink("temp_output.txt");
}

Test(ft_putstr_fd, write_string_to_invalid_fd) {
    ft_putstr_fd("Should not crash", -1);
    cr_assert(true, "Expected ft_putstr_fd to handle invalid file descriptor gracefully without crashing");
}