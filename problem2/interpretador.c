#include <stdio.h>
#include <stdlib.h>

/*
Daniele Ferreira da Silva   2019.1.08.033
Douglas Felipe de Morais    2019.1.08.019
Gabriel Pereira Soares      2019.1.08.027
*/

void executa(int *ram, int *reg)
{
    int operacao, casos, d, n, execucoes = 0, i = 0;

    while (ram[i - 1] != 100)
    {
        scanf("%d\n", &ram[i]);
        if (ram[i] != 0) // ignora entradas 000
            i++;
    }

    for (int j = 0; j < i; j++)
    {
        operacao = ram[j] / 100;
        d = (ram[j] % 100) / 10;
        n = ram[j] % 10;

        switch (operacao)
        {
        case 0:
            // pula para a instrução cujo endereço está em no registrador[d] se o valor do registrador[n] != 0
            if (reg[n] != 0)
                j = reg[d] - 1;
            execucoes++;
            break;
        case 1:
            j = i; // para a execução
            execucoes++;
            break;
        case 2:
            reg[d] = n; // seta n para o registrador[d]
            execucoes++;
            break;
        case 3:
            reg[d] = (reg[d] + n) % 1000; // soma n ao registrador d
            execucoes++;
            break;
        case 4:
            reg[d] = (reg[d] * n) % 1000; // multiplica n ao registrador d
            execucoes++;
            break;
        case 5:
            reg[d] = reg[n]; // seta o valor do registrador[d] com o valor do registrador[n]
            execucoes++;
            break;
        case 6:
            reg[d] = (reg[d] + reg[n]) % 1000; // soma o valor do  registrador[n] ao valor do registrador[d]
            execucoes++;
            break;
        case 7:
            reg[d] = (reg[d] * reg[n]) % 1000; // multiplica o valor do  registrador[n] ao valor do registrador[d]
            execucoes++;
            break;
        case 8:
            reg[d] = ram[reg[n]]; // seta o registador[d] com o valor da RAM cujo endereço está em n
            execucoes++;
            break;
        case 9:
            ram[reg[n]] = reg[d]; // seta a ram[] cujo endereço está em n com o valor do registrador[d]
            execucoes++;
            break;
        }
    }
    printf("Execuções: %d\n", execucoes);
}

void reseta(int *ram, int *reg)
{
    for (int i = 0; i < 100; i++)
        ram[i] = 0;

    for (int i = 0; i < 10; i++)
        reg[i] = 0;
}

int main(void)
{
    int n, ram[1000] = {0}, reg[10] = {0};
    scanf("%d\n\n", &n);

    for (int i = 0; i < n; i++)
    {
        executa(ram, reg);
        reseta(ram, reg);
    }
}