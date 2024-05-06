#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void criar_arquivo(const char *nomeArq) {
    FILE *arquivo = fopen(nomeArq, "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo %s\n", nomeArq);
        return;
    }

    // Escrever conteúdo no arquivo
    fprintf(arquivo, "Conteudo do arquivo %s\n", nomeArq);

    fclose(arquivo);
}

void verificar(const char *nomeArq) {
    // Simulando algum processamento
    FILE *arquivo = fopen(nomeArq, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nomeArq);
        return;
    }


}

double calcular_tempo_execucao(const char *nomeArq) {
    clock_t inicio, fim;
    double tempo_execucao;

    inicio = clock();
    verificar(nomeArq);
    fim = clock();

    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    return tempo_execucao;
}

int main() {
   
    const char *arquivos[] = {"arquivo1.txt", "arquivo2.txt", "arquivo3.txt"};
    

    // Criar e processar cada arquivo
    for (int i = 0; i < 3; i++) {
        criar_arquivo(arquivos[i]);
        double tempo_execucao = calcular_tempo_execucao(arquivos[i]);
        printf("O arquivo %s foi processado em %.6f segundos.\n", arquivos[i], tempo_execucao);
    }

    return 0;
}
