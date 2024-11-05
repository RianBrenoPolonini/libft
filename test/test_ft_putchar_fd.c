/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putchar_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:30:23 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/05 14:31:52 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <fcntl.h>
#include "libft.h"

Test(ft_putchar_fd, write_character_to_stdout) {
    char c = 'A';

    int temp_fd = open("temp_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    cr_assert_neq(temp_fd, -1, "Failed to open temporary file for output");

    ft_putchar_fd(c, temp_fd);

    close(temp_fd);

    char buffer[2] = {0};
    temp_fd = open("temp_output.txt", O_RDONLY);
    cr_assert_neq(temp_fd, -1, "Failed to open temporary file for reading");
    read(temp_fd, buffer, 1);

    cr_assert_str_eq(buffer, "A", "Expected output character to be 'A'");

    close(temp_fd);
    unlink("temp_output.txt");
}

Test(ft_putchar_fd, write_character_to_invalid_fd) {
    char c = 'B';

    ft_putchar_fd(c, -1);
    cr_assert(true, "Expected ft_putchar_fd to handle invalid file descriptor gracefully without crashing");
}
