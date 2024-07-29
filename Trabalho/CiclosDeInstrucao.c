#include <stdio.h>
#include <string.h>
#include <math.h>

typedef enum {
    Instru000001 = 1,
    Instru000010 = 2,
    Instru000011 = 3,
    Instru000100 = 4,
    Instru000101 = 5,
    Instru000110 = 6,
    Instru000111 = 7,
    Instru001000 = 8,
    Instru001010 = 9,
    Instru001011 = 10,
    Instru001111 = 11,
    Instru001100 = 12
} TipoInstrucao;

typedef struct {
    TipoInstrucao tipo;
    int operando1;
    int operando2;
} Instrucao;

int memoria[256];
Instrucao instrucaoo[50];

int CP = 0; // Contador
int ACC = 0; // Acumulador
int MBR = 0; 
int numInstru = 0; 

TipoInstrucao obterInstr(char* instrucao) {
    if (strcmp(instrucao, "000001") == 0) return Instru000001;
    if (strcmp(instrucao, "000010") == 0) return Instru000010;
    if (strcmp(instrucao, "000011") == 0) return Instru000011;
    if (strcmp(instrucao, "000100") == 0) return Instru000100;
    if (strcmp(instrucao, "000101") == 0) return Instru000101;
    if (strcmp(instrucao, "000110") == 0) return Instru000110;
    if (strcmp(instrucao, "000111") == 0) return Instru000111;
    if (strcmp(instrucao, "001000") == 0) return Instru001000;
    if (strcmp(instrucao, "001010") == 0) return Instru001010;
    if (strcmp(instrucao, "001011") == 0) return Instru001011;
    if (strcmp(instrucao, "001111") == 0) return Instru001111;
    if (strcmp(instrucao, "001100") == 0) return Instru001100;
    return Instru000001; 
}

void iniciar() {
    char instrucao[10];
    int operando1, operando2;

    printf("Insira as instrucoees do programa. Digite 'END' para finalizar.\n");

    while (1) {
        printf("Instrucao: ");
        scanf("%s", instrucao); 
        if (strcmp(instrucao, "001100") == 0) break; 

        TipoInstrucao tipo = obterInstr(instrucao);
        printf("Operando1: ");
        scanf("%d", &operando1);

        printf("Operando2: ");
        scanf("%d", &operando2);
        

        instrucaoo[numInstru].tipo = tipo;
        instrucaoo[numInstru].operando1 = operando1;
        instrucaoo[numInstru].operando2 = operando2;
        numInstru++; 
    }
}

void executar() {
    while (CP < numInstru) { 
        Instrucao instr = instrucaoo[CP]; 
        switch (instr.tipo) { 
            case Instru000001:
            printf("CP: %d\n", CP);
                break; 
            case Instru000010:
                MBR = memoria[instr.operando1]; // Carrega o valor em MBR
                ACC = MBR; //  MBR -> acumulador
                printf(" ACC = %d, MBR = %d, CP = %d\n", ACC, MBR, CP);
                break;
            case Instru000011:
                MBR = ACC; // Acumulador -> MBR
                memoria[instr.operando1] = MBR; // MBR -> memória
                printf("ACC = %d, MBR = %d, CP = %d\n", ACC, MBR, CP);
                break;
            case Instru000100:
                MBR = memoria[instr.operando1]; // Carrega  memória no MBR
                ACC += MBR; // MBR -> acumulador
                printf("ACC = %d, MBR = %d, CP = %d\n", ACC, MBR, CP);
                break;
            case Instru000101:
                MBR = memoria[instr.operando1]; // Carrega memória no MBR
                ACC -= MBR; 
                printf("ACC = %d, MBR = %d, CP = %d\n", ACC, MBR, CP);
                break;
            case Instru000110:
                CP = instr.operando1 - 1; //ajusta o contador
                printf("CP = %d\n", CP);
                break;
            case Instru000111:
                if (ACC == 0) CP = instr.operando1 - 1; // Salta se o acumulador for zero
                printf("ACC = %d, CP = %d\n", ACC, CP);
                break;
            case Instru001000:
                if (ACC != 0) CP = instr.operando1 - 1; // Salta se o acumulador não for zero
                printf("ACC = %d, CP = %d\n", ACC, CP);
                break;
            case Instru001010: 
                MBR = (int)sqrt(MBR);
                printf("MBR = %d, CP = %d\n", MBR, CP);
                break;
            case Instru001011: 
                MBR = -MBR;
                printf("MBR = %d, CP = %d\n", MBR, CP);
                break;
            case Instru001111: 
                memoria[instr.operando1] = MBR; //MBR -> posição especificada da memória
                  printf("MBR = %d, Memoria[%d] = %d, CP = %d\n", MBR, instr.operando1, memoria[instr.operando1], CP);
                break;
            case Instru001100: 
            printf(" CP: %d\n", CP);
                break;
        }
        CP++; 

        printf("Valor final do acumulador: %d\n\n", ACC);
    }
}

int main() {
    memset(memoria, 0, sizeof(memoria)); // Inicializa a memória com zero
    iniciar(); 
    executar(); 
    return 0;
}
