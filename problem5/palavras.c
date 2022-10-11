/*
        Daniele Ferreira da Silva - 2019.1.08.033
        José Flávio Lopes         - 2019.1.08.045
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

char **entrada;
int linhas, colunas;

bool busca_Diagonal(char *palavra, int k, int i, int j, bool dce, bool dcd, bool dbe, bool dbd)
{   /* vizinhança
    DCE  1  DCD
    3   x   4
    DBE  6  DBD
    */
   if (k  == strlen(palavra)) // achou a palavra inteira
        return true;  
    if( dce == true && i - 1 >= 0 && j - 1 >= 0 && toupper(palavra[k]) == toupper(entrada[i - 1][j - 1]) ) // dce
        dce = busca_Diagonal(palavra, k + 1, i - 1, j - 1, true, false, false, false);
    else    
        dce = false;
    if( dcd == true && i - 1 >= 0 && j + 1 < colunas && toupper(palavra[k]) == toupper(entrada[i - 1][j + 1]) ) // dcd
        dcd = busca_Diagonal(palavra, k + 1, i - 1, j + 1, false, true, false, false);
    else    
        dcd = false;
    if( dbe == true && i + 1 < linhas && j - 1 >= 0 && toupper(palavra[k]) == toupper(entrada[i + 1][j - 1]) ) // dbe
        dbe = busca_Diagonal(palavra, k + 1, i + 1, j - 1, false, false, true, false);
    else    
        dbe = false;
    if( dbd == true && i + 1 < linhas && j + 1 < colunas && toupper(palavra[k]) == toupper(entrada[i + 1][j + 1]) ) // dbd
        dbd = busca_Diagonal(palavra, k + 1, i + 1, j + 1, false, false, false, true);
    else    
        dbd = false;

    //retorno 
    return dce || dcd || dbe || dbd;

    
}

bool busca_Horizontal(char *palavra, int k, int i, int j, bool esquerda, bool direita)
{
    if (k  == strlen(palavra)) // achou a palavra inteira
        return true;  
    if( direita == true && i - 1 >= 0 && toupper(palavra[k]) == toupper(entrada[i][j + 1]) ) // direita
        direita = busca_Horizontal(palavra, k + 1, i, j + 1, false, true);
    else    
        direita = false;
    if (esquerda == true && i + 1 < linhas && toupper(palavra[k]) == toupper(entrada[i][j - 1])) // esquerda
        esquerda = busca_Horizontal(palavra, k + 1, i , j - 1, true, false);
    else 
        esquerda = false;
  
    //retorno 
    return esquerda || direita;
}

bool busca_Vertical(char *palavra, int k, int i, int j, bool cima, bool baixo)
{
    if (k  == strlen(palavra))  // achou a palavra inteira
        return true;  
    if( cima == true && i - 1 >= 0 && toupper(palavra[k]) == toupper(entrada[i - 1][j]) ) // cima
        cima = busca_Vertical(palavra, k + 1, i - 1, j, true, false);
    else    
        cima = false;
    if (baixo == true && i + 1 < linhas && toupper(palavra[k]) == toupper(entrada[i + 1][j])) // baixo
        baixo = busca_Vertical(palavra, k + 1, i + 1, j, false, true);
    else 
        baixo = false;
  
    //retorno 
    return cima || baixo;
}


int main()
{

    int casos, buscas;
    int a, p, i, j;
    char palavra[51];

    scanf("%d", &casos);

    for (a = 0; a < casos; a++){
        scanf("%d %d", &linhas, &colunas);

        // aloca um vetor de LIN ponteiros para linhas
        entrada = malloc(linhas * sizeof(char *));

        // aloca cada uma das linhas (vetores de COL inteiros)
        for (int i = 0; i < linhas; i++)
            entrada[i] = malloc(colunas * sizeof(char));

        getchar();

        for (int i = 0; i < linhas; i++, getchar()){
            fgets(entrada[i], colunas + 1, stdin);
            entrada[i][colunas] = '\0';
        }

        scanf("%d", &buscas);
        getchar();

        for (p = 0; p < buscas; p++){
            fgets(palavra, 51, stdin);
            if(palavra[strlen(palavra) - 1] == '\n')
                palavra[strlen(palavra) - 1] = '\0';

            // percorer a matriz -> se encontra a letra verificar
            for (int i = 0; i < linhas; i++){
                for (int j = 0; j < colunas; j++){
                    if (toupper(entrada[i][j]) == toupper(palavra[0])){
                        if(busca_Vertical(palavra, 1, i, j , true, true)){ 
                            printf("%d %d\n", i +1 , j +1);
                            i = linhas;//sai do i
                            break; // sai do j
                        }else if (busca_Horizontal(palavra, 1, i,j, true, true)){
                            printf("%d %d\n", i+1 , j +1);
                            i = linhas;//sai do i
                            break;//sai do j
                        }else if ( busca_Diagonal(palavra, 1, i, j, true, true, true, true)){
                            printf("%d %d\n", i +1, j +1);
                            i = linhas;//sai do i
                            break;//sai do j
                        }
                    }
                }
            }
        }

        free(entrada);
        printf("\n");
    }

    return 0;
}

/*caça palavras
a palavra pode estar nas 8 direções
bola

alob

b
  o
    l
     a

     b
   o
  l
a

a
   l
    o
      b

      a
    l
  o
b

b
o
l
a

a
l
o
b
*/