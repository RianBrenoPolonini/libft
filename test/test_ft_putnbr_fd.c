/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putnbr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:44:19 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/05 14:45:28 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <fcntl.h>
#include "libft.h"

Test(ft_putnbr_fd, write_positive_number) {
    int temp_fd = open("temp_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    cr_assert_neq(temp_fd, -1, "Failed to open temporary file for output");

    ft_putnbr_fd(12345, temp_fd);
    
    close(temp_fd);

    char buffer[20] = {0};
    temp_fd = open("temp_output.txt", O_RDONLY);
    cr_assert_neq(temp_fd, -1, "Failed to open temporary file for reading");
    read(temp_fd, buffer, 20);

    cr_assert_str_eq(buffer, "12345", "Expected output string to be '12345'");

    close(temp_fd);
    unlink("temp_output.txt");
}

Test(ft_putnbr_fd, write_negative_number) {
    int temp_fd = open("temp_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    cr_assert_neq(temp_fd, -1, "Failed to open temporary file for output");

    ft_putnbr_fd(-6789, temp_fd);
    
    close(temp_fd);

    char buffer[20] = {0};
    temp_fd = open("temp_output.txt", O_RDONLY);
    cr_assert_neq(temp_fd, -1, "Failed to open temporary file for reading");
    read(temp_fd, buffer, 20);

    cr_assert_str_eq(buffer, "-6789", "Expected output string to be '-6789'");

    close(temp_fd);
    unlink("temp_output.txt");
}

Test(ft_putnbr_fd, write_zero) {
    int temp_fd = open("temp_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    cr_assert_neq(temp_fd, -1, "Failed to open temporary file for output");

    ft_putnbr_fd(0, temp_fd);
    
    close(temp_fd);

    char buffer[20] = {0};
    temp_fd = open("temp_output.txt", O_RDONLY);
    cr_assert_neq(temp_fd, -1, "Failed to open temporary file for reading");
    read(temp_fd, buffer, 20);

    cr_assert_str_eq(buffer, "0", "Expected output string to be '0'");

    close(temp_fd);
    unlink("temp_output.txt");
}

Test(ft_putnbr_fd, write_min_int) {
    int temp_fd = open("temp_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    cr_assert_neq(temp_fd, -1, "Failed to open temporary file for output");

    ft_putnbr_fd(-2147483648, temp_fd);
    
    close(temp_fd);

    char buffer[20] = {0};
    temp_fd = open("temp_output.txt", O_RDONLY);
    cr_assert_neq(temp_fd, -1, "Failed to open temporary file for reading");
    read(temp_fd, buffer, 20);

    cr_assert_str_eq(buffer, "-2147483648", "Expected output string to be '-2147483648'");

    close(temp_fd);
    unlink("temp_output.txt");
}

Test(ft_putnbr_fd, write_to_invalid_fd) {
    ft_putnbr_fd(42, -1);
    cr_assert(true, "Expected ft_putnbr_fd to handle invalid file descriptor gracefully without crashing");
}