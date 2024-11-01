# Projeto Libft - Checklist de Funções

## Parte 1 - Funções da LibC (Mandatórias)

Essas são funções da biblioteca padrão C que você deve recriar com o prefixo `ft_`:

- [x] `ft_isalpha` — Verifica se o caractere é alfabético.
- [x] `ft_isdigit` — Verifica se o caractere é um dígito.
- [ ] `ft_isalnum` — Verifica se o caractere é alfanumérico.
- [ ] `ft_isascii` — Verifica se o caractere está no conjunto ASCII.
- [ ] `ft_isprint` — Verifica se o caractere é imprimível.
- [x] `ft_strlen` — Retorna o comprimento de uma string.
- [ ] `ft_memset` — Preenche um bloco de memória com um valor constante.
- [ ] `ft_bzero` — Zera um bloco de memória.
- [ ] `ft_memcpy` — Copia blocos de memória.
- [ ] `ft_memmove` — Move blocos de memória, lidando com sobreposição.
- [ ] `ft_strlcpy` — Copia uma string para um buffer com limite de tamanho.
- [ ] `ft_strlcat` — Concatena strings com limite de tamanho do buffer.
- [ ] `ft_toupper` — Converte caractere para maiúscula.
- [ ] `ft_tolower` — Converte caractere para minúscula.
- [ ] `ft_strchr` — Localiza um caractere em uma string.
- [ ] `ft_strrchr` — Localiza a última ocorrência de um caractere em uma string.
- [ ] `ft_strncmp` — Compara duas strings até um certo número de caracteres.
- [ ] `ft_memchr` — Pesquisa um valor em um bloco de memória.
- [ ] `ft_memcmp` — Compara blocos de memória.
- [ ] `ft_strnstr` — Localiza uma substring dentro de outra, com limite de tamanho.
- [ ] `ft_atoi` — Converte uma string em um inteiro.

Para as funções que utilizam **`malloc`**:

- [ ] `ft_calloc` — Aloca memória e inicializa todos os bytes com zero.
- [ ] `ft_strdup` — Duplica uma string.

---

## Parte 2 - Funções Adicionais (Mandatórias)

Essas funções são adicionais e não fazem parte diretamente da LibC:

- [ ] `ft_substr` — Cria uma substring de uma string.
- [ ] `ft_strjoin` — Concatena duas strings em uma nova string.
- [ ] `ft_strtrim` — Remove caracteres especificados do início e do fim de uma string.
- [ ] `ft_split` — Divide uma string em um array de strings com base em um delimitador.
- [ ] `ft_itoa` — Converte um número inteiro para uma string.
- [ ] `ft_strmapi` — Aplica uma função a cada caractere de uma string, criando uma nova string.
- [ ] `ft_striteri` — Aplica uma função a cada caractere de uma string (modificável).
- [ ] `ft_putchar_fd` — Escreve um caractere em um file descriptor.
- [ ] `ft_putstr_fd` — Escreve uma string em um file descriptor.
- [ ] `ft_putendl_fd` — Escreve uma string seguida de uma nova linha em um file descriptor.
- [ ] `ft_putnbr_fd` — Escreve um número inteiro em um file descriptor.

---

## Parte Bônus - Funções para Manipulação de Listas (Opcional)

Se a parte obrigatória estiver perfeita, implemente as seguintes funções de manipulação de listas:

- [ ] `ft_lstnew` — Cria um novo nó de lista.
- [ ] `ft_lstadd_front` — Adiciona um nó no início da lista.
- [ ] `ft_lstsize` — Conta o número de nós na lista.
- [ ] `ft_lstlast` — Retorna o último nó da lista.
- [ ] `ft_lstadd_back` — Adiciona um nó no final da lista.
- [ ] `ft_lstdelone` — Libera a memória de um nó, aplicando uma função de deleção ao conteúdo.
- [ ] `ft_lstclear` — Libera a memória de todos os nós de uma lista.
- [ ] `ft_lstiter` — Itera sobre a lista aplicando uma função em cada nó.
- [ ] `ft_lstmap` — Cria uma nova lista resultante da aplicação de uma função em cada nó.

---

Esse checklist cobre todas as funções obrigatórias e bônus que você precisará implementar na **libft**.
