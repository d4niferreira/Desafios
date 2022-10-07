/*	
*	Daniele Ferreira da Silva  2019.1.08.033
*	José Flávio Lopes		   2019.1.08.045
*/

#include <stdio.h>
#include <string.h>

#define DEBUG(x)

//ordenar
void quick(int rank[100][12], int esq, int dir){
    int pivo = esq, i,ch,j, id, tempo;
    for(i=esq+1;i<=dir;i++){        
        j = i;                      
        
		if( rank[j][9] != 0 && (rank[j][10] > rank[pivo][10] || rank[j][10] == rank[pivo][10] && rank[j][11] < rank[pivo][11] || rank[pivo][9] == 0)){
			id = rank[j][9];
            ch = rank[j][10]; 
			tempo = rank[j][11];

            while(j > pivo){           
				rank[j][9] = rank[j-1][9];
                rank[j][10] = rank[j-1][10];
				rank[j][11] = rank[j-1][11];
                j--;                    
            }
            rank[j][9] = id;
			rank[j][10] = ch;
			rank[j][11] = tempo;

            pivo++;                    
        }
    }
    if(pivo-1 >= esq){              
        quick(rank,esq,pivo-1);      
    }
    if(pivo+1 <= dir){              
        quick(rank,pivo+1,dir);      
    }
 }

void imprime(int matriz[100][12], int n){
	for (int i = 0; i < n; i++) {
		for (int j = 9; j < 12; j++) {
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int contaJogadores(int jog[100]){
	int cont = 0;
	for (int i = 0; i < 100; i++){
		if(jog[i] != 0)
			cont++;
	}
	return cont;	
}

int main () {

	char linha[20];
	int cmp,  // competidor 
	    prb,  // problema
		tmp;  // tempo
	char msg; // mensagem

	int rank[100][12] = {0}; 
	int jogadores[100] = {0};

	int nComp;
	int fim;
	int i;

	scanf ("%d\n", &nComp);
	//DEBUG ( printf ("nComp = %d\n", nComp); )
    
	
	while (nComp) {
		fim = 0;

		// Leitura de uma competicao
		//DEBUG ( printf ("Leitura de competicao\n"); )
		while (!fim && fgets (linha, 20, stdin)){
			sscanf (linha, "%d %d %d %c", &cmp, &prb, &tmp, &msg);
			//DEBUG ( printf ("C = %d, P = %d, T = %d, M = %c\n", cmp, prb, tmp, msg); )
			rank[cmp-1][9] = cmp;
			if (msg == 'C'){	
				if (rank[cmp - 1][prb - 1] != 1){
					rank[cmp - 1][10] += 1;
					rank[cmp - 1][11] += tmp + (-20 * rank[cmp - 1][prb - 1]); 
					rank[cmp - 1][prb - 1] = 1;
				}
				
			}else if (msg == 'I'){
				rank[cmp - 1][prb - 1] -= 1; 
			}
			if(jogadores[cmp-1] == 0)
				jogadores[cmp -1] = 1;

			if (linha[0] == 10 || linha[0] == 13)//asci \n \r
				fim = 1;
		}

		int n =contaJogadores(jogadores); //contar jogadores
		quick(rank, 0, 99); //ordenar por acertos
		imprime(rank, n);
		
		nComp--;
		if(nComp != 0){ // zera o rank
			for(int i=0; i < 100; i++) {
				jogadores[i] = 0;
				for(int j = 0; j < 12; j++) {
					rank[i][j] = 0;
				}
			}
		}
	}
    
	return 0;
	
}