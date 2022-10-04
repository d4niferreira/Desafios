/* Alunos: Daniele Ferreira, Lucas Justino, João Pedro*/

#include <stdio.h>
#include <stdlib.h>

void gerarMatriz(char **matriz_entrada,int n, int m )
{
    int matriz_saida[n][m];
    int k = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            matriz_saida[i][j] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            /*
            (i-1, j-1)  (i-1, j)  (i-1, j+1)    |     EC  C   DC
            (i, j-1)    (i, j)    (i, j+1)      |     E   9   D
            (i+1, j-1)  (i+1, j)  (i+1, j+1)    |     EB  B   DB
            */
            if (matriz_entrada[i][j] == '*')
            {
                // verificar se é borda 
                if (i - 1 >= 0)
                {
                    matriz_saida[i - 1][j]++; // C
                    if (j - 1 >= 0)
                        matriz_saida[i - 1][j - 1]++; // EC
                    if (j + 1 < m)
                        matriz_saida[i - 1][j + 1]++; // DC
                }
                if (i + 1 <= n)
                {
                    matriz_saida[i + 1][j]++; // B
                    if (j - 1 >= 0)
                        matriz_saida[i+1][j-1]++; // EB 
                    if (j + 1 < m)
                        matriz_saida[i + 1][j + 1]++; // DB
                }
                if (j - 1 >= 0)
                    matriz_saida[i][j - 1]++; // E
                if (j + 1 < m)
                    matriz_saida[i][j + 1]++; // D
                matriz_saida[i][j] = 10000;   // 9
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matriz_saida[i][j] >= 10000)
                printf("*");
            else
                printf("%d", matriz_saida[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n, m;

    char **matriz_entrada;
    char caracter;
    int numero_field = 1;

    scanf("%d %d", &n, &m);
    scanf("%c", &caracter);
    while (n != 0 && m != 0 && n > 0 && n <= 100 && m > 0 && m <= 100)
    {
        // aloca um vetor de linha 'n' ponteiros para linhas
        matriz_entrada = malloc(n * sizeof(int *));

        // aloca cada uma das linhas (vetores de 'm' inteiros)
        for (int i = 0; i < n; i++)
            matriz_entrada[i] = malloc(m * sizeof(int));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%c", &caracter);
                matriz_entrada[i][j] = caracter;
            }
            scanf("%c", &caracter);
        }
        printf("\nField #%d\n",numero_field);
        numero_field++;
        gerarMatriz(matriz_entrada, n, m);
        scanf("%d %d", &n, &m);
        scanf("%c", &caracter);
    }
    free ( matriz_entrada);
}
