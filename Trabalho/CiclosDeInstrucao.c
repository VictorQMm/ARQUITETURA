#include <stdio.h>
#include <stdbool.h>

#define MEM_SIZE 256

// Definindo os registradores
int PC = 0; // Program Counter
int IR = 0; // Instruction Register
int MAR = 0; // Memory Address Register
int MBR = 0; // Memory Buffer Register
bool ZERO = false; // Flag Zero
bool NEGATIVE = false; // Flag Negativo

// Definindo a memória
int memory[MEM_SIZE];

// Funções auxiliares
void fetch() {
    MAR = PC;
    MBR = memory[MAR];
    IR = MBR;
    PC++;
}

void decode_execute() {
    int opcode = IR >> 24; // Os 8 bits mais significativos para o opcode
    int address = IR & 0xFFFFFF; // Os 24 bits menos significativos para o endereço

    switch (opcode) {
        case 0: // NOOP
            break;
        case 1: // LOAD
            MAR = address;
            MBR = memory[MAR];
            break;
        case 2: // STORE
            MAR = address;
            memory[MAR] = MBR;
            break;
        case 3: // ADD
            MAR = address;
            MBR += memory[MAR];
            break;
        case 4: // SUB
            MAR = address;
            MBR -= memory[MAR];
            break;
        case 5: // JMP
            PC = address;
            break;
        case 6: // JZ (Jump if Zero)
            if (ZERO) {
                PC = address;
            }
            break;
        case 7: // JN (Jump if Negative)
            if (NEGATIVE) {
                PC = address;
            }
            break;
    }

    // Atualizando as flags
    ZERO = (MBR == 0);
    NEGATIVE = (MBR >> 31) & 1; // Verifica o bit mais significativo
}

void execute_program() {
    while (PC < MEM_SIZE && memory[PC] != 0) {
        fetch();
        decode_execute();
    }
}


int main() {
    // Exemplo de programa na memória
    memory[0] = 0x010000FB; // LOAD 251
    memory[1] = 0x030000FC; // ADD 252
    memory[2] = 0x030000FD; // ADD 253
    memory[3] = 0x020000FE; // STORE 254
    memory[4] = 0x00000000; // NOOP

    // Valores iniciais na memória
    memory[251] = 5;
    memory[252] = 10;
    memory[253] = 15;

    // Executar o programa
    execute_program();

    printf("PC: %d\n", PC);
    printf("IR: %d\n", IR);
    printf("MAR: %d\n", MAR);
    printf("MBR: %d\n", MBR);
    printf("ZERO: %d\n", ZERO);
    printf("NEGATIVE: %d\n", NEGATIVE);

    return 0;
}
