#include <stdio.h>
#include <stdlib.h>

int main() {
    int cilindro;
    int qtdCilindro;

    printf("Tamanho do cilindro: ");
    scanf("%d", &cilindro);
    
    printf("Informe a quantidade de pedidos: ");
    scanf("%d", &qtdCilindro); 

    int requisicoes[40] = {0}; 

    for (int i = 0; i < qtdCilindro; i++) {
        printf("Informe o %d pedido de cilindro: ", i + 1);
        scanf("%d", &requisicoes[i]);
    }

    int posicaoAtual = 0;

    printf("FCFS:\n");
    printf("Atendimento: %d ", posicaoAtual);

    for (int i = 0; i < qtdCilindro; i++) {
        posicaoAtual = requisicoes[i];
        printf("-- %d --", posicaoAtual);
    }
    
    printf("\nValores marcados no array:\n");

    for (int i = 0; i < qtdCilindro; i++) {
        if (requisicoes[i] != 0) {
            printf("Posicao %d: XX\n", requisicoes[i]);
        }
    }

    return 0;
}
