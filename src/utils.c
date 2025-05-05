#include "cub3d.h"


int find_first_delimiter_position(const char *str, const char *delim) {
    // Encontra o primeiro caractere da string que seja um delimitador
    const char *pos = strpbrk(str, delim);

    // Se encontrar o delimitador, retorna a posição (índice) na string
    if (pos != NULL) {
        return pos - str;
    }

    return -1;
}

  
char *my_strtok_first(const char *str, const char *delim) {
    char	*end;
	char	*token;
	size_t	length;

    // Encontra a posição do primeiro delimitador na string
    *end = strpbrk(str, delim);

    if (end == NULL) {
        // Não encontrou delimitador, retorna a string inteira
        return strdup(str);
    }

    // Aloca memória para a substring até o primeiro delimitador
    size_t length = end - str;
    char *token = (char *)malloc(length + 1);

    if (token == NULL) {
        return NULL;  // Se falhar na alocação de memória
    }

    // Copia a substring até o primeiro delimitador
    strncpy(token, str, length);
    token[length] = '\0';  // Garante que a substring termina corretamente

    return token;
}
