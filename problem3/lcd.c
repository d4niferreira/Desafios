#include <stdio.h>
#include <stdlib.h>

int numeros[6][5][3] = {
    { { 0, 1, 0 }, { 1, 0, 1 }, { 0, 0, 0 }, { 1, 0, 1 }, { 0, 1, 0 } },
    { { 0, 0, 0 }, { 0, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 }, { 0, 0, 0 } },
    { { 0, 1, 0 }, { 0, 0, 1 }, { 0, 1, 0 }, { 1, 0, 0 }, { 0, 1, 0 } },
    { { 0, 1, 0 }, { 0, 0, 1 }, { 0, 1, 0 }, { 0, 0, 1 }, { 0, 1, 0 } },
    { { 0, 0, 0 }, { 1, 0, 1 }, { 0, 1, 0 }, { 0, 0, 1 }, { 0, 0, 0 } },
    { { 0, 1, 0 }, { 1, 0, 0 }, { 0, 1, 0 }, { 0, 0, 1 }, { 0, 1, 0 } }
};

void exibeLinha(int numero, int linha, int s);

int main() {

    int i, j, k, s = 4;
    int n[8], tamanhoN;

    n[0] = 0;
    n[1] = 1;
    n[2] = 2;
    n[3] = 3;
    n[4] = 4;
    n[5] = 5;
    tamanhoN = 6;

    for (i = 0; i < 5; i++) {
        if (i % 2 == 0) {
            for (j = 0; j < tamanhoN; j++) {
                exibeLinha(n[j], i, s);
                printf(" ");
            }
            printf("\n");
        } else {
            for (j = 0; j < s; j++) {
                for (k = 0; k < tamanhoN; k++) {
                    exibeLinha(n[k], i, s);
                    printf(" ");
                }
                printf("\n");
            }
        }
    }

    return 0;

}

void exibeLinha(int numero, int linha, int s) {

    int i, j;

    for (i = 0; i < 3; i++) {
        if (linha % 2 == 0) {
            for (j = 0; j < s; j++) {
                if (numeros[numero][linha][i] == 1) {
                    printf("-");
                } else {
                    printf(" ");
                }
            }
        } else {
            if (numeros[numero][linha][i] == 0) {
                for (j = 0; j < s; j++) {
                    printf(" ");
                }
            } else {
                if (i == 0) {
                    for (j = 1; j < s; j++) {
                        printf(" ");
                    }
                }
                printf("|");
                if (i == 2) {
                    for (j = 1; j < s; j++) {
                        printf(" ");
                    }
                }
            }
        }
    }

}