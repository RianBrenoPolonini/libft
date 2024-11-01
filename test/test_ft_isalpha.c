#include <criterion/criterion.h>
#include "libft.h"
#include <ctype.h>

Test(ft_isalpha, basic_tests) {
    for (int i = 0; i < 256; i++) {
        cr_assert_eq(ft_isalpha(i), isalpha(i) ? 1 : 0, 
                     "Erro: Esperado %d para o caractere %c, mas obteve %d", 
                     isalpha(i) ? 1 : 0, i, ft_isalpha(i));
    }
}