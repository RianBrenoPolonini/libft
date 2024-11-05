/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putstr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfaria-p <rfaria-p@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:33:57 by rfaria-p          #+#    #+#             */
/*   Updated: 2024/11/05 14:34:12 by rfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <fcntl.h>
#include "libft.h"

Test(ft_putstr_fd, write_string_to_stdout) {
    char *str = "Hello, World!";
    
    // Redirecionar a saída padrão para um arquivo temporário
    int temp_fd = open("temp_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    cr_assert_neq(temp_fd, -1, "Failed to open temporary file for output");

    // Escrever a string usando a função
    ft_putstr_fd(str, temp_fd);
    
    // Fechar o descritor de arquivo temporário
    close(temp_fd);

    // Ler o conteúdo do arquivo temporário
    char buffer[50] = {0}; // Buffer para armazenar a string + terminador nulo
    temp_fd = open("temp_output.txt", O_RDONLY);
    cr_assert_neq(temp_fd, -1, "Failed to open temporary file for reading");
    read(temp_fd, buffer, 50); // Ler até 50 bytes

    // Verificar se a saída é a esperada
    cr_assert_str_eq(buffer, "Hello, World!", "Expected output string to be 'Hello, World!'");

    // Fechar e remover o arquivo temporário
    close(temp_fd);
    unlink("temp_output.txt");
}

Test(ft_putstr_fd, write_null_string) {
    // Testar escrever uma string nula
    int temp_fd = open("temp_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    cr_assert_neq(temp_fd, -1, "Failed to open temporary file for output");

    // Passar uma string nula para a função
    ft_putstr_fd(NULL, temp_fd);
    
    // Fechar o descritor de arquivo temporário
    close(temp_fd);

    // Ler o conteúdo do arquivo temporário
    char buffer[1] = {0}; // Buffer para armazenar a string + terminador nulo
    temp_fd = open("temp_output.txt", O_RDONLY);
    cr_assert_neq(temp_fd, -1, "Failed to open temporary file for reading");
    read(temp_fd, buffer, 1); // Ler 1 byte

    // Verificar que nada foi escrito no arquivo
    cr_assert_eq(buffer[0], '\0', "Expected no output for NULL string");

    // Fechar e remover o arquivo temporário
    close(temp_fd);
    unlink("temp_output.txt");
}

Test(ft_putstr_fd, write_string_to_invalid_fd) {
    // Testar escrever em um descritor de arquivo inválido
    ft_putstr_fd("Should not crash", -1); // Não deve causar falha, mas não deve produzir saída
    cr_assert(true, "Expected ft_putstr_fd to handle invalid file descriptor gracefully without crashing");
}