#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    char frase[100];
    char disco1[100] = {0}, disco2[100] = {0};
    int len, i, j = 0, k = 0;

    printf("Insira uma frase: ");
    fgets(frase, sizeof(frase), stdin);

    // Remover a nova linha '\n' capturada pelo fgets, se houver
    len = strlen(frase);
    if (len > 0 && frase[len - 1] == '\n') {
        frase[len - 1] = '\0';
        len--;
    }

    // Distribuir os caracteres entre Disco 1 e Disco 2
    for (i = 0; i < len; i++) {
        if (i % 2 == 0) {
            disco1[j++] = frase[i];
        } else {
            disco2[k++] = frase[i];
        }
    }

    // Certificar-se de que as strings terminem com nulo
    disco1[j] = '\0';
    disco2[k] = '\0';

    // Imprimir as duas partes
    printf("RAID 0:\n");
    printf("Disco 1: %s\n", disco1);
    printf("Disco 2: %s\n", disco2);

    return 0;
}