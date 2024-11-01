#include <criterion/criterion.h>
#include "libft.h"
#include <string.h>

Test(ft_strlen, empty_string) {
    const char *test = "";
    cr_assert_eq(ft_strlen(test), strlen(test), "Erro: Esperado 0 para uma string vazia, mas obteve %zu", ft_strlen(test));
}

Test(ft_strlen, normal_string) {
    const char *test = "Hello, World!";
    cr_assert_eq(ft_strlen(test), strlen(test), "Erro: Esperado %zu, mas obteve %zu", strlen(test), ft_strlen(test));
}

Test(ft_strlen, spaces) {
    const char *test = "   ";
    cr_assert_eq(ft_strlen(test), strlen(test), "Erro: Esperado %zu, mas obteve %zu", strlen(test), ft_strlen(test));
}

Test(ft_strlen, special_characters) {
    const char *test = "123@#*!";
    cr_assert_eq(ft_strlen(test), strlen(test), "Erro: Esperado %zu, mas obteve %zu", strlen(test), ft_strlen(test));
}

Test(ft_strlen, null_char_in_middle) {
    const char *test = "abc\0def";
    cr_assert_eq(ft_strlen(test), strlen(test), "Erro: Esperado %zu, mas obteve %zu", strlen(test), ft_strlen(test));
}

Test(ft_strlen, long_string) {
    const char *test = "This is a very long string for testing the ft_strlen function's behavior.";
    cr_assert_eq(ft_strlen(test), strlen(test), "Erro: Esperado %zu, mas obteve %zu", strlen(test), ft_strlen(test));
}

Test(ft_strlen, utf8_characters) {
    const char *test = "Olá, mundo! 🌍";
    cr_assert_eq(ft_strlen(test), strlen(test), "Erro: Esperado %zu, mas obteve %zu", strlen(test), ft_strlen(test));
}